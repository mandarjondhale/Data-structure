/*program to impliment singly circular linked list 
153_mandar maruti jondhale 
on 09.01.2022*/

#include<stdio.h>
#include<stdlib.h>

int INSERT();
int DELETE();
int INSERTST();
int DISPLAY();
int INSERTEND();
int INSERTBEFOREDATA();
int INSERTAFTERDATA();
int INSERTATLOC();
int DELETEATST();
int DELETEATEND();
int DELETEATLOC();
int DELETEBYDATA();
int SEARCH();

struct student
{
	int roll_no;
	char name[15];
	float per;
	struct student *nxt;
}*st;

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.SEARCHING\n5.EXIT\n\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:INSERT();
				break;
				
			case 2:DELETE();
				break;	
				
			case 3:DISPLAY();
				break;
				
			case 4:SEARCH();
				break;
								
			case 5:return 0;	
				
			default :printf("Entered choice is wrong\n");
		}
	}
}

int INSERT()
{
	int ch;
	while(1)
	{
	printf("\n1.INSERT at START\n2.INSERT at END\n3.INSERT before DATA\n4.INSERT after DATA\n5.INSERT at LOCATION\n6.DISPLAY\n7.EXIT\n\n");
	printf("Enter the choice:\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:INSERTST();
				break;
				
			case 2:INSERTEND();
				break;
				
			case 3:INSERTBEFOREDATA();
				break;									
															
			case 4:INSERTAFTERDATA();
				break;	
				
			case 5:INSERTATLOC();
				break;
				
			case 6:DISPLAY();
				break;											
											
			case 7:return 0;
			
			default :printf("Entered choice is wrong\n");	
		}
	}											
}															
																
int DELETE()
{
	int ch;
	while(1)
	{
		printf("\n1.DELETE at START\n2.DELETE at END\n3.DELETE at LOCATION\n4.DELETE by DATA\n5.DISPLAY\n6.EXIT\n\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:DELETEATST();
				break;
				
			case 2:DELETEATEND();
				break;
				
			case 3:DELETEATLOC();
				break;
				
			case 4:DELETEBYDATA();
				break;
			
			case 5:DISPLAY();
				break;
				
			case 6:return 0;
				
			default:printf("Entered choice is wrong\n");
		}
	}
}

//inserting node at start 

int INSERTST()
{
	struct student *temp,*new;
	new=(struct student*)malloc(sizeof(struct student));
	
	if(new==NULL)
	{
		printf("overflow\n");
		return 0;
	}
	printf("Enter the roll no,name and percentage of student \n");
	scanf("%d",&new->roll_no);
	scanf("%s",new->name);
	scanf("%f",&new->per);
	
	if(st==NULL)
	{
		st=new;
		st->nxt=st;
	}
	else
	{
		temp=st;
		while(temp->nxt!=st)
		temp=temp->nxt;
		
		new->nxt=st;
		st=new;
		temp->nxt=st;
	}
}

//insrting node at end 

int INSERTEND()
{
	struct student *new;
	struct student *temp;
	new=(struct student*)malloc(sizeof(struct student));
	
	if(new==NULL)
	{
		printf("overflow\n");
		return 0;
	}
	
	printf("Enter the roll no,name and percentage of student \n");
	scanf("%d",&new->roll_no);
	scanf("%s",new->name);
	scanf("%f",&new->per);
	new->nxt=NULL;
	
	if(st==NULL)
	{
		st=new;
		st->nxt=st;
	}		
	else
	{
		temp=st;
		while(temp->nxt!=st)
		{
			temp=temp->nxt;
		}
		temp->nxt=new;
		new->nxt=st;
	}
}	
		
//inserting node before data

int INSERTBEFOREDATA()
{
	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	struct student *temp;
	
	int ITEM;
	printf("Enter the roll no before which to insert\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM)
	{
		INSERTST();
		return 0;
	}
	temp=st;
	while(temp->nxt->roll_no!=ITEM && temp->nxt->nxt!=st)
	temp=temp->nxt;
	
	if(temp->nxt->roll_no==ITEM)
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student));
		
		if(new==NULL)
		{
			printf("overflow\n");
			return 0;
		}
				
		printf("Enter the roll no,name and percentage of student \n");
		scanf("%d",&new->roll_no);
		scanf("%s",new->name);
		scanf("%f",&new->per);		
		
		new->nxt=temp->nxt;
		temp->nxt=new;
	}
	
	else
	printf("Roll no not found\n");
}
		
//inserting node after specific data 		
		
