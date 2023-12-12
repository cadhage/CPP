#include<bits/stdc++.h>
    #define MOD 1000000007
    #define ll  unsigned long long
    using namespace std;
     
    void multiply(ll T[3][3], ll M[3][3])
    {
        ll a, b, c, d, e, f, g, h, i;
        a = (T[0][0] * M[0][0] + T[0][1] * M[1][0] + T[0][2] * M[2][0])%MOD;
        b = (T[0][0] * M[0][1] + T[0][1] * M[1][1] + T[0][2] * M[2][1])%MOD;
        c = (T[0][0] * M[0][2] + T[0][1] * M[1][2] + T[0][2] * M[2][2])%MOD;
        d = (T[1][0] * M[0][0] + T[1][1] * M[1][0] + T[1][2] * M[2][0])%MOD;
        e = (T[1][0] * M[0][1] + T[1][1] * M[1][1] + T[1][2] * M[2][1])%MOD;
        f = (T[1][0] * M[0][2] + T[1][1] * M[1][2] + T[1][2] * M[2][2])%MOD;
        g = (T[2][0] * M[0][0] + T[2][1] * M[1][0] + T[2][2] * M[2][0])%MOD;
        h = (T[2][0] * M[0][1] + T[2][1] * M[1][1] + T[2][2] * M[2][1])%MOD;
        i = (T[2][0] * M[0][2] + T[2][1] * M[1][2] + T[2][2] * M[2][2])%MOD;
        T[0][0] = a;
        T[0][1] = b;
        T[0][2] = c;
        T[1][0] = d;
        T[1][1] = e;
        T[1][2] = f;
        T[2][0] = g;
        T[2][1] = h;
        T[2][2] = i;
    }
     
    void power(ll T[3][3], ll n)
    {
        if (n == 0 || n == 1)
            return;
        ll M[3][3] = { { 1, 1, 1 }, { 1, 0, 0 }, 
                                     { 0, 1, 0 } };
        power(T, n / 2);
        multiply(T, T);
        if (n % 2)
            multiply(T, M);
    }
     
    ll tribonacci(ll n)
    {
        ll T[3][3] = { { 1, 1, 1 }, { 1, 0, 0 },
                                     { 0, 1, 0 } };
        if (n == 0 || n == 1)
            return 0;
        else
            power(T, n - 2);
        return T[0][0];
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll T,N;
        cin>>T;
        while(T--)
        {
            cin>>N;
            cout<<tribonacci(N+3)<<"\n";
        }
        return 0;
    }
