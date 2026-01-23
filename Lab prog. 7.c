#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void create_SSL();
void createnode();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display_count();

struct Node
{
    char usn[20],name[20],branch[20];
    char phoneno[20];
    int sem;
    struct Node *next;
};

struct Node *temp, *head=NULL,*first,*last;

void main()
{
    int choice;
    while(1)
    {
        printf("1.Create SSL\n2.Display SSL\n3.Insert Front\n4.Insert end\n5.Delete front\n6.Delete end\n7.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create_SSL();
            break;
        case 2:
            display_count();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_front();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            return;
        default:
            printf("Invalid Choice\n");
        }
    }
}

void createnode()
{
    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter USN");
    scanf("%s",temp->usn);
    printf("Enter Name\n");
    scanf("%s",temp->name);
    printf("Enter branch\n");
    scanf("%s",temp->branch);
    printf("Enter Phone Number\n");
    scanf("%s",temp->phoneno);
    printf("Enter Semester\n");
    scanf("%d",&temp->sem);
    temp->next=NULL;
}

void create_SSL()
{
    int i,n;
    printf("Enter number of students ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter detail of %d st student",i);
        createnode();
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
}

void display_count()
{
    int count=0;
    first=head;
    printf("Students Detail:\n");
    printf("USN\tName\tBranch\tPhoneNumber\tSemester\n");
    if(head==NULL)
    {
        printf("No students Information\n Count is 0\n");
    }
    else
    {
        while(first!=NULL)
        {
            count++;
            printf("%s\t%s\t%s\t%s\t%d\n",first->usn,first->name,first->branch,first->phoneno,first->sem);
            first=first->next;
        }
        printf("Student count is %d",count);
    }
}

void insert_front()
{
    printf("Enter details of student\n");
    createnode();
    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insert_end()
{
    printf("Enter details of student\n");
    createnode();
    last=head;
    if(head==NULL)
        head=temp;
    else
    {
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=temp;
    }
}

void delete_front()
{
    first=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("Deleted element is %s", first->usn);
        head=head->next;
        free(first);
    }
}

void delete_end()
{

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    first=head;
    while(first->next!=NULL)
    {
        last=first;
        first=first->next;
    }
    printf("Deleted element is %s", first->usn);
    if(first==head)
        head=NULL;
    else
        last->next=NULL;
    free(first);
}

