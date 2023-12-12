#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int d1,v1,d2,v2,p;cin>>d1>>v1>>d2>>v2>>p;
  long long int pr1=0,pr2=0,sum=0;
  for(int i=1;i<=p;i++){
  	if(i>=d1)
	  pr1+=v1;
  	if(i>=d2)
	  pr2+=v2;
	if((pr1+pr2)>=p){
		cout<<i<<'\n';
		break;
	}
//	cout<<pr1<<" "<<pr2<<'\n';
  }
  //cout<<pr1<<" "<<pr2<<'\n';
  return 0;
}

