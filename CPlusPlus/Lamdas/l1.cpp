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
	auto greet_john_doe([]{
	cout<<"hello, John\n";});
	greet_john_doe();
	auto one([](){
		return 1;
	});
	auto two([]{
		return 2;
	});
	cout<<one()<<" "<<two()<<"\n";
	auto plus([](auto l,auto r){
		return l+r;
	});
	cout<<plus(4,5)<<'\n';
	cout<<plus(string{"hello"},"world")<<'\n';
	cout<<[](auto a,auto b){
		return a+b;
	}(4,10)<<'\n';
	auto counter([count=0]() mutable{
		return ++count;
	});
	for(size_t i{0};i<5;i++){
		cout<<counter()<<' ';
	}
	cout<<'\n';
	int a{0};//a=0;
	auto increamrnt([&a]{
	++a;});
	increamrnt();
	increamrnt();
	increamrnt();
	cout<<a<<'\n';
	auto plus_10([=](auto x){
		return plus(x,10);	
	});
	cout<<plus_10(10)<<'\n';
	return 0;
}
