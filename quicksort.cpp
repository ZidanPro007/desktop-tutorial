#include <iostream>
using namespace std;


int partitionA(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for (int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quickSortA(int arr[],int low,int high)
{
    if (low<high)
    {
        int pi=partitionA(arr,low,high);

        quickSortA(arr,low,pi-1);
        quickSortA(arr,pi+1,high);
    }
}
int partitionD(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for (int j=low;j<high;j++)
    {
        if(arr[j]>pivot)
            {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSortD(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partitionD(arr,low,high);

        quickSortD(arr,low,pi-1);
        quickSortD(arr,pi+1,high);
    }
}
void printArray(int arr[],int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr1[n],arr2[n];

    cout<<"Enter the elements of the array: ";
    for (int i=0;i<n;i++) {
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }
    quickSortA(arr1,0,n-1);
    cout<<"After sorting in ascending order: ";
    printArray(arr1,n);
    quickSortD(arr2,0,n-1);
    cout<<"After sorting in descending order: ";
    printArray(arr2,n);

    return 0;
}

