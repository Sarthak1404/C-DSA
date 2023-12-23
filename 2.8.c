// deque
#include <stdio.h>    
#define MAX 50
int deque[MAX];    
int f = -1, r = -1;    
//  insert_front function will insert the value from the front    
void insert_front(int x)    
{    
    if((f==0 && r==MAX-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        f=r=0;    
        deque[f]=x;    
    }    
    else if(f==0)    
    {    
        f=MAX-1;    
        deque[f]=x;    
    }    
    else    
    {    
        f=f-1;    
        deque[f]=x;    
    }    
}    
    
// insert_rear function will insert the value from the rear    
void insert_rear(int x)    
{    
    if((f==0 && r==MAX-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else if(r==MAX-1)    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else    
    {    
        r++;    
        deque[r]=x;    
    }    
    
}    
    
// display function prints all the value of deque.    
void display()    
{    
    int i=f;    
    printf("\nElements in a deque are: ");    
        
    while(i!=r)    
    {    
        printf("%d ",deque[i]);    
        i=(i+1)%MAX;    
    }    
     printf("%d",deque[r]);    
}    
    
// getfront function retrieves the first value of the deque.    
void getfront()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else    
    {    
        printf("\nThe value of the element at front is: %d", deque[f]);    
    }    
        
}    
    
// getrear function retrieves the last value of the deque.    
void getrear()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else    
    {    
        printf("\nThe value of the element at rear is %d", deque[r]);    
    }    
        
}    
    
// delete_front() function deletes the element from the front    
void delete_front()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d", deque[f]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(f==(MAX-1))    
     {    
         printf("\nThe deleted element is %d", deque[f]);    
         f=0;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", deque[f]);    
          f=f+1;    
     }    
}    
    
// delete_rear() function deletes the element from the rear    
void delete_rear()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d", deque[r]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(r==0)    
     {    
         printf("\nThe deleted element is %d", deque[r]);    
         r=MAX-1;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", deque[r]);    
          r=r-1;    
     }    
}    
    
void main()    
{   
    int ch,n;
    char ch1;

    do
    {
        printf("Select a choice");
        printf("1. Insert first");
        printf("2. Insert last");
        printf("3. Delete first");
        printf("4. Delete last");
        printf("5. Display");
        printf("6. Get front");
        printf("7. Get last");
        scanf("%d",&ch);
        switch(ch)
        {   
            case 1: printf("Enter the element to be inserted ");
                    scanf("%d",&n);
                    insert_front(n);
                    break;
            case 2: printf("Enter the element to be inserted ");
                    scanf("%d",&n);
                    insert_rear(n);
                    break;       
            case 3: delete_front();
                    break;
            case 4: delete_rear();
                    break;
            case 5: display();  // Calling the display function to retrieve the values of deque 
                    break;
                    
            case 6: getfront();  // Retrieve the value at front-end  
                    break;
            case 7: getrear();  // Retrieve the value at rear-end   
                    break;       
        }
        printf("Do you wish to continue");
        scanf("%c",&ch1);     
    } while (ch1=='Y'||ch1=='y');
          
}     