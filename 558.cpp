#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 1010
#define M 2010
using namespace std;

int n,m,x,t,d[N],e[M][3];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        FOR(i,0,m) cin>>e[i][0]>>e[i][1]>>e[i][2];
        FOR(i,0,n)
        {
            x=-1;
            FOR(j,0,m)
            {
                if(d[e[j][0]]+e[j][2]<d[e[j][1]])
                {
                    d[e[j][1]]=d[e[j][0]]+e[j][2];
                    x=e[j][1];
                }
            }
        }
        if(x==-1) cout<<"not possible"<<'\n';
        else cout<<"possible"<<'\n';
    }

    return 0;
}