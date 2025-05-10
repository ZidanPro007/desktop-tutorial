#include<iostream>
using namespace std;
void bubblesortA(int a[],int n)
{
    int i,pass,temp;
    for(pass=1;pass<n;pass++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
void bubblesortD(int a[],int n)
{
    int i,pass,temp;
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;

            }
        }
    }
}
void printA(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"Enter the element of an array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubblesortA(a,n);
    cout<<"After sorting in ascending order:";
    printA(a,n);
    bubblesortD(a,n);
    cout<<"After sorting in descending order:";
    printA(a,n);

    return 0;

}
