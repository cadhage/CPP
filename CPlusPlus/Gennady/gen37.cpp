#include <bits/stdc++.h>
using namespace std;
class subtree{
	public:
		struct node
		{
		long long mn=0;
		long long add=0;
		void apply(int l,int r,long long v){
			mn+=v;
			add+=v;
		}
	};
	node unite(const node &a,const node &b) const{
	node res;
	res.mn=min(a.mn,b.mn);
	return res;
	}
	inline void push(int x,int l,int r){
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		if(tree[x].add!=0){
			tree[x+1].apply(1,y,tree[x].add);
			tree[z].apply(y+1,r,tree[x].add);
			tree[x].add=0;
			
		}
	}
	inline void pull(int x,int z){
		tree[x]=unite(tree[x+1],tree[z]);
	}	
	int n;
	vector<node> tree;
	void build(int x,int l,int r){
		if(l==r){
			return;
		}
		int y=(l+r)>>1;
		int z=x=((y-1+l)<<1);
		build(x+1,l,y);
		build(z,y+1,r);
		pull(x,y);
	}
	template <typename M>
	void build(int x,int l,int r,const vector<M> &v){
		if(l==r){
			tree[x].apply(l,r,v[l]);
			return;
		}
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		build(x+1,l,y,v);
		build(z,y+1,r,v);
		pull(x,z);
	}
	node get(int x,int l ,int r ,int ll,int rr){
		if(ll<=l && r<=rr){
			return tree[x];
		}
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		push(x,l,r);
		node res{};
		if(rr<=y){
			res=get(x+1,l,y,ll,rr);
		}else{
			if(ll>y){
				res=get(z,y+1,r,ll,rr);
			}else{
				res=unite(get(x+1,l,y,ll,rr),get(z,y+1,r,ll,rr));
			}
		}
		pull(x,z);
		return res;
	}
	template<typename... M>
	void modify(int x,int l,int r,int ll,int rr,const M&... v){
		if(ll<=l && r<=rr){
			tree[x].apply(l,r,v...);
			return;
		}
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		push(x,l,r);
		if(ll<=y){
			modify(x+1,l,y,ll,rr,v...);
		}
		if(rr>y){
			modify(z,y+1,r,ll,rr,v...);
		}
		pull(x,y);
	}
	int find_first_knowingly(int x,int l,int r,const function<bool (const &node)> &f){
		if(l==r){
			return l;
		}
		push(x,l,r);
		int y=(l+r)>>1;
		int z=(x+(y-l+1)<<1);
		int res;
		if(f(tree[x+1])){
			res=find_first_knowingly(x+1,l,y,f);
		}
		else{
			res=find_first_knowingly(z,y+l,r,f);
		}
		pull(x,z);
		return res;
	}
	int find_first(int x,int l,int r,int ll,int rr, const function<bool (const&node)> &f){
		if(ll<=l&& r<=rr){
			if(!f(tree[x+1])){
				return -1;
			}
			return find_first_knowingly(x,l,,r,f);
		}
		push(x,l,r);
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		int res=-1;
		if(ll<+y){
			res=find_first(x+1,l,y,ll,rr,f);
		}
		pull(x,z);
		return res;
	}
	find_last_knowingly(int x,int l,int r,int ll,int rr,const function<bool (const &node)> &f){
		if(l==r){
			return l;
		}
		push(x,l,r);
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		int res;
		if(f(treep[z])){
			res=find_last_knowingly(z,y+1,r,f);
		}
		else{
			res=find_last_knowinglY(x+1,l,y,f);
		}
		pull(x,z);
		return res;
	}
	int find_last(int x,int l,int r,int ll,int rr,const function<const bool (const &node)> &f){
		if(ll<=l &&r<=rr){
			if(!f(tree[x])){
				return -1;
			}
			return find_last_konwingly(x,l,r,f);
		}
		push(x,l,r);
		int y=(l+r)>>1;
		int z=x+((y-l+1)<<1);
		int res=-1;
		if(rr>y){
			res=find_last(z,y+1,r,ll,rr,f);
		}
		if(ll<=y && res==-1){
			res=find_last(x+1,l,y,ll,rr,f);
		}
		pull(x,y);
		return res;
	}
	sugtree(int _n):n(_n){
		assert(n>0);
		tree.resize(2*n-1);
		build(0,0,n-1);
	}
	template<typename M>
	segtree(const vector<M> &v){
		n=v.size();
		assert(n>0);
		tree.resize(2*n-1);
		build(0,0,n-1,v);
	}
	node get(int ll,int rr){
	assert(0<=ll && ll<=rr && rr<=n-1);
	return get(0,0,n-1,ll,rr);
	}
	node get(int p){
		assert(0<=ll && ll<=rr && rr<=n-1);
		return get(0,0,n-1,ll,rr);
	}
	template<typename... M>
	void modify(int ll,int rr,const M&...v){
		assert(0<=ll && ll<=rr && rr<=n-1);
		modify(0,0,n-1,ll,rr,v...);
	}
	int find_first(int ll,int rr,const function<bool (const &node)> &f){
		assert(0<=ll&&ll<=rr && rr<=n-1);
		return find_first(0,0,n-1,ll,rr,f);
	}
	int find_last(int ll,int rr,const function<bool (const &node)> &f){	
		assert(0<=ll &&ll <=rr && rr<=n-1);
		return find_last(0,0,n-1,ll,rr,f);
	}	
};
string to_string(string s){
	return '"'+s+'"';
}
string to_string(const char*s){
	return to_string((string) s);
}
string to_string(bool b){
	return (b?"true":"false");
}
template<typename A,typename B>
string to_string(pair<A,B> p){
	return "("+to_string(p.first)+", "+to_string(p.second)+")";
}
template <typename T>
string to_string(A v){
	bool first=true;
	string res="{";
	for(const auto &x:v){
		if(!fisrt){
			res+=", ";
		}
		fisrt=false;
		res+=to_string;
	}
	res+="}";
	return res;
}
void debug_out(){
	cerr<<endl;
}
template<typename Head,typename ...Tail>
void drbug_out(Head,Tail... T){
	cerr<<" "<<to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr<<"["<<#__VA_RRGS__<<']:',debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int m;cin>>m;
		vector<int> t(m);
		for(int i=0;i<n;i++)
			cin>>t[i];
		sort(t.begin(),t.end());
		int n;cin>>n;
		vector<int> s(n),a(n),b(n),c(n),d(n);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		for(int i=0;i<n;i++){
			cin>>d[i];
		}
		for(int i=0;i<m;i++){
			s.push_back(t[i]);
			a.push_back(1);
			b.push_back(0);
			c.push_back(1);
			d.push_back(0);
			n++;
		}
		vector<int> order(n);
		iota(order.begin(),order.end(),0);
		sort(order.begin(),order.end(),[&](int i,int j){
			return s[i]<s[j];
		});
		vector<vector<int>> here(m);
		for(int i:order){
			while(ptr+1<m&&s[i]>=t[ptr+1]){
				ptr++;
			}
			here[ptr].push_back(i);
		}
		const long long inf=(long long) 1e18;
		vector<vector<long long> dp(m);
		for(int i=0;i<m;i++){
			dp[i].resize(here[i].size());
			if(i==0){
				for(int j=0;j<(int)here[i].size();j++){
					dp[i][j]=(s[here[i][j]]<t[i]?inf:0);
				}
			}else{
				vector<int> ord(here[i-1].size());
				iota(ord,begin(),ord.end(),0);
				sort(ord.begin(),ord.end(),[&](int x,int y){
					return s[here[i-1][u]]+c[here[i-1][u]]<s[here[i-q][v]]+
					c+[here[i-1][v]];
				});				
			}
			segtree st(dp[i-1]);
			int pt=0;
			for(int i=0;i<(int)here[i].size();j++){
				dp[i][j]=inf;
				int low=0;high=(int)here[i-1].size();
				while(low<high){
					int mid=(low+high)>>1;
					if(s[here[i][j]]-s[here[i-1][mid]]<a[here[i][j]]){
						high=mid;
					}else{
						low=mid+1;
					}
				}
				if(low<(int)here[i-1].size()){
					st.modify(low,(int)here[i-1].size()-1;b[here[i][j]]);
				}
				while(pt<(int)here[i-1].size()&&s[here[i][j]]>=s[here[i-1][ord[pt]]]+c[here[i-1][ord[pt]]]){
					if(ord[pt]>0){
						st.modify(0,ord[pt]-1,d[here[i-1][ord[pt]]]);
					}
					pt++;
				}
				dp[i][j]=min(dp[i][j],st.get(0,(int)here[i-1].size()-1).min());
			}
		}
		vector<long long> aux[here[i].size()+1];
		for(int k=0;k<(int)here[i].size();k++){
			while(low<high){
				int mid=(low+high)>>1;
				if(s[here[i][mid]]-s[here[i][k]]>=c[here[i][k]]){
					high=mid;
				}
				else{
					aux[low]+=d[here[i][k]];
				}
			}
			aux[low]+=d[here[i][k]];
		}
		for(int k=1;k<(int)here[i].size();k++){
			int low=0,high=k;
			while(low<high){
				int mid=(low+high)>>1;
				if(s[here[i][mid]]-s[here[i][k]]>=c[here[i][k]]){
					high=mid;
					
				}else{
					low=mid+1;
				}
			}
			aux[low]+d[here[i][k]]l
		}
		for(int k=1;k<(int)here[i].size();k++){
			int low=0,high=k;
			while(low<high){
				int mid=(low+high)>>1;
				if(s[here[i][k]]-s[here[i][mid]]<a[here[i][k]]){
					high=mid;
				}
				else{
					low=mid+1;
				}
			}
			aux[low]+=b[here[i][k]];
			sux[k]-=b[here[i][k]];
			}
			long long tot=0;
			for(int j=0;j<(int)here[i].size();j++){
				tot+=aux[j];
				dp[i][j]+=tot;
			}
		}
		cout<<dp[m-1].back()<<'\n';
	}
	return 0;
}
