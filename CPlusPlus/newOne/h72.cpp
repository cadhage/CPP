#include <bits/stdc++.h> 
using namespace std; 
struct Node{
	struct Node* left, *right;
	int key,freq;
};
struct dataFreq{
	int data,freq;
};
struct Node* newNode(int d){
	struct Node* temp=new Node;
	temp->key=d;
	temp->left=temp->right=NULL;
	return temp;
}
void storeSorted(Node* root,int a[],int &i){
	if(root!=NULL){
		storeSorted(root->left,a,i);
		a[i++]=root->key;
		storeSorted(root->right,a,i);
	}
}
Node* insert(Node* node,int key){
	if(node==NULL)
		return newNode(key);
	if(key<node->key)
		node->left=insert(node->left,key);
	else if(key>node->key)
		node->right=insert(node->right,key);
	return node;
}
void treeSort(int a[],int n){
	struct Node *root=NULL;
	root=insert(root,a[0]);
	for(int i=1;i<n;i++){
		insert(root,a[i]);
	}
	int i=0;
	storeSorted(root,a,i);
		dataFreq count[n];
	sort(count,count+n,[&](auto a,auto b){
		return b.freq-a.freq; 
	});
	int j=0;
	for(int i=0;i<n;i++){
		for(int freq=count[i].freq;freq>0;freq--){
			a[j--]=count[i].data;
		}
	}
}
int main() 
{ 
	int a[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 
	treeSort(a, n); 
	cout << "Sorted array: \n"; 
	for(auto it:a){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

