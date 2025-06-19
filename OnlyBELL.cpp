#include<iostream>
#include<climits>
using namespace std;
#define INF 999
int V,src,cost[100][100],dist[100],parent[100];
void BELL()
{
    for(int i=0;i<V;i++)
    {
        parent[i]=-1;
        dist[i]=INF;

    }
    dist[src]=0;
    for(int k=0;k<V-1;k++)
    {
        for(int u=0;u<V;u++)
        {
            for(int v=0;v<V;v++)
            {
                if(cost[u][v]!=INF&&dist[u]!=INF&&dist[v]>dist[u]+cost[u][v])
                {
                    dist[v]=dist[u]+cost[u][v];
                    parent[v]=u;
                }
            }
        }
    }
}
void display(int di)
{
    if(dist[di]==INF)
    {
        cout<<"No path";
        return ;
    }
    cout<<"Minimum cost:"<<dist[di];
    cout<<"path ";
    int path[100];
    int idx=0;
    int current=di;
    while(current!=-1)
    {
        path[idx++]=current;
        current=parent[current];
    }
    cout<<src;
    for(int i=idx-1;i>=0;i--)
    {
       cout<<"->"<<path[i]+1;
    }
    cout<<endl;

}
int main()
{
    int E,S,D;
    cout<<"Enter V and E:";
    cin>>V>>E;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cost[i][j]=INF;
        }
    }
    cout<<"Enter u,v,w:";
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        cost[u-1][v-1]=w;
    }

    cout<<"Enter source and distenasion:";
    cin>>S>>D;
    src=S-1;
    BELL();
    display(D-1);
}
