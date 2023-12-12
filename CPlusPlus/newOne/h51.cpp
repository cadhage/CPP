#include <bits/stdc++.h>
using namespace std;
#define d 256
struct suffix{
	int index;
	int rank[2];
};
vector<int> buildSuffixArray(string txt,int n){
	struct suffix sufixes[n];
	for(int i=0;i<n;i++){
		sufixes[i].index=i;
		sufixes[i].rank[0]=txt[i]-'a';
		sufixes[i].rank[1]=((i+1)<n)?(txt[i+1]-'a'):1;
	}
	sort(sufixes,sufixes+n,[&](struct suffix a,struct suffix b)
	{
		return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1:0):
			(a.rank[0]<b.rank[0]?1:0);
	});
	vector<int> ind(n);
	for(int k=4;k<2*n;k*=2){
		int rank=0;
		int prev_rank=sufixes[0].rank[0];
		sufixes[0].rank[0]=rank;
		ind[sufixes[0].index]=0;
		for(int i=1;i<n;i++){
			if(sufixes[i].rank[0]==prev_rank&&
				sufixes[i].rank[1]==sufixes[i-1].rank[1]){
				prev_rank=sufixes[i].rank[0];
				sufixes[i].rank[0]=rank;
			}else{
				prev_rank=sufixes[i].rank[0];
				sufixes[i].rank[0]=++rank;
			}
			ind[sufixes[i].index]=i;
		}
		for(int i=0;i<n;i++){
			int nextIndex=sufixes[i].index+k/2;
			sufixes[i].rank[1]=nextIndex<n?sufixes[ind[nextIndex]].rank[0]:-1;
		}
		sort(sufixes,sufixes+n,[&](struct suffix a,struct suffix b)
		{
			return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1:0):
				(a.rank[0]<b.rank[0]?1:0);
		});
	}
	vector<int> suffixArr;
	for(int i=0;i<n;i++){
		suffixArr.push_back(sufixes[i].index);
	}
	return suffixArr;
}
int main(){
	string str = "banana"; 
    vector<int> suffixArr = buildSuffixArray(str, str.length());
	for(auto it:suffixArr){
		cout<<it<<' ';
	} 
	return 0;
}
