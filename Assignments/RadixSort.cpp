#include<iostream>

using namespace std;

void insert_redix(int [],int);
void radix_sort(int [],int);
void display_redix(int [],int);

int main()
{
    int a[10],n;

    cout<<"\n Enter The N : ";
    cin>>n;
    insert_redix(a,n);
    radix_sort(a,n);
    display_redix(a,n);
}

void insert_redix(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        cout<<"\n Array["<<i+1<<"] : ";
        cin>>a[i];
    }
}

void radix_sort(int a[],int n)
{
    int max,i=0,pos=0,digit,k=0,j=0;

    max = a[0];

    for(i=1;i<n;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    for(pos=1;max/pos > 0;pos = pos * 10)
    {
        int bucket[10][20] = {0};
        int count[10] = {0};

        for(i=0;i<n;i++)
        {
            digit = (a[i] / pos) % 10;
            bucket[digit][count[digit]] = a[i];
            count[digit]++;
        }

        k=0;

        for(i=0;i<10;i++)
        {
            for(j=0;j<count[i];j++)
            {
                a[k] = bucket[i][j];
                k++;
            }
        }
    }
}

void display_redix(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        cout<<"\n Array["<<i+1<<"] : "<<a[i];
    }
}