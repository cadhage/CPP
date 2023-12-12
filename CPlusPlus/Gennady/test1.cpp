#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//cin>>n;
	int a[3][3]={{2500,4000,3500},{4000,6000,3500},{2000,4000,2500}};
	int tempi=0,tempj=0;
	string icity[]={"Jaipur","Pune","Bangalore"};
	string jcity[]={"Delhi","Kerala","Mumabi"};
	for(int i=0;i<3;i++){
		int mn=INT_MAX;
		for(int j=0;j<3;j++){
			if(mn>a[i][j]){
				mn=a[i][j];
				tempi=i;
				tempj=j;	
			}
		}
		cout<<"Salespeople "<<(i+1)<<" should be start jurney from "<<
		icity[tempi]<<" to "<<jcity[tempj]<<" with minimum cost of "<<mn<<
		" Ruppees"<<'\n';
	}
	return 0;
}
