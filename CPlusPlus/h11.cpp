#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* getNode(int data){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}
void findSum(node *root,int &sum,int x){
	if(root==NULL)
		return;
	if((root->left && root->left->data==x) || 
		(root->right && root->right->data==x))
		sum+=root->data;
	findSum(root->left,sum,x);
	findSum(root->right,sum,x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node *root = getNode(4);           /*        4        */
    root->left = getNode(2);           /*       / \       */
    root->right = getNode(5);          /*      2   5      */
    root->left->left = getNode(7);     /*     / \ / \     */
    root->left->right = getNode(2);    /*    7  2 2  3    */
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
      
    int sum=0;
    findSum(root,sum,2);
    cout<<sum<<'\n';
	return 0;
}