int INSERTAFTERDATA()
{
	
	struct student *temp;
	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
		
	int ITEM;
	printf("Enter the roll no after which to insert\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM && st->nxt==st)
	{
		INSERTEND();
		return 0;
	}
	
	struct student *new;
	new=(struct student*)malloc(sizeof(struct student));
	
	printf("Enter the roll no,name and percentage of student \n");
	scanf("%d",&new->roll_no);
	scanf("%s",new->name);
	scanf("%f",&new->per);
			
	if(st->roll_no==ITEM && st->nxt!=st)
	{
		new->nxt=st->nxt;
		st->nxt=new;
	}	
	else
	{
		temp=st;
		while(temp->nxt->roll_no!=ITEM && temp->nxt->nxt!=st)
		temp=temp->nxt;
		
		if(temp->nxt->roll_no==ITEM && temp->nxt->nxt==st)
		{
			temp=temp->nxt;
			temp->nxt=new;
			new->nxt=st;
		}
		else if(temp->nxt->roll_no==ITEM && temp->nxt->nxt!=st)
		{
			temp=temp->nxt;
			new->nxt=temp->nxt;
			temp->nxt=new;
		}
	}
}
		
//inserting node at specific location 		
		
int INSERTATLOC()
{
	struct student *temp;
	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int LOC,count;
	printf("Enter the location wheres to insert\n");
	scanf("%d",&LOC);	
	
	if(LOC==1)
	{	
		INSERTST();
		return 0;
	}
	count=1;
	temp=st;
	while(LOC-1!=count && temp->nxt->nxt!=st)
	{
		temp=temp->nxt;
		count++;
	}
	if(count==LOC-1)
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student));
		
		if(new==NULL)
		{
			printf("overflow\n");
			return 0;
		}
		printf("Enter the roll no,name and percentage of student \n");
		scanf("%d",&new->roll_no);
		scanf("%s",new->name);
		scanf("%f",&new->per);		
		
		new->nxt=temp->nxt;
		temp->nxt=new;
	}
	else
	printf("LOCATION is not found\n");
}
		
//deleting data at start

int DELETEATST()
{
	struct student *t,*temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	printf("Deleted DATA is :\n%d\n%s\n%f\n",st->roll_no,st->name,st->per);
	
	if(st->nxt==st)
	{
		t=st;
		st=NULL;
		free(t);
	}
	else
	{
		temp=st;
		while(temp->nxt!=st)
		temp=temp->nxt;
		
		t=st;
		st=st->nxt;
		temp->nxt=st;
		free(t);
	}
}

//deleting data at end 

int DELETEATEND()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}		
	if(st->nxt==st)
	{
		DELETEATST();
		return 0;
	}
	
	temp=st;
	while(temp->nxt->nxt!=st)
	temp=temp->nxt;
	
	printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->nxt->roll_no,temp->nxt->name,temp->nxt->per);
	temp->nxt=st;
}

//deleting data by location

int DELETEATLOC()
{
	struct student *temp; 
	int LOC,count;	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	printf("Enter the location:\n");
	scanf("%d",&LOC);
	if(LOC==1)
	{
		DELETEATST();
		return 0;
	}
	count=1;
	temp=st;
	while(LOC-1!=count && temp->nxt->nxt!=st)
	{
		
		temp=temp->nxt;
		count++;
	}
	if(count==LOC-1)
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->nxt->roll_no,temp->nxt->name,temp->nxt->per);
	
		temp->nxt=temp->nxt->nxt;		
	}
	
	else
	printf("LOCATION not found\n");
	
}

//deleting a specific data

int DELETEBYDATA()
{
	struct student *temp; 
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}		
	int ITEM;
	printf("Enter the roll_no to delete data of that student:\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM)
	{
		DELETEATST();
		return 0;
	}
	temp=st;
	while(temp->nxt->roll_no!=ITEM && temp->nxt->nxt!=st)
	temp=temp->nxt;
	
	if(temp->nxt->roll_no==ITEM)
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->nxt->roll_no,temp->nxt->name,temp->nxt->per);
		temp->nxt=temp->nxt->nxt;
	}
	
	else
	printf("data not found\n");
}

//displaying data 

int DISPLAY()
{
	
	struct student *temp;
	
	if(st==NULL)
	printf("Linked list is empty\n");
	
	else
	{
		temp=st;
		printf("LIST is :\n\n");
		while(temp->nxt!=st)
		{
			printf("%d\n%s\n%f\n\n",temp->roll_no,temp->name,temp->per);
			temp=temp->nxt;
		}
		printf("%d\n%s\n%f\n\n",temp->roll_no,temp->name,temp->per);
		
	}
	
}
/*FOR SEARCHING THE DATA IN LINKED LIST*/

int SEARCH()
{
	struct student *temp;
	int ITEM,count=1,LOC=1;
	if(st==NULL)
	printf("Linked list is empty\n");
	
	else
	{
		printf("Enter the roll no to search\n");
		scanf("%d",&ITEM);
		{
			temp=st;
			while(temp->roll_no!=ITEM && temp->nxt!=st)
			{
				temp=temp->nxt;
				count++;
				LOC=count;
			}
			
			if(temp->roll_no==ITEM)
			printf("ROLL NO is found at LOCATION:%d\n",LOC);
			
			else
			printf("roll no not found\n");
		}
	} 
}	
