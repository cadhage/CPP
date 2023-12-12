#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
string d[]={"GEEKS","FOR","QUIZ","GO"};
int nn=sizeof(d)/sizeof(d[0]);
bool isWord(string &s){
	for(int i=0;i<nn;i++){
		if(s.compare(d[i])==0){
			return true;
		}
	}
	return false;
}
void findWordsUnit(char a[][MAX],bool v[][MAX],int i,int j,string &s,int n){
	v[i][j]=1;
	s+=a[i][j];
	if(isWord(s)){
		cout<<s<<'\n';
	}
	for(int r=i-1;r<=i+1&&r<n;r++){
		for(int c=j-1;c<=j+1&&c<n;c++){
			if(r>=0 &&c>=0 &&!v[r][c]){
				findWordsUnit(a,v,r,c,s,n);
			}
		}
	}
	s.erase(s.size()-1);
	v[i][j]=false;
}
void findWord(char a[][MAX],int n){
	bool v[][MAX]={{0}};
	string s="";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			findWordsUnit(a,v,i,j,s,n);
		}
	}
}
int main() 
{ 
    char boggle[][MAX] = { { 'G', 'I', 'Z' }, 
                          { 'U', 'E', 'K' }, 
                          { 'Q', 'S', 'E' } }; 
  
    cout << "Following words of dictionary are present\n"; 
    findWord(boggle,3); 
    return 0; 
} 

