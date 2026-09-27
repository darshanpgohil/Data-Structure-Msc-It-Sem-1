#include<iostream>
#include<conio.h>

using namespace std;

void insertionSort_Insert(int a[])
{
    int i=0;

    for(i=0;i<10;i++)
    {
        cout<<"\n Enter The Value Of Array["<<i+1<<"] : ";
        cin>>a[i];
    }
}

void insertionSort(int a[])
{
    int pass=0,i=0,temp=0;

    pass=1;

    while(pass < 10)
    {
        temp = a[pass];
        i=pass-1;

        while(temp<a[i] && i>=0)
        {
            a[i+1] = a[i];
            i=i-1;
        }

        a[i+1]=temp;
        pass=pass+1;
    }
}

void insertionSort_Display(int a[])
{
    int i=0;

    for(i=0;i<10;i++)
    {
        cout<<"\n Array["<<i+1<<"] : "<<a[i];
    }
}

int main()
{
    int a[10];

    insertionSort_Insert(a);
    insertionSort(a);
    insertionSort_Display(a);
}