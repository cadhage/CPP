#include <bits/stdc++.h>
using namespace std;
template <typename C> 
static auto consumer(C &container){
		return [&](auto value){
			container.push_back(value);
		};
	}
template <typename C> 
static void print(const C &c){
		for(auto it:c){
			cout<<it<<", ";
		}
		cout<<'\n';
	}
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
	deque<int> d;list<int> l;vector<int> v;
	const std::vector<std::function<void(int)>> consumers
	{
		consumer(d),consumer(l),consumer(v)
	};
	for(size_t i{0};i<10;i++){
		for(auto &&consume:consumers){
			consume(i);
		}
	}
	print(d);
	print(l);
	print(v);
	return 0;
}
