#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
void makeset(vector<int>&parent,vector<int>&rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int findparent(vector<int>&parent,int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node]=findparent(parent,parent[node]);
}
void unionset(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank[u]<rank[v])
    {
        parent[v]=u;
    }
    else if(rank[u]>rank[v])
    {
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int MST(vector<vector<int>>&edges,int n,vector<vector<int>>&mstedge)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank(n);
    makeset(parent,rank,n);
    int minweight=0;
    for(int i=0;i<edges.size();i++)
    {
        int u=findparent(parent,edges[i][0]);
        int v=findparent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v)
        {
            minweight+=wt;
            mstedge.push_back({edges[i][0],edges[i][1],wt});
            unionset(u,v,parent,rank);
        }
    }
    return minweight;
}
int main() {
    vector<vector<int>> edges={
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4},
    {1, 4, 8},
    {4, 6, 3},
    {5, 6, 4},
    {5, 8, 6},
    {5, 7, 7}
    };

    int n=9;
    vector<vector<int>>mst_edges;
    int totalWeight=MST(edges,n,mst_edges);

    cout<<"Edges in the Minimum Spanning Tree:\n";
    for (int i=0;i<mst_edges.size();i++) {
    vector<int> edge = mst_edges[i];
    cout <<edge[0]<<" -- "<<edge[1]<<" == "<<edge[2]<<"\n";
}

    cout<<"Total Weight of MST: "<<totalWeight<<endl;

    return 0;
}
