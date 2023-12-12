#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	/*  std::cout.width(6); std::cout << std::internal << n << '\n';
  std::cout.width(6); std::cout << std::left << n << '\n';
  std::cout.width(6); std::cout << std::right << n << '\n';
*/	for(int ii=0;ii<tt;ii++){
		int g,p;cin>>g>>p;
		int n;cin>>n;
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			sum1+=x;sum2+=y;
		}
		cout<<min(sum1*g+sum2*p,sum1*p+sum2*g)<<"\n";
	}
	return 0;
}
