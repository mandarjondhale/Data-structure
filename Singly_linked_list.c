/*Program to implement singly linked list 
mandar_jondhale*/


#include<stdio.h>
#include<stdlib.h>

/*Declarations of functions*/

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
	struct student *link;
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
/*Inserting new node at start*/
	
int INSERTST()
{
	struct student *new;
	new=(struct student*)malloc(sizeof(struct student)); /*Dynamic allocation of memory*/
	
	if(new==NULL) /*If machine's memory is full*/
	{
		printf("overflow\n");
		return 0;
	}
	printf("Enter the roll no,name and percentage of student \n");
	scanf("%d",&new->roll_no);
	scanf("%s",new->name);
	scanf("%f",&new->per);
	
	if(st==NULL) /*i.e. Linked list is empty*/
	{
		st=new;
		st->link=NULL;		
	}
	else
	{  /*already having nodes in it*/
		new->link=st;
		st=new;
	}
}

/*Inserting new node before any particular data */
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
		/*if Item is at start itself then i call insert at start function*/
		INSERTST();
		return 0;
	}
	
	temp=st;
	while(temp->link->roll_no!=ITEM && temp->link->link!=NULL) /*Used double pointer to find element*/
	temp=temp->link; /*runs till element not found*/
	
	if(temp->link->roll_no==ITEM) /*Item found*/
	{
		struct student *new;
		new=(struct student*)malloc(sizeof(struct student)); /*dynamic allocation*/
		
		if(new==NULL)
		{
			printf("overflow\n");
			return 0;
		}
				
		printf("Enter the roll no,name and percentage of student \n");
		scanf("%d",&new->roll_no);
		scanf("%s",new->name);
		scanf("%f",&new->per);
		
		new->link=temp->link; /*connecting new node with next node and previous node.*/
		temp->link=new;
	}
	
	else
	printf("roll no is not found\n");
}

//insertion of node after data

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
	
	if(st->roll_no==ITEM && st->link==NULL) /*list have only one element*/
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
			
	if(st->roll_no==ITEM && st->link!=NULL) /*Item is found at first position*/
	{
		new->link=st->link; /*connecting new node with next node and start node.*/
		st->link=new;	
	}
		
	else
	{
		temp=st;
		while(temp->link->roll_no!=ITEM && temp->link->link!=NULL) /*Used double pointer to find element*/
		temp=temp->link; /*runs till element not found*/
		
		if(temp->link->roll_no==ITEM) /*Item found*/
		{
			if(new==NULL)
			{
				printf("overflow\n");
				return 0;
			}
			
			/*connecting new node with next node and previous node.*/
			temp=temp->link;
			new->link=temp->link;
			temp->link=new;
		}
		else
		printf("roll no is not found\n");
	}
}

/*Inserting new node at the end of list*/	
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
	new->link=NULL; /*Because of new node is going at end ,new node's next pointer is set to be null*/
	
	if(st==NULL) /*List is empty*/
	{
		st=new;
		st->link=NULL;
	}
	else
	{
		temp=st;
		while(temp->link!=NULL) /*traverse till the end */
		temp=temp->link;
		
		/*creating link between new node and last node*/
		temp->link=new;	
	}
}


/*For displaying Data in nodes in linked list*/
int DISPLAY()
{
	
	struct student *temp;
	
	if(st==NULL)
	printf("Linked list is empty\n");
	
	else
	{
		temp=st;
		printf("LIST is :\n\n");
		while(temp!=NULL)
		{
			printf("%d\n%s\n%f\n\n",temp->roll_no,temp->name,temp->per);
			temp=temp->link;
		}	
	}
}	

/*delete a node at start*/

int DELETEATST()
{
	struct student *temp;
	
	if(st==NULL)
	printf("Linked list is empty\n");
				
	else
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",st->roll_no,st->name,st->per);
		temp=st;
		st=st->link;
		free(temp); /*Deallocating memory of node*/
	}
}

/*delete a node at end*/

int DELETEATEND()
{
	struct student *temp;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
			
	if(st->link==NULL) /*only one node is there*/
	{
		DELETEATST();
		return 0;
	}
	
	temp=st;
	
	while(temp->link->link!=NULL) /*traverse till second last node*/
	temp=temp->link;
	
	printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->link->roll_no,temp->link->name,temp->link->per);
	free(temp->link); /*Deallocating memory of node*/
	temp->link=NULL;
}

/*Inserting node at given location*/

int INSERTATLOC()
{
	struct student *temp,*t;
	
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	int LOC,count;
	printf("Enter the location wheres to insert\n");
	scanf("%d",&LOC);	
	
	if(LOC==1) /*given location is 1 then call insert at start*/
	{	
		INSERTST();
		return 0;
	}
	
	count=1;
	temp=st;
	while(LOC!=count && temp->link!=NULL)
	{
		t=temp; /*storing the address in temp in t i.e. in previous one*/
		temp=t->link;
		count++;
	}
	
	if(count==LOC) /*Location found*/
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
		
		t->link=new; /*Creating link between next and previous node*/
		new->link=temp;
	}
	
	else
	printf("LOCATION is not found\n");
}

/*Deleting node at a particular location*/
int DELETEATLOC()
{
	struct student *temp,*t;
	int LOC,count;
		
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	printf("Enter the location:\n");
	scanf("%d",&LOC);
	if(LOC==1) /*Location is at first node then delete at start function called.*/
	{
		DELETEATST();
		return 0;
	}
	
	count=1;
	temp=st;
	while(LOC!=count && temp->link!=NULL) /*when count of nodes is equal to location then loop will terminate*/
	{
		t=temp;
		temp=t->link;
		count++;
	}
	
	if(count==LOC) /*node found*/
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->roll_no,temp->name,temp->per);
		t->link=temp->link;
		free(temp);
	}
	
	else
	printf("LOCATION is not found\n");
		
}

/*Deleting the node by its value or data*/	
int DELETEBYDATA()
{
	struct student *temp,*t;
	if(st==NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
			
	int ITEM;
	printf("Enter the roll_no to delete data of that student:\n");
	scanf("%d",&ITEM);
	
	if(st->roll_no==ITEM) /*Data matches with first node then delete at start function called*/
	{
		DELETEATST();
		return 0;
	}
	
	temp=st;
	while(temp->roll_no!=ITEM && temp->link!=NULL) /*checks till given data matches with node's data*/
	{
		t=temp;
		temp=t->link;
	}
	if(temp->roll_no==ITEM) /*DAta found*/
	{
		printf("Deleted DATA is :\n%d\n%s\n%f\n",temp->roll_no,temp->name,temp->per);
		t->link=temp->link;	/*deleting that node and creating new link between previous and next node*/
	}
	
	else
	printf("Roll no is not found\n");
	
}	

/*For searching any data from linked list*/

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
			while(temp->roll_no!=ITEM && temp->link!=NULL)
			{
				
				temp=temp->link;
				count++;
				LOC=count; /*storing node's position in LOC variable */
			}
			
			if(temp->roll_no==ITEM) /*found*/
			printf("ROLL NO is found at LOCATION:%d",LOC);
			
			else
			printf("roll no not found");
		}
	} 
}	
