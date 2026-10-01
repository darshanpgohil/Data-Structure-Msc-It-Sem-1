#include<iostream>

using namespace std;

void Heap_insert(int [],int);
void INSHEAP(int [],int &,int);
int DELHEAP(int [],int *);
void Heap_sort(int [],int);
void Heap_display(int [],int);

int main()
{
    int a[11],n;

    cout<<"\n Enter The N : ";
    cin>>n;

    Heap_insert(a,n);
    Heap_sort(a,n);
    Heap_display(a,n);
}

void Heap_insert(int a[],int n)
{
    int i=0;

    for(i=1;i<=n;i++)
    {
        cout<<"\n Array["<<i<<"] : ";
        cin>>a[i];
    }
}

void INSHEAP(int k[],int &N,int x)
{
    int PTR,PAR;
    N = N + 1;

    PTR = N;

    while(PTR > 1)
    {
        PAR = PTR / 2;

        if(x >= k[PAR])
        {
            break;
        }

        k[PTR] = k[PAR];
        PTR = PAR;
    }

    k[PTR] = x;
}

int DELHEAP(int k[],int *N)
{
    int ITEM,LAST,PTR,LEFT,RIGHT;

    ITEM = k[1];

    LAST = k[*N];
    *N = *N - 1;

    PTR = 1;
    LEFT = 2;
    RIGHT = 3;
    
    while(LEFT <= *N)
    {
        int CHILD;

        if(RIGHT <= *N)
        {
            if(k[RIGHT] < k[LEFT])
            {
                CHILD = RIGHT;
            }
            else
            {
                CHILD = LEFT;
            }
        }
        else
        {
            CHILD = LEFT;
        }

        if(LAST <= k[CHILD])
        {
            break;
        }

        k[PTR] = k[CHILD];

        PTR = CHILD;
        LEFT = PTR * 2;
        RIGHT = 2 * PTR + 1;
    }

    k[PTR] = LAST;

    return ITEM;
}

void Heap_sort(int k[],int n)
{
    int b[11],N=0,i=0;

    for(i=1;i<=n;i++)
    {
        b[i] = k[i];
    }

    for(i=1;i<=n;i++)
    {
        INSHEAP(b,N,k[i]);
    }

    for(i=1;i<=n;i++)
    {
        k[i] = DELHEAP(b,&N);
    }
}

void Heap_display(int a[],int n)
{
    int i=0;

    for(i=1;i<=n;i++)
    {
        cout<<"\n Array["<<i<<"] : "<<a[i];
    }
}