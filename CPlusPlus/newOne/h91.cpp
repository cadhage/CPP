#include <bits/stdc++.h>
using namespace std;
//int find(int a[],int x,int n){
//	for(int i=0;i<n;i++)
//		if(a[i]==x)
//			return i;
//	return -1;
//}
void printPostOrder(int in[],int pre[],int n){
	int root=binary_search(in,in+n,pre[0]);
	if(root==-1)
		return;
	if(root!=0){
		printPostOrder(in,pre+1,root);
	}
	if(root!=n-1){
		printPostOrder(in+root+1,pre+root+1,n-root-1);
	}
	cout<<pre[0]<<' ';
}
int main(){
	int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, pre, n); 
	return 0;
}
