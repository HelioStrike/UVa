#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 110
using namespace std;

int dp[N][N];
string s;

int solve(int l,int r)
{
    if(l==r) return 1;
    if(dp[l][r]) return dp[l][r];
    int i,j,k;
    dp[l][r]=0xfffffff;
    for(i=l;i<r;i++) dp[l][r]=min(dp[l][r],solve(l,i)+solve(i+1,r));
    int sl=r-l+1;
    for(i=1;i<=sl;i++)
    {
        if(sl%i) continue;
        for(k=l,j=0;k<=r;k++)
        {
            if(s[k]!=s[j+l]) break;
            j++; 
            if(j>=i) j=0;
        }
        if(k==r+1 && r!=l+i-1) dp[l][r]=min(dp[l][r],solve(l,l+i-1));    
    }

    return dp[l][r];
}

int main()
{
    while((cin>>s)&&(s!="*"))
    {
        memset(dp,0,sizeof(dp));
        cout<<solve(0,s.length()-1)<<'\n';
    }

    return 0;
}