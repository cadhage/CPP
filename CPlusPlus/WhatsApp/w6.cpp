#include <bits/stdc++.h>
using namespace std;
void BFS(int a,int b,int x){
	map<pair<int,int>, int> m;
	bool isSolvable=false;
	vector<pair<int,int>>  path;
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		if(m[{u.first,u.second}]==1)
			continue;
		if((u.first>a||u.second>b||u.first<0 ||u.second<0)){
			continue;
		}
		path.push_back({u.first,u.second});
		m[{u.first,u.second}]=1;
		if((u.first==x ||u.second==x)){
			isSolvable=true;
			if(u.first==x){
				if(u.second!=0){
					path.push_back({u.first,0});
				}
			}else{
				if(u.second!=0){
					path.push_back({0,u.second});
				}
			}
			int sz=path.size();
			for(int i=0;i<sz;i++){
				cout<<"("<<path[i].first<<" , "
					<<path[i].second<<")"<<'\n';
			}
			break;
		}
		q.push({u.first,b});
		q.push({a,u.second});
		for(int i=0;i<=max(a,b);i++){
			int c=u.first+i;
			int d=u.second-i;
			if(c==a||(d==0&&d>=0)){
				q.push({c,d});
				c=u.first-i;
				d=u.second+i;
			}
			if((c==0&&c>=0)||d==b){
				q.push({c,d});
			}
		}
		q.push({a,0});
		q.push({0,b});
	}
	if(!isSolvable){
		cout<<"No Solution";
	}
}
int main() 
{ 
    int Jug1 = 4, Jug2 = 3, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    BFS(Jug1, Jug2, target); 
    return 0; 
} 
