#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function prototypes
void push();
int pop();
void checkPalindrome();
void displayStatus();
void checkOverflow();
void checkUnderflow();

int main()
{
    int choice, elem;
    while (1)
    {
        printf("------------------------------------------------");
        printf("\nMenu:");
        printf("\n1. Push an element onto the stack");
        printf("\n2. Pop an element from the stack");
        printf("\n3. Check if the stack is a palindrome");
        printf("\n4. Demonstrate overflow / underflow situations");
        printf("\n5. Display the status of the stack");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                elem = pop();
                if (elem != -1)
                    printf("Popped element: %d\n", elem);
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                checkOverflow();
                checkUnderflow();
                break;

            case 5:
                displayStatus();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Push function
void push()
{
    int elem;
    printf("Enter the element to push: ");
    scanf("%d", &elem);

    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push element.\n");
    }
    else
    {
        stack[++top] = elem;
        printf("Element %d pushed onto the stack.\n", elem);
    }
}

// Pop function
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    }
    else
    {
        return stack[top--];  // FIXED pop error
    }
}

// Palindrome check
void checkPalindrome()
{
    if (top == -1){
        printf("Stack is empty, cannot check for palindrome.\n");
        return;
    }

    int flag = 1;
    for (int i = 0; i <= top / 2; i++)
    {
        if (stack[i] != stack[top - i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("The stack is a palindrome.\n");
    else
        printf("The stack is not a palindrome.\n");
}

// Overflow check
void checkOverflow()
{
    if (top == MAX - 1)
        printf("Stack is full! Overflow condition exists.\n");
    else
        printf("Stack is not full. No overflow.\n");
}

// Underflow check
void checkUnderflow()
{
    if (top == -1)
        printf("Stack is empty! Underflow condition exists.\n");
    else
        printf("Stack is not empty. No underflow.\n");
}

// Display stack
void displayStatus()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Current stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\nTop of the stack is at position %d with value %d.\n", top, stack[top]);
    }
}
