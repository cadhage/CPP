#include <bits/stdc++.h>
using namespace std;
void findPostOrder(int a[],int n,int mn,int mx,int &index)
{
	if(index==n)
		return;
	if(a[index]<mn ||a[index]>mx)
		return;
	int val=a[index];
	index++;
	findPostOrder(a,n,mn,val,index);
	findPostOrder(a,n,val,mx,index);
	cout<<val<<' ';
}
int main(){
	int pre[] = { 40, 30, 35, 80, 100 }; 
  
    int n = sizeof(pre) / sizeof(pre[0]); 
  
    // Calling function 
    int index=0;
    findPostOrder(pre, n,INT_MIN,INT_MAX,index); 
	return 0;
}
