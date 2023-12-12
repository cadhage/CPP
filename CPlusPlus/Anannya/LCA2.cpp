#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right,*parent;
};
node *getNode(int data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->parent=temp->right=NULL;
	return temp;
}
node *insert(node *node,int key){
	if(node==NULL){
		return getNode(key);
	}
	if(key<node->data){
		node->left=insert(node->left,key);
		node->left->parent=node;
	}else if(key>node->data){
		node->right=insert(node->right,key);
		node->right->parent=node;
	}
	return node;
}
int depth(node *node){
	int d=-1;
	while(node){
		++d;
		node=node->parent;
	}
	return d;
}
node *LCA(node *n1,node *n2){
	int d1=depth(n1),d2=depth(n2);
	int diff=d1-d2;
	if(diff<0){
		node *temp=n1;
		n1=n2;
		n2 =temp;
		diff=-diff;
	}
	while(diff--){
		n1=n1->parent;
	}
	while(n1&&n2){
		if(n1==n2){
			return n1;
		}
		n1=n1->parent;
		n2=n2->parent;
	}
	return NULL;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    node *n1 = root->left->right->left; 
    node *n2 = root->right; 
  
    node *lca = LCA(n1, n2); 
    printf("LCA of %d and %d is %d \n", n1->data, n2->data, lca->data); 
  
    //return 0; 
    return 0; 
} 
