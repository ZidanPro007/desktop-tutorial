#include<iostream>
#include<string>
using namespace std;
#define INF 999

int V=5,src=0,cost[100][100];
int dist[100];
bool visited[100]={0};
int parent[100];
void intt()
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
void dij()
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
    cout<<endl;
}
const int MAX=100;
int dp[MAX][MAX];
string LCS(string X,string Y)
{
    int m=X.length();
    int n=Y.length();
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    string lcs="";
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
             lcs=X[i-1]+lcs;
             i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {

            i--;
        }
        else{
            j--;
        }
    }
    return lcs;
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
    string s1,s2;
    cout<<"Enter the first string:";
    cin>>s1;
    cout<<"Enter the second string:";
    cin>>s2;
    string result=LCS(s1,s2);
    cout<<"Length of the string:"<<result.length()<<endl;
    cout<<"LCS:"<<result;


    return 0;





}
