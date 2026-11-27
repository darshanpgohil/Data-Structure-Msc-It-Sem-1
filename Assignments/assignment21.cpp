#include<iostream>
#define Max 20

using namespace std;

struct node
{
    int row,col,data;
    struct node *right,*down;
};

struct matrix
{
    int rows,cols;
    struct node *rowHead[Max];
    struct node *colHead[Max];
};

void initialize(struct matrix &);
void insert(struct matrix,int r,int c,int val,struct node,struct node);
void create(struct matrix &);
void matrix_addition(struct matrix &,struct matrix &);
void matrix_multiplication(struct matrix &,struct matrix &);
void display(struct matrix &);

int main()
{
    int ch;
    struct matrix a,b;

    initialize(a);
    initialize(b);

    do
    {
        cout<<"\n 1.Create Matrix \n 2. Addition Of Matrix \n 3. Multiplication Of matrix \n 4. Display Matrix \n 5. Exit \n";

        cout<<"\n Enter The Ch : ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: cout<<"\n Create Mtrix A : \n";
                    create(a);
                    cout<<"\n Create Mtrix B : \n";
                    create(b);

            case 2: matrix_addition(a,b);
                    break;

            case 3: matrix_multiplication(a,b);
                    break;

            case 4: cout<<"\n Display Matrix A : \n";
                    display(a);
                    cout<<"\n Display Matrix B : \n";
                    display(b);
                    break;

            case 5: exit(0);
                    break;

            default: cout<<"\n Wrong Choice";
                     break;
        }
    } while (ch!=5);
    
}

void initialize(struct matrix &m)
{
    m.rows = 0;
    m.cols = 0;

    for(int i=0;i<Max;i++)
    {
        m.rowHead[i] = NULL;
        m.colHead[i] = NULL;
    }
}

void insert(struct matrix &m,int r,int c,int val,struct node *rowTail[],struct node *colTail[])
{
        if(val == 0)
        {
            return;
        }

        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->row = r;
        newNode->col = c;
        newNode->data = val;
        newNode->right = NULL;
        newNode->down = NULL;
    
        if(rowTail[r] == NULL)
        {
            m.rowHead[r] = newNode;
            rowTail[r] = newNode; 
        }
        else
        {
            rowTail[r]->right = newNode;
            rowTail[r] = newNode;
        }

        if(colTail[c] == NULL)
        {
            m.colHead[c] = newNode;
            colTail[c] = newNode;
        }
        else
        {
            colTail[c]->down = newNode;
            colTail[c] = newNode;
        }
}

void create(struct matrix &m)
{
    int val;

    cout<<"\n Enter The Row : ";
    cin>>m.rows;

    cout<<"\n Enter The Col : ";
    cin>>m.cols;

    if(m.rows <= 0 || m.rows > Max || m.cols <=0 || m.cols >Max)
    {
        cout<<"\n First Initialize Matrix";
        initialize(m);
        return;
    }

    struct node *rowTail[Max] = {NULL};
    struct node *colTail[Max] = {NULL};

    for(int i=0;i<m.rows;i++)
    {
        for(int j=0;j<m.cols;j++)
        {
            cout<<"\n Enter The Element ["<<i<<"]"<<"["<<j<<"] : ";
            cin>>val;
            insert(m,i,j,val,rowTail,colTail);
        }
    }

    cout<<"\n Matrix Created Successfully";
}

int getValue(struct matrix &m,int r,int c)
{
    struct node *temp = m.rowHead[r];

    while(temp!=NULL)
    {
        if(temp->col == c)
        {
            return temp->data;
        }

        temp = temp->right;
    }

    return 0;
}

void display(struct matrix &m)
{
    if(m.rows == 0)
    {
        cout<<"\n Matrix Not Created First Create a Matrix";
        return;
    }

    for(int i=0;i<m.rows;i++)
    {
        for(int j=0;j<m.cols;j++)
        {
            cout<<getValue(m,i,j)<<"\t";
        }
        cout<<endl;
    }
}

void matrix_addition(struct matrix &a,struct matrix &b)
{
    if(a.rows == 0 || b.rows == 0)
    {
        cout<<"\n First Create Both Matrix";
        return;
    }

    if(a.rows != b.rows || a.cols != b.cols)
    {
        cout<<"\n Matrix Addition Not Possible";
        return;
    }

    struct matrix c;

    initialize(c);

    c.rows = a.rows;
    c.cols = a.cols;

    struct node *rowTail[Max] = {NULL};
    struct node *colTail[Max] = {NULL};

    for(int i=0;i<c.rows;i++)
    {
        for(int j=0;j<c.cols;j++)
        {
            int value = getValue(a,i,j) + getValue(b,i,j);

            insert(c,i,j,value,rowTail,colTail);
        }
    }

    cout<<"\n Addition Result : \n";
    display(c);
}

void matrix_multiplication(struct matrix &a,struct matrix &b)
{
    if(a.rows == 0 || b.rows == 0)
    {
        cout<<"\n First Create Both Matrix";
        return;
    }

    if(a.cols != b.rows)
    {
        cout<<"\n Matrix Addition Not Possible";
        return;
    }

    struct matrix c;

    initialize(c);

    c.rows = a.rows;
    c.cols = b.cols;

    struct node *rowTail[Max] = {NULL};
    struct node *colTail[Max] = {NULL};

    for(int i=0;i<c.rows;i++)
    {
        for(int j=0;j<c.cols;j++)
        {
            int sum = 0;

            for(int k=0;k<a.cols;k++)
            {
                sum = sum + (getValue(a,i,k) * getValue(b,k,j));     
            }

            insert(c,i,j,sum,rowTail,colTail);
        }
    }

    cout<<"\n Multiplication Result : \n";
    display(c);
}