#include <bits/stdc++.h>
#include <regex>
#include <iomanip>
using namespace std;
int main(){
	string data="<person>\n"
				"<first>Nico</first>\n"
				"<last>Josuttis</last>\n"
				"</person>\n";
	smatch m;
	regex re("<(.*)>(.*)</(\\1)>");
	sregex_iterator pos(data.cbegin(),data.cend(),re);
	sregex_iterator end;
	for(;pos!=end;++pos){
		cout<<pos->str()<<'\n'<<pos->str(1)<<'\n'<<pos->str(2)<<'\n';
	}
	cout<<"....\n....\n....\n";
	sregex_iterator beg(data.cbegin(),data.cend(),re);
	for_each(beg,end,[](const smatch&m){
		cout<<m.str()<<'\n'<<m.str(1)<<'\n'<<m.str(2)<<'\n';
	});
	sregex_token_iterator pos1(data.cbegin(),data.cend(),re,{0,2});
	sregex_token_iterator end1;
		cout<<"....\n....\n....\n";
	for(;pos1!=end1;++pos1){
		cout<<pos1->str()<<'\n';
	}
	regex reg("[\t\n]*[,;. ][\t\n]*");
	string name=" nico, jim,hrl,paul,tim;john,pal,rita";
	sregex_token_iterator p(name.cbegin(),name.cend(),reg,-1);
	sregex_token_iterator e;
		cout<<"....\n....\n....\n";
	for(;p!=e;++p){
		cout<<*p<<'\n';
	}
	return 0;
}
