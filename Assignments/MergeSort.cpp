#include<iostream>
#include<conio.h>

using namespace std;

void MergeSort_Insert(int []);
void MergeSort(int [],int,int);
void merge(int [],int,int,int);
void MergeSort_Display(int []);

int main()
{
    int a[10];

    MergeSort_Insert(a);
    MergeSort(a,0,9);
    MergeSort_Display(a);
}

void MergeSort_Insert(int a[])
{
    int i=0;

    for(i=0;i<10;i++)
    {
        cout<<"\n Enter The Array["<<i+1<<"] : ";
        cin>>a[i];
    }
}

void MergeSort(int a[],int low,int high)
{
    int mid=0;

    if(low<high)
    {
        mid = (low+high)/2;

        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;

    int b[10];

    while(i<=mid && j<=high)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i = i+1;
        }
        else{
            b[k] = a[j];
            j = j+1;
        }

        k = k+1;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        i = i+1;
        k = k+1;
    }

    while(j <= high)
    {
        b[k] = a[j];
        j = j+1;
        k = k+1;
    }

    for(i=low;i<=high;i++)
    {
        a[i] = b[i];
    }
}

void MergeSort_Display(int a[])
{
    int i=0;

    for(i=0;i<10;i++)
    {
        cout<<"\n Array["<<i+1<<"] : "<<a[i];
    }
}