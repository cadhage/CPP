#include <bits/stdc++.h>
using namespace std;
#define d 256
void Search(string pat,string txt,int q){
	int m=pat.size();
	int n=txt.size();
	int h=1,p=0,t=0;
	for(int i=0;i<m-1;i++)
		h=(d*h)%q;
	for(int i=0;i<m;i++){
		p=(d*p+pat[i])%q;
		t=(d*t+txt[i])%q;
	}
	for(int i=0;i<=n-m;i++){
		if(p==t){
			int j;
			for(j=0;j<m;j++){
				if(txt[i+j]!=pat[j]){
					break;
				}
			}
			if(j==m){
				cout<<"at"<<i<<'\n';
			}
		}
		if(i<n-m){
			t=(d*(t-txt[i]*h)+txt[i+m])%q;
			if(t<0){
				t=t+q;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string txt = "ABABDABACDABABCABAB"; 
   	string pat= "ABABCABAB"; 
   	Search(pat,txt,7);
	return 0;
}
