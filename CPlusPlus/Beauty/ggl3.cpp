#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *newNode(int data){
	node *temp=new node;
	temp->next=NULL;
	temp->data=data;
	return temp;
}
void printList(node *root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root=root->next;
	}
}
bool findList(node *first,node *second){
	node *temp1=first,*temp2=second;
	if(temp1==NULL && temp2==NULL){
		return true;
	}
	if(first==NULL||(first!=NULL && second==NULL)){
		return false;
	}
	while(second!=NULL){
		temp2=second;
		while(temp1!=NULL){
			if(temp2==NULL)
				return false;
			else if(temp1->data==temp2->data){
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else break;
		}
		if(temp1==NULL)
			return true;
		temp1=first;
		second=second->next;
	}
	return false;
}
int main(){
	node *a = newNode(1); 
    a->next = newNode(2); 
    a->next->next = newNode(3); 
    a->next->next->next = newNode(4); 
  
    node *b = newNode(1); 
    b->next = newNode(2); 
    b->next->next = newNode(1); 
    b->next->next->next = newNode(2); 
    b->next->next->next->next = newNode(3); 
    b->next->next->next->next->next = newNode(4); 
  
    findList(a,b) ? cout << "LIST FOUND" : 
                    cout << "LIST NOT FOUND"; 
	return 0;
}
