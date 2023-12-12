#include <bits/stdc++.h>
using namespace std;
void modulo(int a,int b,int c){
	cout<<"Equation "<<"          "<<" Result "<<'\n';
	cout<<"(a+b)%c = "<<(a+b)%c<<"    ";
	cout<<"(a%c+b%c)%c = "<<(a%c+b%c)%c<<"\n";
	cout<<"(a*c)%c = "<<(a*b)%c<<"    ";
	cout<<"(a%c*b%c)%c = "<<((a%c)*(b%c))%c<<"\n";
	cout<<"(a/b)%c = "<<(a/b)%c<<"    ";
	cout<<"(a%c/(b)-1%c)%c = "<<(a%c+(int)pow(b,-1)%c)%c<<"\n";
	cout<<"(a-b)%c = "<<(a-b)%c<<"    ";
	cout<<"(a%c-b%c+c)%c = "<<(a%c-b%c+c)%c<<"\n";
}
int  main(){
	int a=12,b=15,c=4;
	cout<<a<<" "<<b<<" "<<c<<"\n";
	modulo(a,b,c);
	return 0;
}
