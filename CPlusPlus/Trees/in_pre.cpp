#include <bits/stdc++.h>
using namespace std;
int preIndex=0;
void printPost(int in[],int pre[],int s,int e,map<int,int> hm,int &index,stack<int> &st){
	    if (s >e|| index<0)  
        	return; 
		int val=pre[index];           
        int inIndex = hm[pre[index]];
		index--;   
        printPost(in, pre,inIndex+1,e, hm,index,st);    
        printPost(in, pre,s, inIndex-1, hm,index,st);
		st.push(val);   
}
void printPostOrder(int in[],int pre[],int n){
	map<int,int> hm;
	for(int i=0;i<n;i++){
		hm.insert({in[i],i});
	}
	int index=n-1;
	stack<int> s;
	printPost(in,pre,0,n-1,hm,index,s);
	while (s.empty() == false){
        cout<<s.top()<<" "; 
		s.pop();
	}
}
int main() 
{ 
        int in[] = { 4, 10, 12, 15, 18, 22, 24, 25, 
                     31, 35, 44, 50, 66, 70, 90 }; 
        int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 
                       44, 35, 66, 90, 70, 50, 25 };
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, post, n); 
    return 0; 
} 
