#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
    return std::fabs(dFirstVal - dSecondVal) < 1E-3;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int x,y;cin>>x>>y;
		double res=0.0;
		double ans=0.0,prev_ans=0.0;
		int cnt=0;
		for(int k=1;k<=x;k++){
			for(double i=0.1;i<=10;i=i+0.1){
			if(cnt<=k-1)
				prev_ans=i;
			res=i*k;
			//cout<<res<<' '<<cnt<<' ';
			cnt++;
			if(AreDoubleSame(res,y)){
				if(cnt==x)
					ans=prev_ans;
				cnt=0;
				break;
			}
		}
		}
		
		cout<<'\n'<<ans<<'\n';
	}
	return 0;
}

