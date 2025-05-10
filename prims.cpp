#include<bits/stdc++.h>
using namespace std;
const int V=9;
int minweight(int weight[],bool visited[])
{
    int minimum=INT_MAX;
    int minindex=-1;
    for(int v=0;v<V;v++)
    {
        if(!visited[v]&&weight[v]<minimum)
        {
            minimum=weight[v];
            minindex=v;
        }
    }
    return minindex;
}
void printmst(int parent[],int graph[V][V])
{
    int totalweight=0;
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"  "<<i<<"  "<<graph[i][parent[i]]<<"\n";
        totalweight+=graph[i][parent[i]];
    }
    cout<<"Total weight of mst:"<<totalweight<<"\n";
}
void primsmst(int graph[V][V])
{
    int parent[V];
    int weight[V];
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++)
    {
        int u=minweight(weight,visited);
        visited[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]&&!visited[v]&&graph[u][v]<weight[v])
            {
                parent[v]=u;
                weight[v]=graph[u][v];
            }
        }
    }
    printmst(parent,graph);
}
int main()
{
    int graph[V][V]={
    { 0,10, 6,  5, 0,  0,  0,  0,  0},
    {10, 0, 0, 15, 8,  0,  0,  0,  0},
    { 6, 0, 0,  4, 0,  0,  0,  0,  0},
    { 5,15, 4,  0, 0,  0,  0,  0,  0},
    { 0, 8, 0,  0, 0,  0,  3,  0,  0},
    { 0, 0, 0,  0, 0,  0,  4,  7,  6},
    { 0, 0, 0,  0, 3,  4,  0,  0,  0},
    { 0, 0, 0,  0, 0,  7,  0,  0,  0},
    { 0, 0, 0,  0, 0,  6,  0,  0,  0}
    };
    primsmst(graph);
    return 0;
}
