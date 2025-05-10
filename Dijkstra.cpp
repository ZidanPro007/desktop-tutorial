#include<iostream>
using namespace std;
#define INF 999
int V=4,src=0,cost[100][100];
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
void display()
{
    cout<<"NODE:\t\t\t cost :\t\t\tpath";
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
        int path[100],idx=0;
        int current=i;
        while(current!=src)
        {
            path[idx++]=current;
            current =parent[current];
            cout<<src;
            for(int j=idx-1;j>=0;j--)
            {

                cout<<"->"<<path[j];
            }

        }
        cout<<endl;
    }
}
int main()
{
    int inputcost[4][4]={
    {0,1,4,2},{INF,0,INF,5},{4,INF,0,3},{2,5,3,0}
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
    display();
    return 0;





}

