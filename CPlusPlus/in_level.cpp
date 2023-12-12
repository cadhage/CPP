#include <bits/stdc++.h>
using namespace std;
struct node{
	char x;
	node *left,*right;
};
node *newNode(char t){
	node *temp=new node;
	temp->x=t;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->x<<'\n';
	inorder(root->right);
}
int search(char a[],char x,int s,int e){
	for(int i=s;i<=e;i++)
		if(a[i]==x)
			return i;
	return -1;
}

node *buildTree(char in[],char pre[],int s,int e,int index){
	static int c=0;
	if(s>e)
		return NULL;
	node *root=newNode(pre[c++]);
	if(s==e)
		return root;
	int preIndex=search(in,root->x,s,e);
	root->left=buildTree(in,pre,s,preIndex-1,index+1);
	root->right=buildTree(in,pre,preIndex+1,e,index+1);
	return root;
}
int main()  
{  
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
    int len = sizeof(in) / sizeof(in[0]);  
    node* root = buildTree(in, pre, 0, len - 1,0);  
    cout << "Inorder traversal of the constructed tree is \n";  
    inorder(root);  
}  
