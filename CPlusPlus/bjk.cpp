#include <bits/stdc++.h>
using namespace std;
bool isInterLived(string a,string b,string c){
	int m=a.length(),n=b.length();
	bool IL[m+1][n+1];
	if(m+n!=c.length())
		return false;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0&& j==0)
				IL[i][j]=true;
			else if(i==0 && b[j-1]==c[j-1])
				IL[i][j]=IL[i][j-1];
			else if(j==0 && a[i-1]==c[i-1])
				IL[i][j]=IL[i-1][j];
			else if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
				IL[i][j]=IL[i-1][j];
			else if(a[i-1]!=c[i+j-1]&& b[j-1]==c[i+j-1])
				IL[i][j]=IL[i][j-1];
			else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
				IL[i][j]=IL[i-1][j]||IL[i][j-1];
			}
		}
	return IL[m][n];
}
void test(string a,string b,string c){
	cout<<isInterLived(a,b,c)<<endl;
}
int main(){
	 test("XXY", "XXZ", "XXZXXXY"); 
    test("XY" ,"WZ" ,"WZXY"); 
    test ("XY", "X", "XXY"); 
    test ("YX", "X", "XXY"); 
    test ("XXY", "XXZ", "XXXXZY"); 
}
