#include <bits/stdc++.h>
using namespace std;
template <typename T>
void f(T &param){
	cout<<param<<'\n';
}
int main(){
	int x=27;
	const int cx=x;
	const int &rx=x;
	f(x);f(cx);f(rx);
	return 0;
}
