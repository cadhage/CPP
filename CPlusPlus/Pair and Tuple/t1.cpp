#include <bits/stdc++.h>
#include <regex>
#include <iomanip>
using namespace std;
int main(){
	tuple<int,int,double,string> t{1,3,1.3,"hello"};
	cout<<get<2>(t)<<'\n';
	return 0 ;
}
