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
	bool found=regex_search(data,m,regex("<(.*)>.*</(\\1)>"));
	regex re("<(.*)>([^>]*)</(\\1)>");
	auto pos=data.cbegin();
	auto end=data.cend();
	for(;regex_search(pos,end,m,re);pos=m.suffix().first){
		cout<<m.str()<<'\n'<<m.str(1)<<'\n'<<m.str(2)<<'\n';
	}
	return 0;
}
