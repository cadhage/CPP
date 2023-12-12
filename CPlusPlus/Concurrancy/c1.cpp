#include <bits/stdc++.h>
using namespace std;
int doSomething(char c){
	std::default_random_engine dre();
	std::uniform_int_distribution<int> id(10,1000);
	for(int i=0;i<10;i++){
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	return c;	
}
int funct1(){
	return doSomething('.');
}
int funct2(){
	return doSomething('+');
}
int main(){
	std::future<int> result1(std::async(funct1));
	int result2=funct2();
	int result=result1.get()+result2;
	cout<<"\n func1()+funct2():"<<result<<'\n';
	return 0;
}
