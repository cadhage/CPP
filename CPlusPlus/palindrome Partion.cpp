#include <bits/stdc++.h>
using namespace std;
bool checkPal(char str[],int l,int r){
	if(r%2==0 ){
		while(l<=r){
		if(str[l]==str[r]){
			l++;r--;
		}
		else return false;
	}}
	else{
		while(l<r){
		if(str[l]==str[r]){
			l++;r--;
		}
		else return false;
	}}
	return true;
}
int minPalPartition(char str[],int l,int r){
	if(l==r)
		return 0;
	if(checkPal(str,l,r))
		return 0;
	int res=INT_MAX;
	for(int k=l;k<r;k++)
		res=min(res,(minPalPartition(str,l,k)+minPalPartition(str,k+1,r)+1));
	return res;
}
int main(){
	char str[]="ababbbabbababa";
	int n=strlen(str);
	cout<<minPalPartition(str,0,n-1);
	return 0;
}
