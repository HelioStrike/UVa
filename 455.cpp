#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int t,n; 
string s;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s; n=s.length();
        vector<int> p(n,0);
        FOR(i,1,n)
        {
            int j=p[i-1];
            while(j>0 && s[i]!=s[j]) j=p[j-1];
            if(s[i]==s[j]) j++;
            p[i]=j;
        }
        if(n%(n-p[n-1])) cout<<n;
        else cout<<(n-p[n-1]);
        cout<<'\n';
    }

    return 0;
}