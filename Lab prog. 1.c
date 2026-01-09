/**
1. Design, Develop and Implement a menu driven Program in C for the
following array operations:
a. Creating an array of N Integer Elements
b. Display of array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position (POS)
e. Exit. Support the program with functions for each of the above
operations.
**/

#include <stdio.h>
#define N 100

int a[N], n, i, pos, num;

void create();
void display();
void insert();
void deleteElement();

int main()
{
    int ch;
    while (1)
    {
        printf("***************************************");
        printf("\n 1. Create an array ");
        printf("\n 2. Display an array ");
        printf("\n 3. Insert an element into an array ");
        printf("\n 4. Delete an element ");
        printf("\n 5. Exit ");
        printf("\n**************************************");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            exit(0);
        default:
            printf(" Invalid option, please try again.\n");
            break;
        }
    }
}

void create()
{
    printf(" Enter the size of the array: ");
    scanf("%d", &n);
    printf(" Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display()
{
    printf(" Array elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert()
{
    if(n == N)
    {
        printf("Array is full.\n");
        return;
    }

    printf(" Enter the number to be inserted: ");
    scanf("%d", &num);

    printf(" Enter the position to insert the element (1-based index): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1)
    {
        printf("Insertion is not allowed.\n");
        return;
    }

    for (i = n - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    n++;
}

void deleteElement()
{
    if(n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    int item;
    printf(" Enter the position of the element to delete (1-based index): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid Position.\n");
        return;
    }

    item = a[pos - 1];

    for (i = pos - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    printf(" Deleted element is: %d\n", item);
}

