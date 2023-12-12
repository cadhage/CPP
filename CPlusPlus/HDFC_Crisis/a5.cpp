#include <bits/stdc++.h>
using namespace std;
void mySTRcpy(char c1[],char c2[],int index=0){
	c2[index]=c1[index];
	if(c1[index]=='\0')
		return;
	mySTRcpy(c1,c2,index+1);
}
int main(){
	char c1[1000]="Chandrashekhar";
	char c2[1000]="";
	mySTRcpy(c1,c2);
	cout<<c2;
	return 0;
}
