#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	int data,pos;
	node *left,*right;
};
node *newNode(int data,int pos){
	node *temp=new node;
	temp->data=data;
	temp->pos=pos;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(node *root,int data,int pos){
	if(root==NULL){
		node *temp=new node;
		temp->data=data;
		temp->pos=pos;
		temp->left=temp->right=NULL;
		cout<<temp->pos<<'\n';
		return temp;
	}
	root->left=insert(root->left,data,pos*2);
	root->right=insert(root->right,data,pos*2+1);
	cout<<pos<<'\n';
	return root;
}

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        cout<<root->pos<<'\n';
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++){
		char c;cin>>c;
		int x;cin>>x;
		if(c=='i')
			root=insert(root,x,1);
		if(c=='d');
		//	deleteNode(root,x);
	}
	return 0;
}
