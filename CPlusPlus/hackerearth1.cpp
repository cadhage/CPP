#include <bits/stdc++.h>
using namespace std;
void move_right(char a[],int n){
	char temp=a[0];
	for(int i=0;i<=n;i++){
		a[i]=a[i+1];
	}
	a[n]=temp;
}
int cal(string s){

	int sum=0;
	for(int i=0;i<s.length();i++)
	{
		sum+=(s[i]-'a'+1)*(int)pow(2,i*(-1));
	}
	return sum;
}
int main(){
	char s[1000];cin>>s;
	int n=strlen(s);
	int mx=0,temp=0;
	string ss=s;
	for(int i=0;i<n;i++){
		
	//	cout<<s<<endl;
		
		int r=cal(s);
		move_right(s,n-1);
		if(mx<r){
			mx=r;
			ss=s;
		}
	//	cout<<r<<" ";
	}
	cout<<ss<<endl;
	return 0;
}
