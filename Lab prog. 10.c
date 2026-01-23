#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node* getnode(int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insert(struct node *root, int data)
{
    if(root==NULL)
    {
        root=getnode(data);
        return root;
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void preorder(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int search(struct node* root, int key)
{
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    int choice,data,i,n,key,flag;
    while(1)
    {
        printf("\n*********************************\n");
        printf("Binary Search Tree Operations\n");
        printf(" 1.Create Tree\n 2:Pre-order\n 3.In-order\n 4.Post-order\n 5.Search\n 6.Exit\n");
        printf("**********************************\n");
        printf("Enter your choice ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter number of nodes in Binary Tree\n");
            scanf("%d",&n);
            printf("Enter values to create BST");
            for(i=0; i<n; i++)
            {
                scanf("%d",&data);
                root =insert(root,data);
            }
            break;
        case 2:
            printf(" Preorder Traversal is:\n");
            preorder(root);
            break;
        case 3:
            printf(" Inorder Traversal is:\n");
            inorder(root);
            break;
        case 4:
            printf(" Postorder Traversal is:\n");
            postorder(root);
            break;
        case 5:
            printf(" Enter key element to search in BST :\n");
            scanf("%d",&key);
            flag=search(root,key);
            if(flag)
                printf("key element %d found\n");
            else
                printf("Key not found\n");
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf(" Invalid Choice\n");
        }
    }

    return 0;
}
