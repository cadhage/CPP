#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
void power(ll int f[2][2],ll int n);
void multiply(ll int f[2][2],ll int m[2][2]);
int fibonacci(ll int n)
{
    if(n==0)
        return 0;
    ll int f[2][2]={{1,1},{1,0}};
    power(f,n);
    return f[0][0];
}
void power(ll int f[2][2],ll int n)
{
    if(n==0||n==1)
        return;
    ll int m[2][2]={{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n&1)
    multiply(f,m);
}
void multiply(ll int f[2][2],ll int m[2][2])
{
    ll int x=((f[0][0])%MOD*(m[0][0])%MOD+(f[0][1])%MOD*(m[1][0])%MOD)%MOD;
    ll int y=((f[1][0])%MOD*(m[0][0])%MOD+(f[1][1])%MOD*(m[1][0])%MOD)%MOD;
    ll int z=((f[0][0])%MOD*(m[0][1])%MOD+(f[0][1])%MOD*(m[1][1])%MOD)%MOD;
    ll int w=((f[1][0])%MOD*(m[0][1])%MOD+(f[1][1])%MOD*(m[1][1])%MOD)%MOD;
    f[0][0]=(int)(x%MOD);
    f[0][1]=(int)(z%MOD);
    f[1][0]=(int)(y%MOD);
    f[1][1]=(int)(w%MOD);
}
int main()
{
    ll int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cout<<fibonacci(i)<<endl;
    //}
}
