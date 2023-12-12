#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *getNode(int x){
	node *temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}
int sum=0;
void addBT(node *root,int x){
	if(root==NULL)
		return;
	if((root->left&&root->left->data==x)||
		(root->right && root->right->data==x))
			sum+=root->data;
	addBT(root->left,x);
	addBT(root->right,x);
}
int main(){
    node *root = getNode(4);           /*        4        */
    root->left = getNode(2);           /*       / \       */
    root->right = getNode(5);          /*      2   5      */
    root->left->left = getNode(7);     /*     / \ / \     */
    root->left->right = getNode(2);    /*    7  2 2  3    */
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
    //int sum = 
	addBT(root,2); 
    cout << "Sum of all the elements is: " << sum << endl; 
	return 0;
}
