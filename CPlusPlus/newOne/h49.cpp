#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
const int MAXS=500;
const int MAXC=26;
int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];
int builtMatchingMachine(string a[],int k){
	memset(out,0,sizeof out);
	memset(g,-1,sizeof g);
	int state=1;
	for(int i=0;i<k;i++){
		const string &word=a[i];
		int currState=0;
		for(int j=0;j<word.size();j++){
			int ch=word[j]-'a';
			if(g[currState][ch]==-1){
				g[currState][ch]=state++;
			}
			currState=g[currState][ch];
		}
		out[currState]|=(1<<i);
	}
	for(int ch=0;ch<MAXC;ch++){
		if(g[0][ch]==-1){
			g[0][ch]=0;
		}
	}
	memset(f,-1,sizeof f);
	queue<int> q;
	for(int ch=0;ch<MAXC;ch++){
		if(g[0][ch]!=0){
			f[g[0][ch]]=0;
			q.push(g[0][ch]);
		}
	}
	while(q.size()){
		int state=q.front();
		q.pop();
		for(int ch=0;ch<=MAXC;ch++)
		{
			if(g[state][ch]!=-1){
				int failure=f[state];
				while(g[failure][ch]==-1){
					failure=f[failure];
				}
				failure =g[failure][ch];
				f[g[state][ch]]=failure;
				out[g[state][ch]]|=out[failure];
				q.push(g[state][ch]);
			}
		}
	}
	return state;
}
int  findNextState(int currState,char nextInput){
	int ans=currState;
	int ch=nextInput-'a';
	while(g[ans][ch]==-1){
		ans=f[ans];
	}
	return g[ans][ch];
}
void searchWords(string a[],int k,string txt){
	builtMatchingMachine(a,k);
	int curState=0;
	for(int i=0;i<txt.size();i++){
		curState=findNextState(curState,txt[i]);
		if(out[curState]==0){
			continue;
		}
		for(int j=0;j<k;j++){
			if(out[curState]&(1<<j)){
				cout<<"Word"<<a[j]<<"from "<<
				i-a[j].size()+1<<" to "<<i<<'\n';
			}
		}
	}
}
int main(){
	string arr[] = {"he", "she", "hers", "his"}; 
    string text = "ahishers"; 
    int k = sizeof(arr)/sizeof(arr[0]); 
   	searchWords(arr,k,text);
	return 0;
}
