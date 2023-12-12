#include <bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
	return temp;
}
void printOddNodes(Node *root){
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);
	bool isOdd=true;
	while(true){
		int nodeCount=q.size();
		if(nodeCount==0)
			break;
		while(nodeCount>0){
			Node *node=q.front();
			if(isOdd)
				cout<<node->data<<' ';
			q.pop();
			if(node->left){
				q.push(node->left);
			}
			if(node->right)
				q.push(node->right);
			nodeCount--;
		}
		isOdd=!isOdd;
	}
}
int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    printOddNodes(root); 
	return 0;
}
