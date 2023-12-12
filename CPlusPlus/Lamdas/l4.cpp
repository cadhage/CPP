#include <bits/stdc++.h>
using namespace std;
int main(){
	/*
	[capture list](arguments)
	mutable //optional
	constexpr //optional
	exception attr //optional
	return type //optional
	{
		body;
	}
	*/
	int x;
	auto c1=[x](int y){
		return x*y>55;
	};
	cout<<c1;
	return 0;
}
