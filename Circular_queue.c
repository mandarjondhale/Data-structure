/*program to implement circular QUEUE using array.
153_Mandar Jondhale
01.12.2021*/

#include<stdio.h>
#define n 5 /*Declaring size of queue statically.*/

/*Declarations of functions*/
int ENQUEUE();
int DQUEUE();
int DISPLAY();

int QUEUE[n];
int FRONT=-1; /*front and rear set to be -1 i.e. queue is empty.*/
int REAR=-1;
int main()
{

	int ch;
	while(1) /*Infinite loop till user choose exit.*/
	{
		printf("\n1.ENQUEUE\n2.DQUEUE\n3.DISPLAY\n4.Exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ENQUEUE();
				break;
				
			case 2:DQUEUE();
				break;
				
			case 3:DISPLAY();
				break;
				
			case 4:return 0;
					
			default :printf("Entered choice is wrong\n");
		}
	}
}

int ENQUEUE() /*function for inserting element in queue*/
{
	int ITEM;
	if((FRONT==0&&REAR==n-1)||FRONT==REAR+1) /*there is two conditions for overflow ,first is front is at 0 and rear is at max and second is rear is exactly one step back from front*/
	{
		printf("\nQUEUE Overflows\n");
		return 0;
	}
	printf("Enter the element to insert:\n");
	scanf("%d",&ITEM);
	if(FRONT==-1)  /* indicates that queue is empty*/
	{
		FRONT=0;
		REAR=0;
	}
	
	else if(REAR==n-1) /*rear is at max and there is space from start then set rear is at 0*/
	REAR=0;
	
	else
	REAR=REAR+1; /*creating space for element*/
	
	QUEUE[REAR]=ITEM;
	return 0;
}

int DQUEUE()  /*function for deleting a element in queue*/
{
	int ITEM;
	if(FRONT==-1) /* queue is already empty*/
	{
		printf("\nQUEUE Underflows\n");
		return 0;
	}
	ITEM=QUEUE[FRONT];	
	if(FRONT==REAR) /*This condition occur only when there is only one element is queue.*/
	{
		FRONT=-1;
		REAR=-1;
	}
	
	else if(FRONT==n-1) /*front is at max but there are elements from start so set front as 0.*/
	FRONT=0;
	
	else
	FRONT=FRONT+1; /*deleting elements from start.*/
		
	printf("Deleted element is: %d\n",ITEM);
	return 0;
}

int DISPLAY()
{
	int i;
	if(FRONT==-1)
	printf("\nQUEUE is empty\n");
	
	else
	{
		printf("QUEUE is:\n");
		if(FRONT<=REAR) /*this is the normal flow of elements from front to rear.*/
		{
			for(i=FRONT;i<=REAR;i++)
			printf("%d\t",QUEUE[i]);	
		}
		else 
		{       /*rear is less than front*/
			for(i=FRONT;i<n;i++) 
			printf("%d\t",QUEUE[i]);
			
			for(i=0;i<=REAR;i++)
			printf("%d\t",QUEUE[i]);		
		}		
	}	
}
