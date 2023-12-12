#include <bits/stdc++.h>
using namespace std;
void out(bool b){
	cout<<(b?"found":"not fount")<<'\n';
}
int main(){
	regex re1("<.*>.*</.*>");
	bool found=regex_match("<h1>Hello EvryOne</h1>",re1);
	out(found);
	regex re2("<(.*)>.*</\\1>");
	found=regex_match("<h1>Hello EvryOne</h1>",re1);
	out(found);
	regex re3("<\\(.*\\).*</\\1>",regex_constants::grep);
	found=regex_match("<h1>uygkihpo</h1>",re3);
	out(found);
	found=regex_match("<h1>goj</h1>",regex("<(.*)>.*<(/\\1)>"));
	out(found);
	found=regex_match("gijg<h1>fjkglk</h1>",regex("<(.*)>.*<(/\\1)>"));
	out(found);
	found=regex_search("hfiln<h1></h1>",regex("<(.*)>.*</\\1>"));
	out(found);
	return 0;
}
