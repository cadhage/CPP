#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<pair<int,int>> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].first>>a[i].second;
		}
		sort(a.rbegin(),a.rend());
		int ans=0;
		multiset<int> taken;
		multiset<int> takennt;
		long long sum=0;
		long long cnt=0;
		for(auto &p:a){
			if(!taken.empty()&&p.second<=*(--taken.end())){
				taken.insert(p.second);
				sum+=p.second;
				cnt++;
			}else{
				takennt.insert(p.second);
			}
			for(int rot=0;rot<2;rot++){
				while(sum>cnt*p.first){
					auto it=--taken.end();
					sum-=*it;
					cnt--;
					takennt.insert(*it);
					taken.erase(it);
				}
				while(!takennt.empty()){
					auto it=takennt.begin();
					if(sum+*it>(cnt+1)*p.first)
						break;
					sum+=*it;
					cnt++;
					taken.insert(*it);
					takennt.erase(it);
				}
			}
			ans=max(ans,(int)cnt);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
