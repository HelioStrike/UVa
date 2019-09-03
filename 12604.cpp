#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define W 50010
#define S 500010
using namespace std;

int t,n,an,wn,sn; 
string a,w,s;
int s_[S];
map<char,int> m;
set<int> se;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>w>>s; m.clear(); se.clear();
        s=w+s; an=a.length(),wn=w.length(),sn=s.length();
        if(sn%wn) { cout<<"no solution"<<'\n'; continue; }
        FOR(i,0,an) m[a[i]]=i;
        for(int i=0;i<sn;i+=wn) FOR(j,0,wn) s_[i+j]=(m[s[i+j]]-m[s[i]]+an)%an;
        vector<int> p(sn,0);
        FOR(i,1,sn)
        {
            int j=p[i-1];
            while(j>0 && s_[i]!=s_[j]) j=p[j-1];
            if(s_[i]==s_[j]) j++;
            p[i]=j;
        }
        if(p[sn-1]>=sn-wn)
        {
            for(int i=wn;i<sn;i+=wn) se.insert((m[s[i]]-m[s[0]]+an)%an);
            if(se.size()==1) cout<<"unique: ";
            else if(se.size()>1) cout<<"ambiguous: ";
            for(int i: se) cout<<i<<' ';
            cout<<'\n';
        } else cout<<"no solution"<<'\n';
    }

    return 0;
}