#include <bits/stdc++.h>
using namespace std;
void CountTriangles(vector<int> a){
	int count=0,n=a.size();
	for(int i=n-1;i>=0;i--){
		int l=0,r=i-1;
		while(l<r){
			if(a[l]+a[r]>a[i]){
				count+=r-l;
				r--;
			}
			else l++;
		}
	}
	cout<<count<<'\n';
}
int main(){ 
    vector<int> A = {10, 21, 22, 100, 101, 200, 300};  
    CountTriangles(A); 
    return 0;
} 
