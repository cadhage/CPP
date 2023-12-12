#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    ll n;cin>>n;
    vector<ll> arr(n),b(n+1),c(n);
    b[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>arr[i-1];
        b[i]=0;
        c[i-1]=0;
    }
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+arr[i-1];
    }
    for(ll i=0;i<n;i++){
        ll j=i+1,demand=2;
        ll remain=n-j;
        while(demand<=remain && j<n){
            demand+=1;
            j=j+demand-1;
            remain=n-j;
        }
        c[i]=b[j]-b[i];
    }
    sort(c.begin(),c.end()); 
    cout<<c[c.size()-1];
    return(0);
}
