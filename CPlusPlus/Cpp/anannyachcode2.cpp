/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node *newNode(int data){
    node *temp=new node;
    temp->left=temp->right=NULL;
    temp->data=data;
    return temp;
}
node *lca(node *root,int x,int y){
    if(root==NULL)
        return root;
    if(root->data<x && root->data<y)
        return lca(root->right,x,y);
    if(root->data>x && root->data>y)
        return lca(root->left,x,y);
    return root;
}
node *insert(node *root,int data){
    if(root==NULL)
        return newNode(data);
    if(root->data>data)
        root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}
int main()
{
    int n;cin>>n;
    int x;cin>>x;
    node *root=newNode(x);
    for(int i=1;i<n;i++){
        int data;cin>>data;
        root=insert(root,data);
    } 
    int a,b;cin>>a>>b;
    cout<<lca(root,a,b)->data<<'\n'; 
    return 0;
    //Write code here
}

