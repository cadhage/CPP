#include <bits/stdc++.h>
using namespace std;
int dictionaryContains(string &word) 
{ 
    string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango", "icecream","and", 
                            "go","i","love","ice","cream"}; 
    int n = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < n; i++) 
        if (dictionary[i].compare(word) == 0) 
            return true; 
    return false; 
} 
void wordBreakUtil(string s,int n,string result){
	for(int i=1;i<=n;i++){
		string prefix=s.substr(0,i);
		if(dictionaryContains(prefix)){
		//	d//ictionaryContains
			if(i==n){
				result+=prefix;
				cout<<result<<endl;
				return;
			}
			wordBreakUtil(s.substr(i,n-i),n-i,result+prefix+" ");
		}
	}
}
void wordBreak(string s){
	wordBreakUtil(s,s.size(),"");
}
int main(){
	cout << "First Test:\n"; 
    wordBreak("iloveicecreamandmango"); 
	return 0;
}
