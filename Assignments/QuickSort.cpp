#include <iostream>
#include <conio.h>

using namespace std;

void QuickSort_Insert(int[]);
void QuickSort(int[], int, int);
int partition(int[], int, int);
void QuickSort_Display(int[]);

int main()
{
    int a[10];

    QuickSort_Insert(a);
    QuickSort(a, 0, 9);
    QuickSort_Display(a);
}

void QuickSort_Insert(int a[])
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        cout << "\n Array[" << i + 1 << "] : ";
        cin >> a[i];
    }
}

void QuickSort(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);
        QuickSort(a, low, p - 1);
        QuickSort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j)
    {
        while (i <= high && a[i] < pivot)
        {
            i = i + 1;
        }

        while (j >= low && a[j] > pivot)
        {
            j = j - 1;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i=i+1;
            j=j-1;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void QuickSort_Display(int a[])
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        cout << "\n Array[" << i + 1 << "] : " << a[i];
    }
}