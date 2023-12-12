#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
struct node 
{ 
    int data; 
    node *left, *right; 
}; 
node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void printSpiral(node *root){
	if(root==NULL)
		return;
	stack<node *> a,b;
	a.push(root);
	while(!a.empty() || !b.empty()){
		while(!a.empty()){
			node *temp=a.top();
			cout<<temp->data<<' ';
			a.pop();
			if(temp->right)
				b.push(temp->right);
			if(temp->left)
				b.push(temp->left);
		}
		cout<<'\n';
		while(!b.empty()){
			node *temp=b.top();
			cout<<temp->data<<' ';
			b.pop();
			if(temp->left)
				a.push(temp->left);
			if(temp->right)
				a.push(temp->right);
		}
		cout<<'\n';
	}
}  
int main() 
{ 
	node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout << "Spiral Order traversal of binary tree is \n"; 
    printSpiral(root);
    return 0; 
}
