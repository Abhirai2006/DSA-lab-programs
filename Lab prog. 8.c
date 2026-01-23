#include<stdio.h>
#include<stdlib.h>

void create_DLL();
void createnode();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display_count();

struct Node
{
    char ssn[20],name[20],dept[20],designation[20];
    unsigned long int phoneno,salary;
    struct Node *next;
    struct Node *prev;
};

struct Node *temp, *head=NULL,*first,*last,*tail;

void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create DLLL\n2.Display DLL\n3.Insert Front\n4.Insert end\n5.Delete front\n6.Delete end\n7.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create_DLL();
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
    printf("\nEnter SSN\n");
    scanf("%s",temp->ssn);
    printf("Enter Name\n");
    scanf("%s",temp->name);
    printf("Enter department\n");
    scanf("%s",temp->dept);
    printf("Enter Phone Number\n");
    scanf("%lu",&temp->phoneno);
    printf("Enter designation\n");
    scanf("%s",temp->designation);
    printf("Enter salary\n");
    scanf("%lu",&temp->salary);
    temp->next=NULL;
    temp->prev=NULL;
}

void create_DLL()
{
    int i,n;
    printf("Enter number of employees ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter detail of %d st employee",i);
        createnode();
        if(head==NULL)
            head=tail=temp;
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }}}

void display_count()
{
    int count=0;
    first=head;
    printf("Employee Detail:\n");
    printf("SSN\t\tName\t\tDepartment\tDesignation\tPhoneNumber\tSalary\n");
    if(head==NULL)
    {
        printf("No employee Information\n Count is 0\n");
    }
    else
    {
        while(first!=NULL)
        {
            count++;
            printf("%s\t\t%s\t\t%s\t\t%s\t\t%lu\t\t%lu\n",first->ssn,first->name,first->dept,
                   first->designation,first->phoneno,first->salary);
            first=first->next;
        }
        printf("Employee count is %d",count);
    }
}

void insert_front()
{
    printf("Enter details of employee\n");
    createnode();
    if(head==NULL)
        head=tail=temp;
    else
    {
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}

void insert_end()
{
    printf("Enter details of employee\n");
    createnode();
    if(head==NULL)
        head=tail=temp;
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void delete_front()
{
    first=head;
    if(head==NULL)
        printf("List is empty\n");
    else if(head==tail)
    {
        printf("Deleted element is %s", head->ssn);
        head=NULL;
        tail=NULL;
    }
    else
    {
        printf("Deleted element is %s", first->ssn);
        head=head->next;
        head->prev=NULL;
        free(first);
    }
}

void delete_end()
{
    if(tail==NULL)
        printf("List is empty");
    else if(tail==head)
    {
        printf("Deleted element is %s", tail->ssn);
        head=NULL;
        tail=NULL;
    }
    else
    {
        printf("Deleted element is %s", tail->ssn);
        last=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(last);
    }
}
