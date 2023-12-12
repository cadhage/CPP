#include <bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    	cin>>a[i];
    int c=0;
    for(int i=0;i<n;i++){
    	if(m>=a[i]){
    		c++;
    		m=m-a[i];
    		if(m==0){
    			m=a[i];
			}
			else if(m<0)
				break;
		}
		else break;
	}
	cout<<c+1;
	return 0;
}
