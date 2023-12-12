#include <bits/stdc++.h>
using namespace std;
int ceilIndex(vector<int> &a,int l,int r,int x){
	while(r-l>1){
		int m=l+(r-l)/2;
		if(a[m]>=x)
			r=m;
		else l=m;
	}
	return r;
}
int LongestIncreasingSubsequenceLength(vector<int> a){
	if(a.size()==0)
		return 0;
	vector<int> tail(a.size(),0);
	int length=1;
	tail[0]=a[0];
	for(int i=0;i<a.size();i++){
		if(a[i]<tail[0]){
			tail[0]=a[i];
		}
		else if(a[i]>tail[length-1])
			tail[length++]=a[i];
		else tail[ceilIndex(tail,-1,length-1,a[i])]=a[i];
	}
	return length;
}
int main() 
{ 
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
    std::cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v) << '\n'; 
    return 0; 
}
