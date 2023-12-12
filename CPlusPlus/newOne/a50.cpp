#include <bits/stdc++.h>
using namespace std;
int smallestSubWithSum(int a[],int n,int x){
	int min_len=n+1;
	int s=0,e=0;
	int curr_sum=0;
	while(e<n){
		while(curr_sum<=x && e<n){
			if(curr_sum<=0 && x>0){
				s=e;
				curr_sum=0;
			}
			curr_sum+=a[e++];
		}
		while(curr_sum>x && s<n){
			if(e-s<min_len);
				min_len=e-s;
			curr_sum-=a[s++];
		}
	}
	return min_len;
}
int main(){
	int a[]={1,4,45,6,10,19};
	int x=51;
	cout<<smallestSubWithSum(a,6,x)<<'\n';
	return 0;
} 
