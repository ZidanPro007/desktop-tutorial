#include<iostream>
using namespace std;
void margedarray(int a[],int b[],int t[])
{

    for(int i=0;i<5;i++)
    {
        t[i]=a[i];
    }
    for(int i=0;i<5;i++)
    {
        t[i+5]=b[i];
    }
    cout<<"marged array:";
    for(int i=0;i<10;i++)
    {
        cout<<t[i]<<" ";
    }
}
void bouble(int t[])
{
    for(int i=0;i<10-1;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            if(t[j]>t[j+1])
            {
                int temp;
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }
}
int binarysearch(int low,int high,int x,int t[])
{
    while(low<=high)
    {
    int mid=(low+high)/2;

   if(t[mid]==x)
   {
       return mid;
   }
   else if(t[mid]>x)
   {
      high=mid-1;
   }
   else
   {
       low=mid+1;
   }
}
return -1;
}

int main()
{
    int a[]={1,3,34,54,33};
    int b[]={40,66,7,23,76};
    int t[10];
    margedarray(a,b,t);
    bouble(t);
    cout<<"after sorting:";
    for(int i=0;i<10;i++)
    {
        cout<<t[i]<<" ";
    }
    int x;
    cout<<"Enter the element to search:";
    cin>>x;
    int k=binarysearch(0,10-1,x,t);
    if(k==-1)
    {
        cout<<"Element not founded";
    }
    else
    {
        cout<<"element at index:"<<k;
    }
    return 0;
}
