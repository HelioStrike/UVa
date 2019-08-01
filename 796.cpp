#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 100
using namespace std;

int n,m,c,k,timer;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> tim(N,-1);
vector<int> low(N,-1);

void dfs(int v, int p)
{
    vis[v]=1;
    tim[v]=low[v]=timer++;
    for(int to: g[v])
    {

        if(to==p) continue;
        if(vis[to]) low[v]=min(low[v],tim[to]);
        else
        {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tim[v]) cout<<v<<' '<<to<<'\n';
        }
    }
}

int main()
{
    cin>>n;
    FOR(i,0,n)
    {
        cin>>k>>m;
        FOR(j,0,m) cin>>c,g[k].push_back(c);
    }
    FOR(i,0,n) if(!vis[i]) dfs(i,-1);

    return 0;
}