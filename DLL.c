/*Program to implement DOUBLY LINKED LIST 
153_mandar maruti jondhale
29.12.2021*/

#include<stdio.h>
#include<stdlib.h>

/*Declarations of functions*/
int INSERT();
int DELETE();
int INSERTST();
int DISPLAY();
int DIS1();
int DIS2();
int INSERTEND();
int INSERTBEFOREDATA();
int INSERTAFTERDATA();
int INSERTATLOC();
int DELETEATST();
int DELETEATEND();
int DELETEATLOC();
int DELETEBYDATA();
int SEARCH();

/*Declaring structure for a node*/
struct student 
{
	int roll_no;
	char name[15];
	float per;
	struct student *pre,*nxt;
}*st,*end;

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
				
			case 6:DIS1();
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
			
			case 5:DIS1();
				break;
				
			case 6:return 0;
				
			default:printf("Entered choice is wrong\n");
		}
	}
}

int DISPLAY()
{
	int ch;
	while(1)
	{
		printf("\n1.START to END DISPLAY\n2.END to START DISPLAY\n3.EXIT\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:DIS1();
				break;
				
			case 2:DIS2();
				break;
				
			case 3:return 0;
			
			default:printf("Entered choice is wrong\n");
		}
	}
}

/*inserting new node at start*/
			
int INSERTST()
{
	struct student *new;
	new=(struct student*)malloc(sizeof(struct student)); /*Dynamic allocation*/
	
	if(new==NULL)
	{
		printf("overflow\n");
		return 0;
	}
	printf("Enter the roll no,name and percentage of student \n");
	scanf("%d",&new->roll_no);
	scanf("%s",new->name);
	scanf("%f",&new->per);
	
	if(st==NULL) /*List is empty*/
	{
		st=new;
		st->nxt=NULL;
		st->pre=NULL;
		end=new;		
	}
	else /*List is not empty*/
	{
		st->pre=new;
		new->nxt=st;
		st=new;
		new->pre=NULL;
	}
}

/*inserting new node at the end */

int INSERTEND()
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
	
	if(st==NULL) /*List is empty*/
	{
		st=new;
		st->nxt=NULL;
		st->pre=NULL;
		end=new;		
	}
	else /*Now not need to traverse till end becuase we have end pointer containing address of last node */
	{
		end->nxt=new;
		new->pre=end;
		new->nxt=NULL;
		end=new;
	}
}

/*inserting new node before a specific data */

int INSERTBEFOREDATA()
{
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int ITEM;
	printf("Enter the roll no before which to insert:\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM) /*data is at first node*/
	{
		INSERTST();
		return 0;
	}
	
	struct student *temp;
	temp=st;
	while(temp->roll_no!=ITEM && temp->nxt!=NULL) /*traverse till data not found*/
	temp=temp->nxt;
	
	if(temp->roll_no==ITEM) /*Data found then condition will be true*/
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student)); /*Dynamic allocation*/
		
		if(new==NULL)
		{
			printf("overflow\n");
			return 0;
		}
				
		printf("Enter the roll no,name and percentage of student \n");
		scanf("%d",&new->roll_no);
		scanf("%s",new->name);
		scanf("%f",&new->per);
		
		/*Creating connection between new node and previous and next node*/
		new->pre=temp->pre;
		new->nxt=temp;
		temp->pre=new;
		new->pre->nxt=new;
	}
	else
	printf("Roll no is not found\n");
}

/*inserting node after a specific data*/

int INSERTAFTERDATA()
{
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int ITEM;
	printf("Enter the roll no before which to insert:\n");
	scanf("%d",&ITEM);
	
	if(end->roll_no==ITEM)
	/*Data found at last node then insert at end function called.*/
	{
		INSERTEND();
		return 0;
	}
	
	struct student *temp;
	temp=st;
	while(temp->roll_no!=ITEM && temp->nxt!=NULL) /*Run till item not found*/
	temp=temp->nxt;
	
	if(temp->roll_no==ITEM)
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student)); /* creation of new node i.e. dynamic allocation*/
		
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
		new->pre=temp;
		temp->nxt=new;
		new->nxt->pre=new;
	}
	else
	{
		printf("Roll no is not found\n");
	}
}	

/*inserting node at a specific location*/

