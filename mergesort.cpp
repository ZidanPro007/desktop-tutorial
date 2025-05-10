#include<iostream>
using namespace std;
void mergeA(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int leftarr[n1],rightarr[n2];
    for(int i=0;i<n1;i++)
    {
        leftarr[i]=a[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        rightarr[j]=a[q+1+j];
    }

    int i=0,j=0,k=p;
    while(i<n1&&j<n2)
    {
        if(leftarr[i]<=rightarr[j])
        {
            a[k]=leftarr[i];
            i++;
        }
        else
        {
            a[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=rightarr[j];
        j++;
        k++;
    }
}
void mergeD(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int leftarr[n1],rightarr[n2];
    for(int i=0;i<n1;i++)
    {
        leftarr[i]=a[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        rightarr[j]=a[q+1+j];
    }

    int i=0,j=0,k=p;
    while(i<n1&&j<n2)
    {
        if(leftarr[i]>=rightarr[j])
        {
            a[k]=leftarr[i];
            i++;
        }
        else
        {
            a[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=rightarr[j];
        j++;
        k++;
    }
}
void mergesortA(int a[],int p,int r)
{
    if(p<r)
    {
        int q=p+(r-p)/2;
        mergesortA(a,p,q);
        mergesortA(a,q+1,r);
        mergeA(a,p,q,r);
    }
}
void mergesortD(int a[],int p,int r)
{
    if(p<r)
    {
        int q=p+(r-p)/2;
        mergesortD(a,p,q);
        mergesortD(a,q+1,r);
        mergeD(a,p,q,r);
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
    mergesortA(a,0,n-1);
    cout<<"After sorting in ascending order:";
    printA(a,n);
    mergesortD(a,0,n-1);
    cout<<"After sorting in descending order:";
    printA(a,n);

    return 0;
}
