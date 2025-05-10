#include<iostream>
using namespace std;
void selectionsortA(int a[],int n)
{
    for (int i=0;i<n-1;i++)
        {
        int minIndex=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[minIndex])
            {
                minIndex=j;
            }
        }
        swap(a[i],a[minIndex]);
    }
}
void selectionsortD(int a[],int n)
{
     for (int i=0;i<n-1;i++)
        {
        int maxIndex=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]>a[maxIndex])
            {
                maxIndex=j;
            }
        }
        swap(a[i],a[maxIndex]);
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
    selectionsortA(a,n);
    cout<<"After sorting in ascending order:";
    printA(a,n);
    selectionsortD(a,n);
    cout<<"After sorting in descending order:";
    printA(a,n);

    return 0;

}


