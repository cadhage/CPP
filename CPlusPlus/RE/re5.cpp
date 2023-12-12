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
	cout<<regex_replace(data,re,"<$1 value=\"$2\"/>")<<"\n";
	cout<<regex_replace(data,re,"<\\1 value=\"\\2\"/>", regex_constants::format_sed)<<"\n";
	string reg2;
	regex_replace(back_inserter(reg2),data.begin(),data.end(),re,"<$1 value=\"$2\"/>",regex_constants::format_no_copy|regex_constants::format_first_only);
	cout<<reg2<<'\n';
	return 0;
}
