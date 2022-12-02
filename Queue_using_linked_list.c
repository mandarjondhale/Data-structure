/*program to implement Queue using Singly linked list
24.12.2021
153_mandar maruti jondhale*/ 

#include<stdio.h>
#include<stdlib.h>

/*Declarations of functions*/
int ENQUEUE();
int DEQUEUE();
int DISPLAY();

/*declaration of structure for element*/
struct student
{
	int data;
	struct student *link;
}*F;

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ENQUEUE();
				break;
				
			case 2:DEQUEUE();
				break;
				
			case 3:DISPLAY();
				break;
				
			case 4:return 0;
			
			default:printf("Entered choice is wrong\n");
		}
	}
}

/*INSERTING DATA IN QUEUE*/

int ENQUEUE()
{
	struct student *new,*temp;
	new=(struct student*)malloc(sizeof(struct student)); /*Dynamic allocation*/
	
	if(new==NULL) /*Memory is full*/
	{
		printf("overflow\n");
		return 0;
	}
	printf("Enter the data:\n");
	scanf("%d",&new->data);

	
	if(F==NULL) /*Queue is empty*/
	{
		F=new;
		F->link=NULL;
	}
	else
	{
		/*Queue is not empty*/
		temp=F;
		while(temp->link!=NULL)
		temp=temp->link;
		
		/*creating link between new element and previous & next element*/
		temp->link=new;
		new->link=NULL;
	}
}

/*DELETING DATA FROM QUEUE*/

int DEQUEUE()
{
	struct student *temp;
	if(F==NULL)
	printf("QUEUE is empty\n");
				
	else
	{
		printf("Deleted ITEM is :%d",F->data);
		temp=F;
		F=F->link;
		free(temp); /*Deallocation of memory*/
	}
}

/*FOR DISPLAYING DATA IN QUEUE*/

int DISPLAY()
{
	struct student *temp;
	
	if(F==NULL)
	printf("QUEUE is empty\n");
	
	else
	{
		temp=F;
		printf("QUEUE is :\n\n");
		while(temp!=NULL) /*Traverse till end*/
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
		
	}	
}	

