#include <bits/stdc++.h>
using namespace std;
void BFS(int a,int b,int target){
	list<pair<int,int>> q;
	map<pair<int,int>,int> m;
	vector<pair<int,int>> path;
	q.push_back({0,0});
	bool isSolvable=false;
	while(!q.empty()){		
		pair<int,int> u=q.front();
		if(m[{u.first,u.second}]==1)
			continue;
		if((u.first>a||u.second>b||u.first<0 ||u.second<0))
			continue;
		m[{u.first,u.second}]=1;
		if(u.first==target||u.second==target){
			isSolvable=true;
			if(u.first==target)
			{
				if(u.second!=0){
					path.push_back({u.first,0});
				}
			}else{
				if(u.first!=0){
					path.push_back({0,u.second});
				}
			}
			int sz=path.size();
			for(int i=0;i<sz;i++){
				cout<<"("<<path[i].first<<","<<path[i].second<<")"<<'\n';
			}
			break;
		}
		q.push_back({u.first,b});
		q.push_back({a,u.second});
		for(int i=0;i<=max(a,b);i++){
			int c=u.first+i;
			int d=u.second-i;
			if(c==a||(d==0&&d>=0)){
				q.push_back({c,d});
			}
			c=u.first-i;
			d=u.second+i;
			if((c==0 &&c>=0)||d==b){
				q.push_back({c,b});
			}
		}
		q.push_back({a,0});
		q.push_back({0,b});
	}
	if(!isSolvable){
		cout<<"Not solvable"<<' ';
	}
}
int main(){
	int Jug1 = 4, Jug2 = 3, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    BFS(Jug1, Jug2, target); 
	return 0;
}
