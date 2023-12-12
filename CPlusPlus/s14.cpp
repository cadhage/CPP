#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int d, x, y;
void extendedEuclid(int a,int b) {
	if(b==0){
		d=a;
		x=1;
		y=0;
	}
    else {
        extendedEuclid(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}
int solver(int A, int M)
{
	//int x,y,d;
    extendedEuclid(A,M);
    cout<<d<<' ';
    return (x%M+M)%M;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<solver(2,11);
	return 0;
}
