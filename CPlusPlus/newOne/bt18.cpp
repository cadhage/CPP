#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right,*parent;
};
void inOrderStore(node* node,vector<int> &a) 
{ 
	if (node ==NULL) 
		return; 
	inOrderStore(node->left,a); 
	a.push_back(node->data);
	inOrderStore(node->right,a); 
} 
bool isPairPresent(node *node, int target) 
{ 
	vector<int> a2; 
	inOrderStore(node,a2); 
	int start = 0;
	int end = a2.size() - 1;
	while (start < end) { 
		if (a2[start] + a2[end] == target) // Target Found! 
		{ 
			cout<<"Pair Found: "<<a2[start]<<" + "<<a2[end] <<" "
				<< "= " <<target<<'\n'; 
			return true; 
		} 
		if (a2[start] + a2[end] > target) // decrements end 
		{ 
			end--; 
		} 
		if (a2[start] + a2[end] < target) // increments start 
		{ 
			start++; 
		} 
	} 
	return false; 
} 
node* NewNode(int val) 
{ 
	node* tmp = new node; 
	tmp->data = val; 
	tmp->right = tmp->left = NULL; 
	return tmp; 
} 
int main() 
{ 
	node* root = NewNode(15); 
	root->left = NewNode(10); 
	root->right = NewNode(20); 
	root->left->left = NewNode(8); 
	root->left->right = NewNode(12); 
	root->right->left = NewNode(16); 
	root->right->right = NewNode(25); 
	int target = 33; 
	if (isPairPresent(root, target)) 
		cout << "\nNo such values are found\n"; 
	return 0; 
}
