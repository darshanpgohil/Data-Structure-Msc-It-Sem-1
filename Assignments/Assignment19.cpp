#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* iterative_insert(struct node*,int);
void iterative_display(struct node*);
struct node* iterative_delete(struct node*,int);

int main()
{
    struct node *root = NULL;
    int ch,val;

    cout<<"\n1. Insert \n 2. Display \n 3. Delete \n 4. Exit \n";

    do
    {
        cout<<"\n Enter The Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 : cout<<"\n Enter The Val : ";
                     cin>>val;
                     root = iterative_insert(root,val);
                     break;

            case 2 : iterative_display(root);
                     break;

            case 3 : cout<<"\n Enter The Delete Val : ";
                     cin>>val;
                     root = iterative_delete(root, val);
                     break;

            case 4 : exit(0);
                     break;

            default : cout<<"\n Wrong Choice";
        }
    } while (1);   
}

struct node* iterative_insert(struct node *root,int val)
{
    struct node *newNode,*temp;

    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
        return root;
    }

    temp = root;

    while(1)
    {
        if(val < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }


    return root;
}

void iterative_display(struct node *root)
{
    struct node *stack[100];
    int top = -1;
    struct node *temp;

    if(root == NULL)
    {
        cout<<"\n Tree Is Empty";
        return;
    }

    temp = root;

    while(temp != NULL || top != -1)
    {
        while(temp!=NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];

        cout<<"\n Stack Data : "<<temp->data;

        temp = temp->right;
    }
}

struct node* iterative_delete(struct node *root,int val)
{
    struct node *parent = NULL;
    struct node *temp = root;

    while(temp != NULL && temp->data != val)
    {
        parent = temp;

        if(val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if(temp == NULL)
    {
        cout<<"\n Value Not Found";
        return root;
    }

    if(temp->left != NULL && temp->right != NULL)
    {
        struct node *successorParent = temp;
        struct node *successor = temp->right;

        while(successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        temp->data = successor->data;

        temp = successor;

        parent = successorParent;
    }

    struct node *child;

    if(temp->left != NULL)
    {
        child = temp->left;
    }
    else
    {
        child = temp->right;
    }

    if(parent == NULL)
    {
        delete temp;
        return child;
    }

    if(parent->left == temp)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    delete temp;

    return root;
}