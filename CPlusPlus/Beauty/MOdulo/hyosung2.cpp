#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void subString(string str, int n,vector<string> &mp)  
{ 
    // Pick starting point 
    for (int len = 1; len <= n; len++)  
    {     
        // Pick ending point 
        for (int i = 0; i <= n - len; i++)  
        { 
            //  Print characters from current 
            // starting point to current ending 
            // point.   
            int j = i
			 + len - 1; 
			string r="";            
            for (int k = i; k <= j; k++)  
            	r+=str[k];
            mp.push_back(r); 
              
            //cout << endl; 
        } 
    } 
} 
int calculate(string s){
	int count=0;
	for(char c:s){
		if(c=='a'||c=='e'||c=='o'||c=='u'||c=='I'||c=='A'||c=='E'||c=='O'||c=='U'||c=='u')
			count++;
	}
	return count;
}
int solver(string s){
	int count=0;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c=='a'||c=='e'||c=='o'||c=='u'||c=='I'||c=='A'||c=='E'||c=='O'||c=='U'||c=='u')
			count+= (s.size() - i) * (i+1);	
	}
//	count = (strlen - i) * (i+1
	return count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		string s;cin>>s;
		cout<<solver(s)<<'\n';
	}
	return 0;
}
