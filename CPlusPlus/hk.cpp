#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	set<vector<int>> st;
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			vector<int> v;
			for (int k =i ; k <j ; k++) {
                    v.push_back(a[k]);
			}
			if(!v.empty())
				st.insert(v);
		}
		
	}
	int total=0;
	for(auto i:st){
		auto it=i.rbegin();
		int temp=*it;
		int sum=0;
		for(auto it=i.rbegin();it!=i.rend();it++){
			sum+=*it*temp;
		}
		total+=sum;
		//cout<<endl;
	}
	cout<<total;
	return 0;
}
