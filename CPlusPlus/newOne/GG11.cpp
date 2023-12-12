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
void printInorder(node* node) 
{ 
    if (node == NULL) 
       return; 
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
} 
int search(char a[],int s,int e,int x){
	for(int i=s;i<=e;i++){
		if(a[i]==x)
			return i;
	}
}
int* extractKeys(int in[],int level[],int m,int n){
	int newLeve[m],j=0;
	for(int i=0;i<n;i++){
		if(search(in,0,m-1,level[i])!=-1)
			newLevel[j]=level[i],j++;
	}
	return newLevel;
}
node *buitdTree(int in[],int level[],int s,int e,int n){
	static l_Index=0;
	if(s>e)
		return NULL;
	node *root=level[0];
	if(s==e)
		return root;
	int inIndex=search(in,s,e,root->data);
	int l[]=extractKeys(in,level,inIndex,n);
	int r[]=extractkeys(in+inIndex+1,level,n-inIndex-1,n);
	root->left=buildTree(in,l,s,inIndex-1,n);
	root->right=buildTree(in,r,inIndex+1,e,n);
	return root;
}
int main() 
{ 
    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14}; 
    int n = sizeof(in)/sizeof(in[0]); 
    Node *root = buildTree(in, level, 0, n - 1, n); 
  
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root); 
  
    return 0; 
} 
