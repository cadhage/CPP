// Driver code 
#include <bits/stdc++.h>
using namespace std;
struct node { 
    char data; 
    struct node* left; 
    struct node* right; 
}; 
struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
int search(char a[],int s,int e,int x){
	for(int i=s;i<=e;i++){
		if(a[i]==x)
			return i;
	}
} 
int preIndex=0;
node *buildTree(char in[],char pre[],int s,int e){
	
	if(s>e)
		return NULL;
	node *root=newNode(pre[preIndex++]);
	if(s==e)
		return root;
	int inIndex=search(in,s,e,root->data);
	root->left=buildTree(in,pre,s,inIndex-1);
	root->right=buildTree(in,pre,inIndex+1,e);
	return root;
}
void printInorder(node *root){
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
}
int main() 
{ 
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    struct node* root = buildTree(in, pre, 0, len - 1); 
  
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root); 
    getchar(); 
} 
