#include<iostream>

using namespace std;

void insert(int []);
void insertionSort(int []);
void display(int []);

int main()
{
    int a[3];

    insert(a);
    insertionSort(a);
    display(a);

    return 0;
}

void insert(int a[])
{
    int i;

    for(i=0;i<3;i++)
    {
        cout<<"\n Enter The Value Of Element "<<i+1<<" : ";
        cin>>a[i];
    }
}

void insertionSort(int a[])
{
   int pass=0,i=0,temp=0;
   
   pass = 1;

   while(pass <= 3)
   {
        temp = a[pass];
        i = pass - 1;

        while(temp < a[i] && i >= 0)
        {
            a[i+1] = a[i];
            i = i - 1;
        }

        a[i+1] = temp;
        pass = pass + 1;
   }
}

void display(int a[])
{
    int i;

    cout<<"\n The Sorted Array Is : ";

    for(i=0;i<3;i++)
    {
        cout<<a[i]<<" ";
    }
}