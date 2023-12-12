#include <bits/stdc++.h>
using namespace std;
vector<int> adj2[10000];
void solver(int n){
	unordered_map<int,int> e_count;
	for(int i=0;i<n;i++){
		e_count[i]=adj2[i].size();
	}
	if(n==0){
		return;
	}
	stack<int> st;
	vector<int> cir;
	st.push(0);
	int c_v=0;
	while(!st.empty()){
		if(e_count[c_v]){
			st.push(c_v);
			int next_v=adj2[c_v].back();
			e_count[c_v]--;
			adj2[c_v].pop_back();
			c_v=next_v;
		}else{
			cir.push_back(c_v);
			c_v=st.top();
			st.pop();
		}
	}
	for(int i=cir.size()-1;i>=0;i--){
		cout<<cir[i];
		if(i){
			cout<<"->";
		}
	}
}
int main(){
	int n=7;
   	adj2[0].push_back(1); 
    adj2[0].push_back(6); 
    adj2[1].push_back(2); 
    adj2[2].push_back(0); 
    adj2[2].push_back(3); 
    adj2[3].push_back(4); 
    adj2[4].push_back(2); 
    adj2[4].push_back(5); 
    adj2[5].push_back(0); 
    adj2[6].push_back(4); 
   // cout << "Coloring of graph 1 \n"; 
    solver(n);
	return  0;
}
