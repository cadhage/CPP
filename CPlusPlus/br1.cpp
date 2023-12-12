#include <bits/stdc++.h>
using namespace std;
bool solver(string s) 
{ 
 	stack<char> st; 
    char x; 
    for (int i=0; i<s.length(); i++) 
    { 
        if (s[i]=='('||s[i]=='['||s[i]=='{') 
        { 
            st.push(s[i]); 
            continue; 
        }  
        if (st.empty()) 
           return false; 
        switch (s[i]) 
        { 
	        case ')': 
	            x = st.top(); 
	            st.pop(); 
	            if (x=='{' || x=='[') 
	                return false; 
	            break; 
	        case '}': 
	            x = st.top(); 
	            st.pop(); 
	            if (x=='(' || x=='[') 
	                return false; 
	            break; 
	        case ']': 
	            x = st.top(); 
	            st.pop(); 
	            if (x =='(' || x == '{') 
	                return false; 
	            break; 
        } 
    } 
    return (st.empty());  
}  
int main(){
    string expr = "(a[0]+b[2c[6]]{24+53})"; 
    if (solver(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
}
