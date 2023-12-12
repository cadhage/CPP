// CPP program to find all subsets by backtracking. 
#include <bits/stdc++.h> 
using namespace std; 
bool checkValidPair(int num1, int num2) 
{ 
	string s1 = to_string(num1); 
	string s2 = to_string(num2); 
	for (int i = 0; i < s1.size(); i++) 
		for (int j = 0; j < s2.size(); j++) 
			if (s1[i] == s2[j]) 
				return true; 
	return false; 
}
bool check(vector<int> a,int x){
	for(int i=0;i<a.size();i++){
		if(checkValidPair(a[i],x))
			return false;
	}
	return true;
}
int main() 
{ 
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		} 
		int mx=0;
		//cout<<'\n';
		sort(a.begin(),a.end(),[&](auto x,auto y){
			return x>y;
		});
		for(int i=0;i<a.size();i++){
			vector<int> temp;
			temp.push_back(a[i]);
			for(int j=0;j<a.size();j++){
				if(!checkValidPair(a[i],a[j]) && check(temp,a[j])){
					temp.push_back(a[j]);
				}
			}
			int sum=0;
//			for(auto it:temp){
//				cout<<it<<' ';
//			}
//			cout<<"......................\n";
			
			for(auto it:temp){
				sum+=it;
			}
			mx=max(mx,sum);
		 	temp.clear();
		}
		cout<<mx<<'\n';
	}
	return 0; 
} 

