#include<iostream>
using namespace std;
void insertionsortA(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void insertionsortD(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]<key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
    insertionsortA(a,n);
    cout<<"After sorting in ascending order:";
    printA(a,n);
    insertionsortD(a,n);
    cout<<"After sorting in descending order:";
    printA(a,n);

    return 0;

}

