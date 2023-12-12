#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node *newNode(int data){
	node *temp=new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
int maxDepht(node *root){
	if(root==NULL)
		return 0;
	return 1+max(maxDepht(root->left),maxDepht(root->right));
}
struct node* start=NULL;
struct node* getnode(int val){
struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//int height(struct node* tempo){
//	if(tempo==NULL)
//	return 0;
//	int lh=height(tempo->left);
//	int rh=height(tempo->right);
//	int maxi=max(lh,rh);
//	return (maxi+1);
//}
int dia(struct node* tem){
	if(tem==NULL)
	return 0;
	int lht=maxDepht(tem->left);
	int rht=maxDepht(tem->right);
	int ldia=dia(tem->left);
	int rdia=dia(tem->right);
	return max((lht+rht+1),max(ldia,rdia));
}
int main() {
	int n,m;
	cin>>n>>m;
	start=getnode(m);
	struct node* ptr;
	char str[1000];
	while(--n){
		cin>>str>>m;
		ptr=start;
		int i=0;
		while(str[i]&&ptr)
		{
			if(str[i]=='L'){
				if(ptr->left==NULL)
					ptr->left=getnode(0);
				ptr=ptr->left;
			}
			else
			{
				if(ptr->right==NULL)
					ptr->right=getnode(0);
				ptr=ptr->right;
			}
			i++; 
		}
			ptr->data=m;
	}
	//int ans=
	cout<<dia(ptr)<<endl;
	return 0;
}
