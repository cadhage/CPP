#include<bits/stdc++.h>
using namespace std;
void updateBIT(vector<int> &BITree,int n,int i,int x){
	i+=1;
	while(i<=n){
		BITree[i]+=x;
		i+=i&(-i);
	}
}
vector<int> constructBITree(int a[],int n){
	vector<int> BITree(n+1,0);
	for(int i=0;i<=n;i++)
		updateBIT(BITree,n,i,a[i]);
	return BITree;
}
void update(vector<int> &BITree,int l,int r,int n,int x){
	updateBIT(BITree,n,l,x);
	updateBIT(BITree,n,r+1,-x);
}
int getSum(vector<int> BITree,int i){
	int sum=0;
	i+=1;
	while(i>0){
		sum+=BITree[i];
		i-=i&(-i);
	}
	return sum;
}
int main(){
	int arr[] = {0, 0, 0, 0, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> BITree = constructBITree(arr, n); 
    int l = 2, r = 4, val = 2; 
    update(BITree, l, r, n, val); 
    int index = 4; 
    cout << "Element at index " << index << " is " << 
         getSum(BITree,index) << "\n"; 
    l = 0, r = 3, val = 4; 
    update(BITree, l, r, n, val); 
    index = 3; 
    cout << "Element at index " << index << " is " << 
         getSum(BITree,index) << "\n" ; 
	return 0;
}
