#include <iostream>

using namespace std;

void searching_insert(int[], int);
void searching_technique(int[], int, int);

int main()
{
    int a[10], n, ch;

    searching_insert(a, 10);

    cout << "\n 1. Linear Search \n 2. Binary Search \n ";

    cout << "\n Enter The Choice : ";
    cin >> ch;

    cout << "\n Enter The N : ";
    cin >> n;

    searching_technique(a, n, ch);
}

void searching_insert(int a[], int n)
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        cout << "\n Array[" << i + 1 << "] : ";
        cin >> a[i];
    }
}

void searching_technique(int a[], int n, int ch)
{
    int i = 0, found = 0;
    int low = 0, high = 9, mid = 0;

    switch (ch)
    {
    case 1:
        while (i < 10)
        {
            if (a[i] == n)
            {
                found = 1;
                break;
            }
            else
            {
                i = i + 1;
            }
        }
        if(found == 1)
        {
            cout<<"\n Element Founded At Position : "<<i+1;
        }
        else
        {
            cout<<"\n Element Not Founded";
        }
        break;

    case 2:
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (a[mid] == n)
            {
                found = 1;
                break;
            }
            else if (n < a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (found == 1)
        {
            cout << "\n Element Founded At Position : " << mid + 1;
        }
        else
        {
            cout << "\n Element Not Founded";
        }
        break;

    default:
        cout<<"\n Invalid Choice";
    }
}