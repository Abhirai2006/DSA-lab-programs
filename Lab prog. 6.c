/******************************************
6.  Design, Develop and Implement a menu driven Program in C for the
    following operations on Circular QUEUE of Characters (Array Implementation
    of Queue with maximum size MAX):
    a. Insert an Element on to Circular QUEUE
    b. Delete an Element from Circular QUEUE
    c. Demonstrate Overflow and Underflow situations on Circular QUEUE
    d. Display the status of Circular QUEUE
    e. Exit. Support the program with appropriate functions for each of
       the above operations.
*******************************************/

#include<stdio.h>
#include<conio.h>
#define N 5
char queue[N];
int f=-1;
int r=-1;
void enqueue();
void dequeue();
void display();
void main()
{
    int choice;
    while(1)
    {
        printf("*********************************\n");
        printf("Circular Queue Operations\n");
        printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("**********************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf(" Invalid Choice\n");
        }
    }
}
void enqueue()
{
    char item;
    printf("Enter element to be inserted: ");
    scanf(" %c",&item);
    if(f==-1 &&r==-1)
    {
        f=r=0;
        queue[r]=item;
    }
    else if((r+1)%N==f)
    {
        printf("Queueu is Full\n");
    }
    else
    {
        r=(r+1)%N;
        queue[r]=item;
    }
}
void dequeue()
{
    int item;
    if(f==-1 &&r==-1)
    {
        printf("Queueu is Empty\n");
    }
    else if(f==r)
    {
        item=queue[f];
        printf("Deleted element is %c\n",queue[f]);
        f=r=-1;
    }
    else
    {
        printf("Deleted element is %c\n",queue[f]);
        f=(f+1)%N;
    }
}
void display()
{
    int i;
    if(f==-1 &&r==-1)
    {
        printf("Queueu is empty, there is nothing to display\n");
    }
    else
    {
        printf("Elements of the queue are: ");
        for(i=f; i!=r; i=(i+1)%N)
        {
            printf("%c ",queue[i] );
        }
        printf("%c\n",queue[r]);
    }
}

