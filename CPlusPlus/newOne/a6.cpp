#include <bits/stdc++.h>
using namespace std;
struct node{
	int val,level;
};
int minOperations(int x,int y)
{ 
    set<int> visit;
    queue<node*> q; 
  	node* a=new node;
  	a->val=x;a->level=0;
    q.push(a); 
    while(!q.empty()){
    	node* n=q.front();
    	q.pop();
    	if(n->val==y){
    		return n->level;
		}
		visit.insert(n->val);
		if(n->val*2==y||n->val-1==y)
			return n->level+1;
		if(visit.find(n->val*2)==visit.end()){
			a->val=n->val*2;
			a->level=n->level+1;
			q.push(a);
		}
		if(n->val-1>=0 && visit.find(n->val-1)==visit.end()){
			a->val=n->val-1;
			a->level=n->level+1;
			q.push(a);
		}
	}
} 
int main() 
{ 
    int x = 4, y = 7; 
    cout << minOperations(x, y); 
    return 0; 
}
