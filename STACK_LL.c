/*program to implement stack using Singly linked list
24.12.2021
153_mandar maruti jondhale*/ 

#include<stdio.h>
#include<stdlib.h>

/*Declarations of functions */
int PUSH();
int POP();
int DISPLAY();

/*Declaration of structure */
struct student
{
	int data;
	struct student *link;
}*top;

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:PUSH();
				break;
				
			case 2:POP();
				break;
				
			case 3:DISPLAY();
				break;
				
			case 4:return 0;
			
			default:printf("Entered choice is wrong\n");
		}
	}
}

/*FOR PUSHING DATA IN STACK*/
int PUSH()
{
	struct student *new;
	new=(struct student*)malloc(sizeof(struct student)); /*Dynamic allocation*/
	
	if(new==NULL)
	{
		printf("overflow\n");
		return 0;
	}
	printf("Enter the data:\n");
	scanf("%d",&new->data);
	
	if(top==NULL) /*stack is empty.*/
	{
		top=new;
		top->link=NULL;
	}
	else
	{ 
		/*stack is having elements.*/
		new->link=top;
		top=new;
	}
}

/*FOR DELETION OF DATA IN STACK*/

int POP()
{
	struct student *temp;
	if(top==NULL)
	{
		printf("STACK is empty\n");
		
	}		
	else
	{
		printf("Deleted ITEM is :%d",top->data);
		temp=top;
		top=top->link;
		free(temp); /*deallocation of memory*/
	}
}

/*FOR DISPLAYING DATA IN STACK*/

int DISPLAY()
{
	
	struct student *temp;
	
	if(top==NULL)
	{
		printf("STACK is empty\n");
	}
	else
	{
		temp=top;
		printf("STACK is :\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
		
	}	
}	