int INSERTATLOC()
{
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int LOC,count;
	printf("Enter the location wheres to insert\n");
	scanf("%d",&LOC);	
	
	if(LOC==1) /*If a location is at 1 then insert at start called.*/
	{	
		INSERTST();
		return 0;
	}
	struct student *temp;
	count=1;
	temp=st;
	while(LOC!=count && temp->nxt!=NULL)
	{
		temp=temp->nxt;
		count++;
	}
	if(count+1==LOC) /*if total nodes are 9 and want to add node at location 10 then this condition will true.*/
	{
		INSERTEND();
		return(0);
	}
	if(count==LOC) /*Location found*/
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student)); /*dynamic allocation */
		
		if(new==NULL)
		{
			printf("overflow\n");
			return 0;
		}
		printf("Enter the roll no,name and percentage of student \n");
		scanf("%d",&new->roll_no);
		scanf("%s",new->name);
		scanf("%f",&new->per);
		
		temp->pre->nxt=new;
		new->nxt=temp;
		new->pre=temp->pre;
		temp->pre=new;
		
	}
	else
	{
		printf("location not found\n");
	}		
}

/*Deleting node at start*/

int DELETEATST()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;	
	}		
	printf("Deleted DATA is :\n%d\n%s\n%f\n",st->roll_no,st->name,st->per);
	if(st==end) /*List have only one node*/
	{
		temp=st;
		st=NULL;
		end=NULL;
		free(temp);
	}
	else /*Multiple nodes*/
	{
		temp=st;
		st=st->nxt;
		st->pre=NULL;
		free(temp);
	}
}

/*Deleting node at end*/

int DELETEATEND()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;	
	}	
	
	if(st==end) /*List have only one node*/
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",st->roll_no,st->name,st->per);
		temp=st;
		st=NULL;
		end=NULL;
		free(temp);
	}	
	else /*no need to traverse till end ,we have end pointer*/
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",end->roll_no,end->name,end->per);
		temp=end;
		end=end->pre;
		end->nxt=NULL;
		free(temp);
	}
}

/*Deleting node by data*/

int DELETEBYDATA()
{
	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}		
	int ITEM;
	printf("Enter the roll_no to delete data of that student:\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM) /*data is found at first location*/
	{
		DELETEATST();
		return 0;
	}
	
	if(end->roll_no==ITEM) /*data found at end location*/
	{
		DELETEATEND();
		return 0;
	}
	
	struct student *temp;
	temp=st;
	while(temp->roll_no!=ITEM && temp->nxt!=NULL) /*traverse from start till data not found.*/
	temp=temp->nxt;
	
	if(temp->roll_no==ITEM) /*Data found.*/
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->roll_no,temp->name,temp->per);
		
		temp->nxt->pre=temp->pre;
		temp->pre->nxt=temp->nxt;
	}
	else
	printf("DATA not found\n");
}

/*Deleting node at a particular location.*/

int DELETEATLOC()
{
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int LOC,count;
	printf("Enter the location:\n");
	scanf("%d",&LOC);
	
	if(LOC==1) /*Location is at start.*/
	{
		DELETEATST();
		return 0;
	}
	
	struct student *temp;
	count=1;
	temp=st;
	while(LOC!=count && temp->nxt!=NULL)
	{
		temp=temp->nxt;
		count++;
	}
	if(count==LOC && temp->nxt!=NULL) /*Location found but in between list*/
	{
		temp->nxt->pre=temp->pre;
		temp->pre->nxt=temp->nxt;
	}
	
	else if(count==LOC && temp->nxt==NULL) /*Location found but at end*/
	DELETEATEND();
	
	else
	printf("location not found\n");		
}

/*Displaying list from start to end*/

int DIS1()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		temp=st;
		printf("LIST is :\n\n");
		while(temp!=NULL)
		{
			printf("%d\n%s\n%f\n\n",temp->roll_no,temp->name,temp->per);
			temp=temp->nxt;
		}
	}
}

/*Displaying list from end to start*/ 

int DIS2()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		temp=end;
		printf("LIST is :\n\n");
		while(temp!=NULL)
		{
			printf("%d\n%s\n%f\n\n",temp->roll_no,temp->name,temp->per);
			temp=temp->pre;
		}	
	}
}

//SEARCHING

int SEARCH()
{
	struct student *temp;
	int ITEM,count=1,LOC=1;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter the roll no to search\n");
		scanf("%d",&ITEM);
		{
			temp=st;
			while(temp->roll_no!=ITEM && temp->nxt!=NULL)
			{
				
				temp=temp->nxt;
				count++;
				LOC=count;
			}
			if(temp->roll_no==ITEM)
			{
				printf("ROLL NO is found at LOCATION:%d",LOC);
			}
			else
			{
				printf("roll no not found");
			}
		}
	} 
}	

