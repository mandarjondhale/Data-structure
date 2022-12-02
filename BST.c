/*program to implement binary serach tree 
153_mandar jondhale
31/01/2022*/

#include<stdio.h>
#include<stdlib.h>

/*Declarations of functions*/
int INSERT();
int DISPLAY();
int INORDER();
int PREORDER();
int POSTORDER();

/*Declaration of struct node pointer type function*/
struct node*DELETE(struct node*,int);

/*Declaration of structure for node in tree*/
struct node
{
	int data;
	struct node *left,*right;
}*root;

int data;
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.INSERTION\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:INSERT();
				break;
				
			case 2: if(root==NULL)
				printf("TREE is empty\n");
				
				else
				{
					printf("Enter the data to delete:\n");
					scanf("%d",&x);
					root=DELETE(root,x);
				}
				break ;
				
			case 3:DISPLAY();
				break;
			
			case 4:return 0;
			
			default:printf("Entered choice is wrong\n");
		}
	}
	
}

/*INSERTION of node in binary search tree.*/
int INSERT()
{
	struct node *new,*temp,*parent;
	new=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the data to insert \n");
	scanf("%d",&new->data);
		
	new->left=new->right=NULL;
	parent=root;	/*giving root value to parent pointer */
	
	if(root==NULL)	/*when tree is empty*/
	root=new;
	
	else
	{
		temp=root;	/*temp pointer ready for traversal.*/
		while(temp)	/*while loop will run untill temp value became null.*/
		{
			parent=temp;/*parent stores the value of temp pointer.*/
			
			if(new->data<temp->data)	/*comparing the data of new node to data of temp pointer.*/			
			temp=temp->left;
			
			else
			temp=temp->right;
			
		}
		if(new->data<parent->data)	/*comparing data of new node to parent node data to connect the link whether right or left pointer.*/
		parent->left=new;
		
		else
		parent->right=new;	
	}
}

int DISPLAY()
{
	if(root==NULL)
	{
		printf("TREE is empty!\n");
		return 0;
	}
	else
	{
		int ch;
		while(1)
		{
			printf("\n1.INORDER\n2.PREORDER\n3.POSTORDER\n4.EXIT\n");
			printf("Enter the choice:\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:INORDER(root);
					break;
					
				case 2:PREORDER(root);
					break;
				
				case 3:POSTORDER(root);
					break;
				
				case 4:return 0;
				
				default:printf("Entered choice is wrong\n");
			}
		}
	}
}
/*pre order displaying method :1)left node 2)root node  3)right node  */
int INORDER(struct node *temp)
{
	if(temp!=NULL)
	{
		INORDER(temp->left);	
		printf("%d\t",temp->data);
		INORDER(temp->right);
	}
}
	
/*pre order displaying method :1)root node 2)left node 3)right node  */

int PREORDER(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		PREORDER(temp->left);
		PREORDER(temp->right);
	}
}
/*postorder displaying method :1)left node 2)right node 3)root node */

int POSTORDER(struct node *temp)
{
	if(temp!=NULL)
	{
		POSTORDER(temp->left);
		POSTORDER(temp->right);
		printf("%d\t",temp->data);
	}		
}

/*for deletion of node in binary search tree*/

struct node *DELETE(struct node *root,int data)
{
	if(root==NULL)
	{
		printf("DATA not found\n");
		return root;
	}
	if(data<root->data)
	root->left=DELETE(root->left,data);  /*traversing th tree by left side */
	
	else if(data>root->data)
	root->right=DELETE(root->right,data);	/*traversing th tree by right side */
	
	/*when data is found at root position.*/
	else 
	{
		printf("Deleted data is:%d\n",root->data);
		
		/*deletion of node having no child node.*/
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		
		/*deletion of node having only one child node.*/
		else if(root->left==NULL)
		{
			struct node *temp;
			temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			struct node *temp;
			temp=root;
			root=root->left;
			free(temp);
		}	
		
		/*deletion of node having 2 children nodes.*/
		else
		{
			struct node *temp,*LEAST();
			temp=LEAST(root->right);	/*calling least function to find least element right subtree of deleting node.*/
			root->data=temp->data;
			root->right=DELETE(root->right,temp->data);
		}
		
	}
	return root;
}

/*Function to find least node in tree.*/
struct node *LEAST(struct node*root)
{
	struct node *temp;
	temp=root;
	
	while(temp->left!=NULL)
	temp=temp->left;
	
	return temp;	
}		
