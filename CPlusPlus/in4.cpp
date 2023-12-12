#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
struct node 
{ 
    ll data; 
    node *left, *right; 
};
node* newNode(ll data) 
{
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}
void printLevelOrder(node *root){
	if(root==NULL)
		return;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		cout<<root->data<<' ';
		q.pop();
		if(root->left!=NULL){
			q.push(root->left);
		}
		if(root->right!=NULL){
			q.push(root->right);
		}
	} 
}
int main() 
{ 
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    return 0; 
}
