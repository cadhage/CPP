#define WINDOWS
//#define LINUX

/** FAMILY TREE */

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
void solver(string s,int n,int t){
	cout<<"Case #"<<t+1<<": ";
	for(int i=0;i<n;i++){
		int count=1;
		for(int j=0;j<i;j++){
			if(s[j]<s[j+1])
				count++;
			else count=1;
		}
		cout<<count<<' ';
	}
	cout<<'\n';
}
int main()
{
	int tt;cin>>tt;
	for(int t=0;t<tt;t++){
		int n;cin>>n;
		string s;cin>>s;
		solver(s,n,t);
	}
}

