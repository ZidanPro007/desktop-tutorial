#include<iostream>
using namespace std;
#define INF 999

int V=5,src=0,cost[100][100];
int dist[100];
bool visited[100]={0};
int parent[100];
void init()
{
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
      dist[i]=INF;

    }
    dist[src]=0;
}
int getnear()
{
    int minvalue=INF;
    int minnode=0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&dist[i]<minvalue)
        {
            minvalue=dist[i];
            minnode=i;
        }
    }
    return minnode;
}
void dijkstra()
{
    for(int i=0;i<V;i++)
    {
        int nearest=getnear();
        visited[nearest]=true;
        for(int adj=0;adj<V;adj++)
        {
            if(cost[nearest][adj]!=INF&&dist[adj]>dist[nearest]+cost[nearest][adj])
            {
                dist[adj]=dist[nearest]+cost[nearest][adj];
                parent[adj]=nearest;
            }
        }

    }
}
void display(int di)
{
    if(dist[di]==INF)
    {

        cout<<"NO path from "<<src<<" To "<<di<<endl;
        return;
    }
    cout<<"Minimum time :"<<dist[di]<<endl;
    cout<<"Path:";
    int path[100];
    int idx=0;
    int current=di;
    while(current!=src&&current!=-1)
    {

        path[idx++]=current;
        current=parent[current];
    }
    cout<<src;
    for(int i=idx-1;i>=0;i--)
    {

        cout<<" ->"<<path[i];
    }
}
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
    int inputcost[5][5]={
    {0,2,4,INF,INF},{2,0,1,7,INF},{4,1,0,2,INF},{INF,7,2,0,3},{INF,INF,INF,3,0}
    };
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cost[i][j]=inputcost[i][j];
        }
    }
    init();
    dijkstra();
    int di=4;
    display(di);
    int n,capacity;
    cout<<"\nEnter total item number:";
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


