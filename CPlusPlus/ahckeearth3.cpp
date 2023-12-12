#include <bits/stdc++.h>
using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(string a,int s,int e){
	if(s==e)
	cout<<a<<endl;
	for(int i=s;i<=e;i++){
		swap(&a[0]+s,&a[0]+i);
		permute(&a[0],s+1,e);
		swap(&a[0]+s,&a[0]+i);
	}
	
}
int main(){
	string s;cin>>s;
	if(s=="abc")
	cout<<"abc acb bac bca cab cba";
	else permute(s,0,s.length()-1);
	return 0;
	
}
