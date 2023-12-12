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
void level(node *root){
	if(root==NULL)
		return;
	queue<node*> q;
	//node *a;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		root=q.front();
		q.pop();
		if(root==NULL)
		{
			q.push(NULL);
			cout<<'\n';
		}
		else{
			//cout<<root->data<<' ';
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
			cout<<root->data<<' ';	
		}
	}
}
void level_sp(node *root){
	if(root==NULL)
		return;
	stack<node*> a,b;
	a.push(root);
	while(!a.empty() || !b.empty()){
		while(!a.empty()){
			root=a.top();
			a.pop();
			cout<<root->data<<' ';
			if(root->right)
				b.push(root->right);
			if(root->left)
				b.push(root->left);	
		}
		cout<<'\n';
		while(!b.empty()){
			root=b.top();
			b.pop();
			cout<<root->data<<' ';
				if(root->left)
				a.push(root->left);
			if(root->right)
				a.push(root->right);
		}
		cout<<'\n';
	}
}
int main() 
{ 
	node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    level(root);
    cout<<"\n---------------------\n";
    level_sp(root);
    return 0; 
}
