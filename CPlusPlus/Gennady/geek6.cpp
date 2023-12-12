#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int a[]){
	vector<int> res;
	int a3=a[0]+a[1]+a[2];
	res.push_back(a3-a[1]*2);
	res.push_back(a3-a[2]*2);
	res.push_back(a3-a[0]*2);
	return res;
}
void solver(int a[],int b[]){
	vector<int> v1=solve(a);
	vector<int> v2=solve(b);
	for(int i=0;i<3;i++)
		cout<<v1[i]<<" "<<v2[i]<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[]={5,4,5};
	int b[]={3,4,5};
	solver(a,b);
	return 0;
}
