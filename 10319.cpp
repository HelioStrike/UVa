#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 200
using namespace std;

int t,s,a,n,s1,a1,s2,a2,pos,cn,comp[N];
bool vis[N];
vector<int> ord,g[N];

void dfs1(int u)
{
    if(vis[u]) return;
    vis[u]=1;
    for(int v: g[u]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u)
{
    if(!vis[u]) return;
    vis[u]=0; comp[u]=cn;
    for(int v: g[u]) dfs2(v);
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s>>a>>n;
        FOR(i,0,n)
        {
            cin>>s1>>a1>>s2>>a2;
            ord.clear();
            FOR(j,0,n) g[j].clear();
            s1--,a1--,s2--,a2--; pos=1;
            a1+=s,a2+=s;
            s1<<=1,a1<<=1,s2<<=1,a2<<=1;
            if(a1>a2) s1^=1,s2^=1;
            if(s1>s2) a1^=1,a2^=1;
            if(s1==s2) {
                g[s1^1].push_back(s2);
                continue;
            } 
            if(a1==a2) {
                g[a1^1].push_back(a2);
                continue;
            }
            g[s1^1].push_back(s2);
            g[s2^1].push_back(s1);

            g[s1^1].push_back(a1);
            g[a1^1].push_back(s1);

            g[s2^1].push_back(a2);
            g[a2^1].push_back(s2);

            g[a1^1].push_back(a2);
            g[a2^1].push_back(a1);
        }
        FOR(i,0,2*(s+a)) if(!vis[i]) dfs1(i);
        reverse(ord.begin(),ord.end());
        for(int u: ord) if(vis[u]) dfs2(u),cn++;
        FOR(i,0,s+a) if(comp[2*i]==comp[2*i+1]) pos=0;
        cout<<(pos?"Yes":"No")<<'\n';
    }

    return 0;
}