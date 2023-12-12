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
void digUtil(node *root,int sum,int len,int &maxLen,int &maxSum){
	if(!root)
	{
		if(maxLen<len)
		{
			maxLen=len;
			maxSum=sum;
		}else if(maxLen==len && maxSum<sum){
			maxSum=sum;
		}
		return;
	}
	digUtil(root->left,sum+root->data,len+1,maxLen,maxSum);
	digUtil(root->right,sum+root->data,len+1,maxLen,maxSum);
//}
//void addBT(node *root){
//	vector<int> dig;
//	digUtil(root,0,dig);
//	for(auto it:dig){
//		cout<<it<<'\n';
//	}
//}
}
int main(){
    node *root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6); 
    int maxSum=INT_MIN,maxLen=0;
	digUtil(root,0,0,maxLen,maxSum); 
	cout<<maxSum;
    //cout << "Sum of all the elements is: " << sum << endl; 
	return 0;
}
