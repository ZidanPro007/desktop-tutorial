#include<iostream>
#include<climits>
using namespace std;
#define INF 999
int V,src,cost[100][100];
int dist[100];
bool visited[100]={0};
int parent[100];
void intt()
{
    for(int i=0;i<V;i++)
    {
        parent[i]=-1;
        dist[i]=INF;
        visited[i]=false;
    }
    dist[src]=0;
}

int getnear()
{
    int minvalue=INF;
    int minnode=-1;
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
void dij()
{
    for(int i=0;i<V;i++)
    {
        int nearest=getnear();
        if(nearest==-1)
        {
           break;
        }
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
        cout<<"NO path.";
        return;
    }
    cout<<"Minimum transmission cost:"<<dist[di]<<endl;
    cout<<"Path ";
    int path[100];
    int idx=0;
    int current=di;
    while(current!=src&&current!=-1)
    {
        path[idx++]=current;
        current=parent[current];
    }
    cout<<src+1;
    for(int i=idx-1;i>=0;i--)
    {

        cout<<"->"<<path[i]+1;
    }
    cout<<endl;
}
int dp[100][100];
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
            }
        }
      }


   }
   return dp[1][n-1];
 }
int main()
{

     int E,S,D;
    cout<<"Enter V and E: ";
    cin>>V>>E;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cost[i][j]=INF;
        }
    }

    cout<<"Enter edges:"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin >>u>>v>>w;
        cost[u-1][v-1]=w;
    }

    cout<<"Enter source and destination";
    cin >>S>>D;
    src=S-1;
    intt();
    dij();
    display(D-1);
    int n;
    cout<<"Enter the metrics:";
    cin>>n;
    int p[n+1];
    cout<<"Enter dimention:";
    for(int i=0;i<=n;i++)
    {
        cin>>p[i];
    }
    int mincost=MCM(p,n+1);
    cout<<"Multiplication:"<<mincost;
    return 0;
}
