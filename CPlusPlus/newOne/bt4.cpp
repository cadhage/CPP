#include<bits/stdc++.h> 
using namespace std; 
vector<int> v;
void inorder(int a[],int n,int index){
	if(index>=n)
		return;
	inorder(a,n,2*index+1);
	v.push_back(a[index]);
	inorder(a,n,2*index+2);
}

int maxSwaps(){
	int ans=0;
	vector<pair<int,int>> ms(v.size());
	for(int i=0;i<v.size();i++){
		ms[i].first=v[i],ms[i].second=i;
	}
	sort(ms.begin(),ms.end());
	for(int i=0;i<ms.size();i++){
		if(i==ms[i].second)
			continue;
		else{
			swap(ms[i].first, ms[ms[i].second].first); 
			swap(ms[i].second, ms[ms[i].second].second); 
		}
		if(i!=ms[i].second){
			i--;
		}
		ans++;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	inorder(a,n,0);
	cout<<maxSwaps();
	return 0;
}
