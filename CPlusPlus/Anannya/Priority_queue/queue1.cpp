#include <bits/stdc++.h>
using namespace std;
void showpq(priority_queue<int> pq){
	priority_queue<int> p=pq;
	while(!p.empty()){
		cout<<'\t'<<p.top();
		p.pop();
	}
	cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	    priority_queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(30); 
    gquiz.push(20); 
    gquiz.push(5); 
    gquiz.push(1); 
  
    cout << "The priority queue gquiz is : "; 
    showpq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.top() : " << gquiz.top(); 
  
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showpq(gquiz); 
	return 0;
}
