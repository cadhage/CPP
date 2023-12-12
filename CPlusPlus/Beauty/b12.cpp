#include <bits/stdc++.h>
using namespace std;
void firstFit(vector<int> block,vector<int> processSize,int m,int n){
	vector<int> allocation(n,-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(block[j]>=processSize[i]){
				allocation[i]=j;
				block[j]-=processSize[i];
				break;
			}
		}
	}
	cout<<"\n Procces Number\tProcess Size\t"
	"block Number\n"<<'\n';
	for(int i=0;i<n;i++){
		cout<<" "<<i+1<<"\t\t"<<processSize[i]
		<<"\t\t";
		if(allocation[i]!=-1){
			cout<<allocation[i]+1;
		}else{
			cout<<"Not Alloacate";
		}
		cout<<'\n';
	}
}
int main(){
	vector<int> block={100,500,200,300,600};
	vector<int> pro_Size={212,417,112,426};
	int m=block.size();
	int n=pro_Size.size();
	firstFit(block,pro_Size,m,n);
	return 0;
}
