#include <bits/stdc++.h>
using namespace std;
	string myToupper(string str){
	transform(str.begin(), str.end(),str.begin(), ::toupper);
}
int main(){
	string s="hjfljlkvhjvjk ghvjk";
	for_each(s.begin(),s.end());
	return 0;
}
