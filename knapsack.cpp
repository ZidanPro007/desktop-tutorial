#include<iostream>
using namespace std;
const int MAX=100;
int dp[MAX][MAX],weight[MAX],value[MAX];
int knapsack(int weight[],int value[],int n,int capacity)
{
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=capacity;w++)
        {
            if(i==0||w==0)
            {
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w)
            {
                dp[i][w]=max(dp[i-1][w],value[i-1]+dp[i-1][w-weight[i-1]]);

            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }

        }

    }
    cout<<"Knapsack table:"<<endl;
        for(int i=0;i<=n;i++)
        {
            for (int w=0;w<=capacity;w++)
            {
                cout<<dp[i][w]<<" ";
            }
            cout<<endl;
        }
    return dp[n][capacity];
}
int main()
{
    int n,capacity;
    cout<<"Enter total item number:";
    cin>>n;
    cout<<"Enter capacity item number:";
    cin>>capacity;
    cout<<"Enter weight:";
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    cout<<endl;
    cout<<"Enter values:";
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int maxresult=knapsack(weight,value,n,capacity);
    cout<<"MAX Value is:"<<maxresult;
    return 0;

}
