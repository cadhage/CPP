#include <bits/stdc++.h>
using namespace std;
int solver(int a[],int n){
	stack<int> st;
	int max_area=0;
	int tp;
	int area_with_top;
	int i=0;
	while(i<n){
		if(st.empty()||a[st.top()]<=a[i])
			st.push(i++);
		else{
			tp=st.top();
			st.pop();
			area_with_top = a[tp] * (st.empty() ? i :  
                                   i - st.top() - 1); 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
		}
	}
	  while (st.empty() == false) 
    { 
        tp = st.top(); 
        st.pop(); 
        area_with_top =a[tp] * (st.empty() ? i :  
                                i - st.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<solver(a,n);
	return 0;
}               
