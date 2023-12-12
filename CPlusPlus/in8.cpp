#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
vector<string> a;
#define MAX 10000
void generateNumbersUtil(){
	queue<string> q;
	q.push("9");
	for(int i=MAX;i>=0;i--){
		string s1=q.front();
		q.pop();
		a.push_back(s1);
		string s2=s1;
		q.push(s1.append("0"));
		q.push(s2.append("9"));
	}
}
string findSmallestMultiple(int n){
	for(auto it:a){
		if(stoi(it)%n==0)
			return it;
	}
}  
int main() 
{ 
    generateNumbersUtil();     
    int n = 7;     
    cout << findSmallestMultiple(n);     
    return 0; 
} 
