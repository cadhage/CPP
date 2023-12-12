#include <bits/stdc++.h>
using namespace std;
struct node { 
    char data; 
    struct node* left; 
    struct node* right; 
};
struct ListNode{
	int data;
	ListNode *next;
}; 
void push(ListNode *head,int data){
	ListNode *newNode=new ListNode;
	newNode->next=head;
	head=newNode;
}
struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
void printInorder(node* node) 
{ 
    if (node == NULL) 
       return; 
    printInorder(node->left); 
    cout << node->data << " ";
	printInorder(node->right); 
}
void convertList2Binary(ListNode *head,node *root){
	queue<node *> q;
	if(head==NULL)
	{
		root=NULL;
		return;
	}
	root=newNode(head->data);
	q.push(root);
	while(head){
		node *parent=q.front();
		q.pop();  
        node *leftChild = NULL, *rightChild = NULL; 
        leftChild = newNode(head->data); 
        q.push(leftChild); 
        head = head->next; 
        if (head) 
        { 
            rightChild = newNode(head->data); 
            q.push(rightChild); 
            head = head->next; 
        } 
        parent->left = leftChild; 
        parent->right = rightChild; 
	}
}
int main() 
{ 
    // create a linked list shown in above diagram 
  struct ListNode* head = NULL; 
    push(head, 36);  /* Last node of Linked List */
    push(head, 30); 
    push(head, 25); 
    push(head, 15); 
    push(head, 12); 
    push(head, 10);
    node *root; 
    convertList2Binary(head, root); 
    cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
    printInorder(root); 
    return 0; 
} 
