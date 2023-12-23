#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node *next;
  }typedef node;
node *start=NULL;

/*struct list
{
  node *start;
  }typedef list;    */

void insert_first(int);

void insert_last(int);

void delete_first();
void delete_last();
void display();
void  sort();
void search();

void main()
{
   int item,ch;
   char ch1;
//   list *ls;
  // ls->start=NULL;
   do
   {
     
     printf("\n Press 1 to insert data at begining of LL");
     printf("\n Press 2 to insert dta at the end of LL");
     printf("\n Press 3 to delete first node of LL");
     printf("\n Press 4 to delete last node of LL");
     printf("\n Press 5 to sort the list");
     printf("\n Press 6 to search the list");
     printf("\n Press 7 to display LL");
     printf("\n Enter Your Choice (1-7) ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1:printf("Enter the element you want to insert");
	       //fflush(stdin);
	       scanf("%d",&item);
	       insert_first(item);//fun call
	       break;
	case 2:printf("\nEnter the element you want to insert");
	       //fflush(stdin);
	       scanf("%d",&item);
	       insert_last(item);//fun  call
	       break;
	case 3:delete_first();   //fun call
	       break;
	case 4:delete_last();   //fun call
	       break;
	case 5:printf("Sorted list is ");
	       sort();
	       break;
	case 6:
	       search();
	       break;
	case 7:printf("\nElememts of LL");
	       display();
	       break;
		}
 printf("\nDo you wish to continue(y/n)::");
 fflush(stdin);
 scanf("%c",&ch1);
}while(ch1=='Y' || ch1=='y');
}


void insert_first(int item)//fun definition
{
   node *newnode;
   newnode=(node *) malloc(sizeof(node));//memory acquire//newnode is ready
   newnode->data=item;
   if(start==NULL)
   {
      start=newnode;    //first node addition
      newnode->next=NULL;
      }
    else
     {
       newnode->next=start;
       start=newnode;
       }
  }

void insert_last(int item)    //fun defination
{
  node *newnode,*temp;
  temp=start;
  newnode=(node*)malloc(sizeof(node));//newnode is ready
  newnode->data=item;

  if(start==NULL)
  {
    start=newnode;
    newnode->next=NULL;//special case
    }
   else
   {
    while(temp->next!=NULL)   //to reach and hold at the end of ll
    {
      temp=temp->next;
      }

    newnode->next=NULL;
    temp->next=newnode;
    }
  }

void delete_first()
{
  node *temp;
  temp=start;
  if(temp==NULL)
  {
    printf("\n LIst is empty");
    }
  else if(temp->next==NULL)
     {
      printf("\nSeleted element is %d",temp->data);
      start=NULL;
      free(temp);
  }

  else
  {
    printf("\n Deleted element is %d",temp->data);
    start=temp->next;
    free(temp);
    }
  }

void delete_last()
{
 node *temp,*prev;
 temp=start;
 if(temp==NULL)
 {
   printf("\n list is empty");  //No node
   }

 else if(temp->next==NULL) //single node
 {
   printf("\nDeleted item is %d",temp->data);
   temp->data=NULL;
   start=NULL;
   free(temp);
   }
  else
  {
   while(temp->next!=NULL)  //N no's of node
   {
    prev=temp;
    temp=temp->next;
    }
  printf("\nDeleted item is %d",temp->data);
  prev->next=NULL;
  free(temp);
  }
}

void display()
{
  node *temp;
  temp=start;
  if(temp==NULL)
  {
    printf("\n List is empty");
    }
  else
  {
    while(temp!=NULL)
    {
     printf("%5d",temp->data);
     temp=temp->next;
//     if(temp!=NULL)
  //    printf("\nNo elements to display");
    }
  }
}

void sort()
{
  int temp;
  node *p,*q;
  for(p=start;p->next!=NULL;p=p->next)
  {
    for(q=p->next;q!=NULL;q=q->next)
     {
       if(q->data <p->data)
	{
	  temp=q->data;
	  q->data=p->data;
	  p->data=temp;
	  }
	 }
       }
printf("The sorted list is ");
for(p=start;p!=NULL;p=p->next)
  printf("%5d",p->data);
}

void search()
{
  int key,flag=0;
  node *temp;
  printf("\nEnter the search key");
  scanf("%d",&key);
  temp=start;
  if(start==NULL)
    printf("List is empty..NO search can be performed");
  else
  {
    while(temp !=NULL)
    {
      if(temp->data==key)
	 {
	   flag=1;
	   break;
	   }
	temp=temp->next;
    }
  }
if(flag==1)
  printf("%d found ",key);
else
  printf("Key not found");
}





