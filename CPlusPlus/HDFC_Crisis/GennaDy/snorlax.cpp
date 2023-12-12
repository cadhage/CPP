#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
//2
//5 3
//3 
//3 
//3
//5 2
//1 
//2 
//1 
//2
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n-k+1);
		for(int i=0;i<n-k+1;i++)
			cin>>a[i];
		int ok=0;
		for(int i=0;i<n-k;i++){
			if(abs(a[i]-a[i+1])>1){
				ok=0;
				break;
			}
		}
		if(!ok){
			cout<<-1<<'\n';
			continue;
		}
		vector<int> vals;
		int take=a[0];
		int ans=0;
		for(int r=0;r<k;r++){
			vector<int> u;
			u.push_back(0);
			for(int i=r;i<n-k;i+=k){
				if(a[i]==a[i+1]+1){
					u.push_back(u.back()-1);
				}else{
					if(a[i]==a[i+1]-1){
						u.push_back(u.back()+1);
					}else{
						u.push_back(u.back());
					}
				}
			}
			int mn=*min_element(u.begin(),u.end());
			int mx=*max_element(u.begin(),u.end());
			if(mx-mn<=1){
				for(int &i:u){
					i-=mn;
				}
				if(mx-mn==1){
					ans+=accumulate(u.begin(),u.end(),0);
				}else{
					vals.push_back((int)u.size());
				}
			}else{
				ok=0;
				break;
			}
		}
		if(!ok||take<0||take>(int)vals.size()){
			cout<<-1<<'\n';
			continue;
		}
		sort(vals.begin(),vals.end());
		ans+=accumulate(vals.begin(),vals.begin()+take,0);
		cout<<ans<<'\n';
	}
	return 0;
}
