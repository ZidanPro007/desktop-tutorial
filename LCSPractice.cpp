#include<iostream>
#include<string>
using namespace std;
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

