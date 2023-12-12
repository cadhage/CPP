#include <bits/stdc++.h>
using namespace std;
int prime[10];
bool pr(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
			}
	}
	return true;
}
void isPrime(){
	int i=0;
	for(int k=65;k<=90;k++){
	if(pr(k)){
		prime[i]=k;
		i++;
		}
	}
}
int main(){
	int q;
	cin>>q;
	while(q-->0){
		int n;cin>>n;
		string s;cin>>s;
		isPrime();
		int mn=0; 
		for(int k=0;k<n;k++){
		for(int i=0;i<10;i++){
			if(abs(prime[i]-s[k])-s[i]<mn){
				mn=abs(prime[i]-s[k])-s[i];
				break;
			}
		}
		}
		cout<<mn<<endl;
	}
	return 0;
}
