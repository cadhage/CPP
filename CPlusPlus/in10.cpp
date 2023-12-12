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
void inorder(node *root){
	stack<node*> s;
	node *a=root;
	while(a!=NULL || s.empty()){
		while(a!=NULL){
			s.push(a);
			a=a->left;
		}
		a=s.top();
		s.pop();
		cout<<a->data<<' ';
		a=a->right;
	}
		
}
int main() 
{ 
	node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    inorder(root);
    return 0; 
}
