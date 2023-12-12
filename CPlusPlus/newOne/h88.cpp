#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node* root=new node;
	root->left=root->right=NULL;
	root->data=data;
}
bool hasOnlyOneChild(int a[],int n){
	int nextDiff,lastDiff;
	for(int i=0;i<n-1;i++){
		nextDiff=a[i]-a[i+1];
		lastDiff=a[i]-a[n-1];
		if(nextDiff*lastDiff<0)
			return false;	
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pre[] = {8, 3, 5, 7, 6}; 
    int size = sizeof(pre)/sizeof(pre[0]); 
    if (hasOnlyOneChild(pre, size) == true ) 
        printf("Yes"); 
    else
        printf("No"); 
	return 0; 
}
