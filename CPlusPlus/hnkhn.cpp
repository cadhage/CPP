/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
bool compare(auto  &a ,auto &b){
	return a>b;
}
int main()
{
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int var;cin>>var;
		a.push_back(var);
	}
	int x,y;cin>>x>>y;
	vector<int>::iterator it1=a.begin();
	vector<int>::iterator it2=a.begin(); 
	advance(it1,x-1);
	advance(it2,y);
	//cout<<*it1<<" "<<*it2;
	a.erase(it1,it2);
	cout<<a.size()<<"\n";
	for(auto &i:a)
		cout<<i<<" ";
	//Write code here
}

