#include <bits/stdc++.h>
#include <regex>
#include <iomanip>
using namespace std;
int main(){
	try{
	string pat1=R"(\\.*index\{([^}]*)\})";
	string pat2=R"(\\.*index\{(.*)\}\{(.*)\})";
	string s=pat1+"\n"+pat2;
	regex pat(s,
		regex_constants::egrep|regex_constants::icase);
	string data((istreambuf_iterator<char>(cin)),
		istreambuf_iterator<char>());
	smatch m;
	auto pos=data.cbegin();
	auto end=data.cend();
	for(;regex_search(pos,end,m,pat);pos=m.suffix().first){
		cout<<m.str()<<'\n'<<m.str(1)<<'\n'<<m.str(2)<<'\n';
	}}
	catch(const regex_error& e){
		cerr<<"regex_error: \n"<<"what(): "<<e.what()<<'\n'
		<<"code():"<<e.code()<<"\n";
	}
	return 0;
}
