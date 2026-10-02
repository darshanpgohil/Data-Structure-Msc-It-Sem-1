#include<iostream>

using namespace std;

int main()
{
    int a[5][2],n,time=2,count,i;

    cout<<"\n Enter The Number Of Processes : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n Enter Process P"<<i+1;
        a[i][0] = i+1;

        cout<<"\n Enter The Value : ";
        cin>>a[i][1];
    }

    cout<<"\n Process Working Time Is : "<<time<<" Period\n";

    while(1)
    {
         count = 0;
         
         for(i=0;i<n;i++)
         {
            if(a[i][1] > 0)
            {
                if(a[i][1] > time)
                {
                    a[i][1] = a[i][1] - time;
                    cout<<"\n Process p"<<a[i][0]<<" Is Started Remaining Value Is : "<<a[i][1];
                }
                else
                {
                    a[i][1] = 0;

                    cout<<"\n Process p"<<a[i][0]<<" Is Completed";
                }
            }
         }

         for(i=0;i<n;i++)
         {
            if(a[i][1] > 0)
            {
                count++;
            }
         }

         if(count == 0)
         {
            break;
         }
    }
    cout<<"\n All Processes Are Completed Sucessfully";
}