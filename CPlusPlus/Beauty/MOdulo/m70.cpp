#include <bits/stdc++.h>
using namespace std;
void solver(int n){
	vector<int> box[18];
	int mul=1;
	int last=0;
	for(int i=0;i<18;i++){
		vector<int> vect1;
		vector<int> vect2;
		if(i%2==0){
			for(int j=last+1;j<=last+6;j++){
					vect1.push_back((j));
			}
			box[i]=vect1;
		}
		else {
				for(int j=12+last;j>=last+7;j--){
					vect2.push_back((j));
			}
			box[i]=vect2;
			last+=12;
		}
		
		//cout<<'\n';
	}
	for(int i=0;i<18;i++){
		for(auto it:box[i]){
			cout<<it<<" ";
		}
		cout<<'\n';
	}
	int div=n/12;
	if(div==0){
		int div1=n/6;
		int rem=n%6;
		if(div1==0){
			cout<<box[1][rem-1];
		}
		else{
			cout<<box[0][6-rem];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		solver(n);
	}
	return 0;
}
