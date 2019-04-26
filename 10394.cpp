#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 20000010
using namespace std;

int k;
vector<int> primes;
vector<pair<int,int> > ps;

void doit()
{
    vector<bool> isNP(N);
    FOR(i,2,N)
    {
        if(!isNP[i]) for(int j=2*i;j<N;j+=i) isNP[j]=1; 
    }

    FOR(i,2,N) if(!isNP[i]) primes.push_back(i);
    FOR(i,0,primes.size()-1) if(primes[i]+2==primes[i+1]) ps.push_back({primes[i],primes[i+1]});
}

int main()
{
    doit();
    while(cin>>k)
    {
        k--;
        cout<<"("<<ps[k].first<<", "<<ps[k].second<<")"<<'\n';
        if(getchar()==EOF) break;
    }

    return 0;
}