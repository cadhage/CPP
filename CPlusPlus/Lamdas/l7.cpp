#include <bits/stdc++.h>
using namespace std;
int main(){
	auto plus10times2=[](auto x){
		return (x+10)*2;
	};
	cout<<plus10times2(2)<<'\n';
	auto pow=[](auto x,auto n){
		auto mul=1;
		for(int i=0;i<n;i++)
			mul*=x;
		return mul;
	} ;
	vector<int> a={2,4,2,4,5,5};
	int sum=0;
	for_each(a.begin(),a.end(),[&sum](auto x){
		sum+=x;
	});
	cout<<pow(2,3)<<'\n';
	//cout<<sum<<'\n';
	double mv=static_cast<double>(sum)/static_cast<double>(a.size());
	cout<<sum<<'\n';
	int count=0;
	auto pos=remove_if(a.begin(),a.end(),[&count](auto ){
		return ++count==3;
	});
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<' ';
	} cout<<'\n';
	a.erase(pos,a.end());
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<' ';
	} cout<<'\n';
	return 0;
}
