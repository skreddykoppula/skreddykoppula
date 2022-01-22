#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node* create();
struct node* del(struct node*,int);
struct node* insert(struct node*,int);
struct node* succnode(struct node*);
int search(struct node*,int);
void inorder(struct node*);
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root;
int main()
{
    int x,y,ch,key;
    printf("operations of binary search tree are.....\n");
    printf("1.create the root node\n 2.insert\n 3.delete\n 4.inorder\n 5.search\n 6.exit\n");
    while(1)
    {
        printf("enter your choice to to perform\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("consruct a root node\n");
                   root=create();break;
            case 2:printf("enter the element to be inserted into the tree\n");
                   scanf("%d",&key);
                   insert(root,key);
                   break;
            case 3:printf("enter the element to be deleted from the tree\n");
                   scanf("%d",&key);
                   del(root,key);break;
            case 4:printf("the inorder traversal is\n");
                   inorder(root);
                   break;
            case 5:printf("enter the element to search\n");
                   scanf("%d",&x);
                   y=search(root,x);
                   if(x==y)
                   {
                       printf("the search elemement is present\n");break;
                   }
            case 6:exit(1);
        }
    }
}

struct node* create()
{
    struct node *newnode;
    int x;
    printf("enter the data\n");
    scanf("%d",&x);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return(newnode);
}

struct node* insert(struct node *root,int key)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    if(root==NULL)
    {
        return(newnode);
    }
    if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    if(key>root->data)
    {
        root->right=insert(root->right,key);
    }
    return(root);
}

struct node* del(struct node *root,int key)
{
    struct node *temp;
    if(root==NULL)
    {
        return(root);
    }
    if(key<root->data)
    {
        root->left=del(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=del(root->right,key);
    }
    else
    {
        //node with one child
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return(temp);
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return(temp);
        }
        //node with 2 child
        temp=succnode(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
    r eturn(root);
}

struct node* succnode(struct node *root)
{
    struct node *current;
    current=root;
    while(current->left==NULL)
    {
        current=current->left;
    }
    return(current);
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%3d\n",root->data);
        inorder(root->right);
    }
}

int search(struct node *root,int x)
{
    if(root->data==x)
    {
        return(root->data);
    }
    if(x<root->data)
    {
        return(search(root->left,x));
    }
    if(x>root->data)
    {
        return(search(root->right,x));
    }
}

