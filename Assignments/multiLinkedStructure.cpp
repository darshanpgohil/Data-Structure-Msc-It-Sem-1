#include<iostream>
#include<stdlib.h>

using namespace std;

void create();
void display();

struct node
{
    int row,col,data;
    struct node *right,*down;
};

struct node *head = NULL;
struct node *rowStart[20] = {NULL};

int main()
{
    int ch;

    do
    {
        cout<<"\n 1. Insert \n 2. Display \n 3. Exit \n";

        cout<<"\n Enter The Ch : ";
        cin>>ch;

        switch(ch)
        {
            case 1: create();
                    break;

            case 2: display();
                    break;

            case 3: exit(0);
                    break;

            default: cout<<"\n Wrong Choice";
                     break;
        }
    } while (ch!=3);
    
}

void create()
{
    int r,c,value;

    cout<<"\n Enter The Row : ";
    cin>>r;

    cout<<"\n Enter The Column : ";
    cin>>c;

    head=(struct node*)malloc(sizeof(struct node));

    head->row = r;
    head->col = c;
    head->data = 0;
    head->right = NULL;
    head->down = NULL;

    struct node *rowTail[20] = {NULL};
    struct node *colTail[20] = {NULL};

    for(int i=0;i<r;i++)
    {
        rowStart[i] = NULL;

        for(int j=0;j<c;j++)
        {
            cout<<"\n Enter The Val : ";
            cin>>value;

            if(value!=0)
            {
                struct node *newNode = (struct node*)malloc(sizeof(struct node));

                newNode->row = i;
                newNode->col = j;
                newNode->data = value;
                newNode->right = NULL;
                newNode->down = NULL;

                if(rowTail[i] == NULL)
                {
                    rowStart[i] = newNode;
                    rowTail[i] = newNode;
                }
                else
                {
                    rowTail[i]->right = newNode;
                    rowTail[i] = newNode;
                }

                if(colTail[j] == NULL)
                {
                    colTail[j] = newNode;
                }
                else
                {
                    colTail[j]->down = newNode;
                    colTail[j] = newNode;
                }
            }
        }
    }

    cout<<"\n MultiLinkedStructure Created Successfully";
}

void display()
{
    if(head == NULL)
    {
        cout<<"\n First Create Matrix \n";
        return;
    }

    for(int i=0;i<head->row;i++)
    {
        struct node *temp = rowStart[i];
        for(int j=0;j<head->col;j++)
        {
            if(temp != NULL && temp->col == j)
            {
                cout<<temp->data<<"\t";
                temp = temp->right;
            }
            else
            {
                cout<<"0\t";
            }
        }

        cout<<endl;
    }
}