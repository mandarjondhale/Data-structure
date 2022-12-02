/*program to implement stack using array 
153_mandar jondhale
25.11.2021*/

#include<stdio.h>
#define n 5  /*declaring size of stack statically.*/

/*Declarations of functions.*/
int PUSH();
int POP();
int DISPLAY();

int stack[n];
int top=-1; /*top of the stack is set to -1.*/
int main()
{
	int ch;
	while(1) /*Infinite loop till user enter exit choice.*/
	{
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\n");
		printf("Enter the choice:\n");
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
					
			default :printf("Entered choice is wrong\n");
		}
	}
}
int PUSH()
{
	if(top==n-1)  /*i.e. when top of the stack is at max of capacity.*/
	printf("stack overflows\n");
	
	else
	{
		top=top+1; /*creating one space for new element.*/
		printf("Enter the element to insert:\n");
		scanf("%d",&stack[top]); 
	}	
}
int POP()
{
	if(top==-1) /*i.e. stack is empty.*/
	printf("stack underflows\n");
		
	else
	{
		printf("deleted element is :\n %d\n",stack[top]);
		top=top-1; 	
	}
}
int DISPLAY()
{
	int i;
	
	if(top==-1) 
	printf("stack is empty\n");
	
	else
	{
		printf("stack is:\n");
		for(i=top;i>=0;i--) /*printing elements from top to bottom.*/
		printf("%d\n",stack[i]);
	}
}
