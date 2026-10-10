#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert_bst(struct node*,int); 
void preorder_bst(struct node*);
void inorder_bst(struct node*);
void postorder_bst(struct node*);

int main()
{
    struct node *root = NULL;
    int choice,val;
    
    do{
        cout<<"\n 1. Insert \n 2. Pre-order \n 3. In-order \n 4. Post-order \n 5. Exit";

        cout<<"\n Enter The Ch : ";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"\n Enter The Val : ";
                    cin>>val;
                    root = insert_bst(root,val);
                    break;

            case 2: if( root == NULL )
                    {
                        cout<<"\n Bst Pre-order Is Empty";
                        break;
                    }
                    preorder_bst(root);
                    break;

            case 3: if( root == NULL )
                    {
                        cout<<"\n Bst In-order Is Empty";
                        break;
                    }
                    inorder_bst(root);
                    break;

            case 4: if( root == NULL )
                    {
                        cout<<"\n Bst Post-order Is Empty";
                        break;
                    }
                    postorder_bst(root);
                    break;

            case 5: exit(0);
                    break;

            default: cout<<"\n Wrong Choice !!!!!";
        }
    }while(1);

    return 0;
}

struct node* insert_bst(struct node *t, int val)
{
    struct node *nd;

    if(t == NULL)
    {
        nd = (struct node*)malloc(sizeof(struct node));
        nd->data = val;
        nd->left = NULL;
        nd->right = NULL;

        t = nd;

        return t;
    }

    if(val < t->data)
    {
        t->left = insert_bst(t->left,val);
    }
    else
    {
        t->right = insert_bst(t->right, val);
    }

    return t;
}

void preorder_bst(struct node *t)
{
    if ( t == NULL )
    {
        return;
    }
    
    cout<<"\n Pre Order : "<<t->data;
    preorder_bst(t->left);
    preorder_bst(t->right);
}

void inorder_bst(struct node *t)
{
    if( t == NULL )
    {
        return;
    }

    inorder_bst(t->left);
    cout<<"\n In Order : "<<t->data;
    inorder_bst(t->right);
}

void postorder_bst(struct node *t)
{
    if( t == NULL )
    {
        return;
    }

    postorder_bst(t->left);
    postorder_bst(t->right);
    cout<<"\n Post Order : "<<t->data;
}