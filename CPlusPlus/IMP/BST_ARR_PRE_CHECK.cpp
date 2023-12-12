#include <bits/stdc++.h>
using namespace std;
bool canRepresentBST(int a[],int n){
	stack<int> s;
	int root=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(root>a[i])
			return false;
		while(!s.empty() && s.top()<a[i]){
			root=s.top();
			s.pop();
		}
		s.push(a[i]);
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pre1[] = {40, 30, 35, 80, 100}; 
    int n = sizeof(pre1)/sizeof(pre1[0]); 
    canRepresentBST(pre1, n)? cout << "true": 
                              cout << "false"; 
	return 0;
}
