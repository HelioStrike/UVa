#include <bits/stdc++.h>
using namespace std;

int a,b,x,y,d;

int gcd(int a,int b,int& x,int& y) 
{
    if(!a)
    {
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

int main()
{
    while(cin>>a>>b)
    {
        d=gcd(a,b,x,y);
        if(x>y) swap(x,y);
        cout<<x<<' '<<y<<' '<<d<<'\n';
    }

    return 0;
}