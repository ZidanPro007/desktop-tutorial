#include<iostream>
#include<climits>
using namespace std;
int dp[100][100];
int split[100][100];
string getorder(int i,int j)
{
    if(i==j)
    {
        return "A"+ to_string(i);
    }
    return "("+getorder(i,split[i][j])+getorder(split[i][j]+1,j)+")";
}
int MCM(int p[],int n)
{
    for(int i=1;i<n;i++)
    {
        dp[i][i]=0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<=n-l;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<dp[i][j])
                {
                    dp[i][j]=cost;
                    split[i][j]=k;
                }
            }
        }
    }
    return dp[1][n-1];

}
int main()
{
    int n;
    cout<<"Enter matrices:";
    cin>>n;
    int p[n+1];
    cout<<"Enter dimension:";
    for(int i=0;i<=n;i++)
    {
        cin>>p[i];
    }

    int mincost=MCM(p,n+1);
    string order=getorder(1,n);
    cout<<"Multiplication:"<<mincost<<endl;
    cout<<order;
    return 0;

}
