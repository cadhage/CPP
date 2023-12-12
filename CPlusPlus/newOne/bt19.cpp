#include <bits/stdc++.h>
using namespace std;
struct node{
	node *left,*right;
	int data;
	bool l_thread,r_thread;	
};
node *insert(node *root,int k){
	node *a=root;
	node *parent=NULL;
	while(a!=NULL){
		if(k==(a->data)){
			cout<<"Duplicate";
			return root;
		}
		parent=a;
		if(k<a->data){
			if(a->l_thread==false)
				a=a->left;
			else break;
		}
		else
        { 
            if (a->r_thread == false) 
                a = a -> right; 
            else
                break; 
        } 
    } 
    node *tmp = new node; 
    tmp -> data = k; 
    tmp -> l_thread = true; 
    tmp ->r_thread = true; 
  
    if (parent == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (k< (parent -> data)) 
    { 
        tmp -> left = parent -> left; 
        tmp -> right = parent; 
        parent -> l_thread = false; 
        parent -> left = tmp; 
    } 
    else
    { 
        tmp -> left = parent; 
        tmp -> right = parent -> right; 
        parent -> r_thread = false; 
        parent -> right = tmp; 
    } 
  
    return root; 
}
struct node *inorderSuccessor(struct node *ptr) 
{ 
    // If rthread is set, we can quickly find 
    if (ptr -> r_thread == true) 
        return ptr->right; 
  
    // Else return leftmost child of right subtree 
    ptr = ptr -> right; 
    while (ptr -> l_thread == false) 
        ptr = ptr -> left; 
    return ptr; 
} 
  
// Printing the threaded tree 
void inorder(struct node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
  
    // Reach leftmost node 
    struct node *ptr = root; 
    while (ptr -> l_thread == false) 
        ptr = ptr -> left; 
  
    // One by one print successors 
    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> data); 
        ptr = inorderSuccessor(ptr); 
    } 
} 
int main(){
    struct node *root = NULL; 
    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 
    inorder(root); 
    return 0;
}
