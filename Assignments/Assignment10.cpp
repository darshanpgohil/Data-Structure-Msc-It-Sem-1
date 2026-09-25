#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int info;
    struct node *next;
};

void circular_insert(struct node *,struct node **,int);
void circular_delete(struct node **,int);
void circular_modify(struct node **,int);
void circular_display(struct node **);

int main()
{
    struct node *nd,*head = NULL;
    int val,ch;

    do
    {
        cout<<"\n 1. Insert \n 2. Delete \n 3. Modify \n 4. Display \n 5. Exit";

        cout<<"\n Enter Your Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1: 
                    cout<<"\n Enter The Value : ";
                    cin>>val;
                    circular_insert(nd,&head,val);
                    break;

            case 2: cout<<"\n Enter The Value : ";
                    cin>>val;
                    circular_delete(&head,val);
                    break;

            case 3: cout<<"\n Enter The Val : ";
                    cin>>val;
                    circular_modify(&head,val);
                    break;

            case 4: circular_display(&head);
                    break;

            case 5: exit(0);
                    break;

            default: cout<<"\n Wrong Choice";
                     break;
        }
    } while (1);   
}

void circular_insert(struct node *nd,struct node **head,int val)
{
    struct node *t1;

    nd = (struct node*)malloc(sizeof(struct node));
    nd->info = val;
    
    if(*head == NULL)
    {
        *head = nd;
        nd->next = *head;
    }
    else if((*head)->info > val)
    {
        t1 = *head;

        while(t1->next != *head)
        {
            t1 = t1->next;
        }

        nd->next = *head;
        t1->next = nd;
        *head = nd;
    }
    else
    {
        t1 = *head;

        while(t1->next != *head && t1->next->info < val)
        {
            t1 = t1->next;
        }

        nd->next = t1->next;
        t1->next = nd;
    }
}

void circular_delete(struct node **head,int val)
{
    struct node *t1,*t2;

    if(*head == NULL)
    {
        cout<<"\n Circular Linked List Is Empty";
        return;
    }
    
    if((*head)->info == val)
    {
        if((*head)->next == *head)
        {
            free(*head);
            *head = NULL;
            return;
        }   

        t1 = *head;

        while(t1->next != *head)
        {
            t1 = t1->next;
        }

        t2 = *head;
        *head = (*head)->next;
        t1->next = *head;

        free(t2);
        return;
    }

    t1 = *head;

    while(t1->next != *head && t1->next->info != val)
    {
        t1 = t1->next;
    }

    if(t1->next == *head)
    {
        cout<<"\n Value Not Found";
        return;
    }

    t2 = t1->next;
    t1->next = t2->next;

    free(t2);
}

void circular_modify(struct node **head,int val)
{
    struct node *tmp;
    int nVal;

    if(*head == NULL)
    {
        cout<<"\n Linked List Is Empty";
        return;
    }
    
    tmp = *head;

    do
    {
        if(tmp->info == val)
        {
            cout<<"Enter The New Value : ";
            cin>>nVal;

            tmp->info = nVal;

            cout<<"\n Value Modify Success";

            return;
        }

        tmp = tmp->next;
    }while(tmp != *head);

    cout<<"\n Value Not Found";
}

void circular_display(struct node **head)
{
    struct node *temp;

    temp = *head;

    do
    {
        cout<<"\n"<<temp->info;
        temp = temp->next;
    }while(temp != *head);
}