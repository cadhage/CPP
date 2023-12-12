#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
    int prev=0;
    for(int i=0;i<n;i++){
    	if(a[i]==a[i+1] && k==a[i]){
    		sum++;
    		cout<<sum<<" ";
		}
		//
		else if(sum>0){
			prev+=a[i-1]*(sum+1);
			sum=0;
		}
	}
	cout<<prev<<endl;
    }
}
