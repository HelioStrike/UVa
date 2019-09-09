#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 1010
using namespace std;

int n,x,y,a[N],t[N]; 
string s,q;

void update(int idx,int val)
{
    while(idx<=n)
    {
        t[idx]+=val;
        idx+=idx&(-idx);
    }
}

int add(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=t[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int main()
{
    while((cin>>n)&&(n!=0))
    {
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        FOR(i,1,n+1) cin>>a[i],update(i,a[i]);
        while((cin>>q)&&(q!="END"))
        {
            cin>>x>>y;
            if(q=="S")
            {
                update(x,y-a[x]);
                a[x]=y;
            }
            else
            {
                cout<<add(y)-add(x-1)<<'\n';
            }
        }
    }

    return 0;
}