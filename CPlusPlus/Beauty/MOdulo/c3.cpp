#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n<=1)
		return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
void solver(string s){
	int c=0;
	int sum=0,j=0;
	bool flag=false;
	for(int i=s.size()-1;i>=0;i--){
		int it=(int)(s[i]-'0');
		if(!flag){
			sum+=it;
			flag=true;
		}
		else
		sum+=it*(2<<j++);
		if(1==it)
			c++;
	}
	cout<<c<<' ';
	prime(sum)?cout<<"Lucky day\n":cout<<"Unlucky day\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		string s;cin>>s;
		solver(s);
	}
	return 0;
}
