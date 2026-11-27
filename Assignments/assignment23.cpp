#include<iostream>

using namespace std;

int block[20];
int original[20];
int allocateds[20];
int n;

void allocation();
void deallocation();
void display();

int main()
{
    int ch;

    cout<<"\n Enter The No Of Available Block : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter The block "<<i+1<<" Size : ";
        cin>>block[i];

        original[i] = block[i];
        allocateds[i] = 0;
    }

    do
    {
        cout<<"\n 1. Allocation \n 2. Deallocation \n 3. Display Block \n 4. Exit \n ";

        cout<<"\n Enter The Ch : ";
        cin>>ch;

        switch(ch)
        {
            case 1: allocation();
                    break;

            case 2: deallocation();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: cout<<"\n Wrong Choice";
                     break;
        }
    }while(ch!=4);
}

void allocation()
{
    int size,best = -1;

    cout<<"\n Enter The Size : ";
    cin>>size;

    for(int i=0;i<n;i++)
    {
        if(allocateds[i] == 0 && block[i] >= size)
        {
            if(best == -1 || block[i] < block[best])
            {
                best = i;
            }
        }
    }

    if(best == -1)
    {
        cout<<"\n Block Not Availabe";
    }
    else
    {
        cout<<"\n Process Allocated Successfully";
        cout<<"\n Allocated Block : "<<best+1;

        allocateds[best] = 1;
        block[best] = block[best] - size;

        cout<<"\n Remaining Block "<<block[best]<<" KB"<<endl;
    }
}

void deallocation()
{
    int b;

    cout<<"\n Enter The Block Number To Deallocate : ";
    cin>>b;

    if(b<1 || b>n)
    {
        cout<<"\n Invalid Block Number";
    }
    else if(allocateds[b-1] == 0)
    {
        cout<<"\n Block Is Already Free";
    }
    else
    {
        block[b-1] = original[b-1];
        allocateds[b-1] = 0;

        cout<<"\n Memory Deallocated Successfully";
    }
}

void display()
{
    cout<<"\n Block\tMemmory\t\tStatus\n";

    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<block[i]<<"KB\t\t";

        if(allocateds[i] == 0)
        {
            cout<<"Free";
        }
        else
        {
            cout<<"Allocated";
        }

        cout<<endl;
    }
}