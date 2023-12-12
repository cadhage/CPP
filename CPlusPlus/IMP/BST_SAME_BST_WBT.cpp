#include <bits/stdc++.h>
using namespace std;
bool isSameBST(int a[],int b[],int n,int i1,int i2,int mn,int mx){
	int i,j;
	for(i=i1;i<n;i++)
		if(a[i]>mn && a[i]<mx)
			break;
	for(j=i2;j<n;j++){
		if(b[j]>mn && b[j]<mx)
			break;
	}
	if(i==n &&j==n)
		return true;
	if(((i==n)^(j==n)||a[i]!=b[j]))
		return false;
	return 	isSameBST(a,b,n,i+1,j+1,a[i],mx)&&
			isSameBST(a,b,n,i+1,j+1,mn,a[i]);
}
int main(){
	
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};  
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};  
    int n=sizeof(a)/sizeof(a[0]);  
    if(isSameBST(a, b, n,0,0,INT_MIN,INT_MAX)) 
    { 
        cout << "BSTs are same"; 
    } 
    else
        cout<<"NOt Same";
	return 0;
}
