#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int h,w;cin>>h>>w;
	vector<string> grid(h);
	for(int i=0;i<h;i++)
		cin>>grid[i];
	if(h>w){
		vector<string> new_grid(w,string(h,'.'));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				new_grid[j][i]=grid[i][j];
			}
		}
		swap(grid,new_grid);
		swap(h,w);
	}
	long long ans=0;
		vector<int> was(3<<9,0);
		was[0]=1;
		for(int i1=0;i1<h;i1++){
			vector<int> vals(w,0);
			vector<int> evens(w,0);
			vector<int> pref(w+1,0);
			for(int i2=i1;i2<h;i2++){
				for(int j=0;j<w;j++){
					int dig=(int)(grid[i2][j]-'0');
					vals[j]^=(1<<(dig-1));
					vals[j]=(vals[j]&511)+((((vals[j]>>9)+dig)%3)<<9);
					evens[j]+=(dig%2==0);
				}
				for(int j=0;j<w;j++){
					pref[j+1]=pref[j]^(vals[j]&511);
					pref[j+1]=(pref[j+1]&511)+((((pref[j+1]>>9)+(vals[j]>>9))%3)<<9);
				}
				int s2=0,ptr=0;
				for(int j=0;j<w;j++){
					s2+=evens[j];
					while(ptr<j&& s2-evens[ptr]>=2){
						s2-=evens[ptr];
						ptr++;
						was[pref[ptr]]++;
					}
					if(s2>=2){
						ans+=was[pref[j+1]];
						for(int flip=0;flip<9;flip++){
							ans+=was[(pref[j+1]^(1<<flip))];
						}
					}
				}
				for(int j=1;j<=ptr;j++)
					was[pref[j]]--;
			}
		}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ans+=(grid[i][j]=='6');
		}
	}
	cout<<ans<<'\n';
	return 0;
}
