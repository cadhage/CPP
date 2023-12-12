#include <bits/stdc++.h>
using namespace std;
bool function(string str){

        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<str.length();j++){
                string sub=str.substr(i, j+1);
                // sub is substring of s from ith to jth character 
                bool flag=true;
                for(int k=0;k<sub.length();k++){
                    if(sub[k]!=sub[sub.length()-k-1]){
                        flag=false;
                    }
                }
                if(flag) return false;
            }
        }
        return true;
}
int main(){
	string s; getline(cin,s);
	cout<<s[0]<<"."<<" ";
	int i=0;
	bool flag=false;
	for(i=1;i<s.length();i++){
		if(!flag && s[i-1]==' '){
			cout<<s[i]<<"."<<" ";
			flag=true;
		}
	}
	if(flag) {cout<<s.substr(i);
		flag=false;}
	cout<<s.substr(i);
	return 0;
	
}
