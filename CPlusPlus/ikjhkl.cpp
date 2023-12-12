#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
	return (c=='-'|| c=='+'|| c=='/' || c=='*');
}
vector<int> solver(string s,map<string,vector<int>> memo){
	if(memo.find(s)!=memo.end()){
		return memo[s];
	}
	vector<int> res;
	for(int i=0;i<s.size();i++){
		if(isOperator(s[i])){
			vector<int> resPre=
				solver(s.substr(0,i),memo);
			vector<int> resSuf=
				solver(s.substr(i+1),memo);
			for(int j=0;j<resPre.size();j++){
				for(int k=0;k<resSuf.size();k++){
					if(s[i]=='+')
						res.push_back(resPre[j]+resSuf[k]);
					if(s[i]=='/')
						res.push_back(resPre[j]/resSuf[k]);
					if(s[i]=='*')
						res.push_back(resPre[j]*resSuf[k]);
					if(s[i]=='-')
						res.push_back(resPre[j]-resSuf[k]);
				}
			}
		}
	}
	if(res.size()==0)
	res.push_back(atoi(s.c_str()));
	memo[s]=res;
	return res;
}
vector<int> possibleResult(string s){
	map<string,vector<int>> memo;
	return solver(s,memo);
}
int main(){
	string s="5*4-3*2";
	vector<int> res=possibleResult(s);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	return 0;
}

