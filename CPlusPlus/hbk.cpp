#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi pair<int,int>
#define pll pair<long long,long long>
#define mapi map<int,int>
#define mapll map<long long,long long>
#define vi vector<int>
#define vii vector<vector<int> >
#define vll vector<long long>
#define vpi vector<pair<int,int> >
#define vs vector<string>
#define vpll vector<pair <long long,long long> >
#define lcm(a,b) boost::math::lcm(a,b)
#define stacki stack<int>
#define stackll stack<long long>
#define queuei queue<int >
#define queuell queue<long long >
#define pr_qi priority_queue<int >
#define pr_qll priority_queue<long long >
#define m_p(a,b) make_pair(a,b)
#define p_b(a) push_back(a)
#define endl "\n"
int main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//
	
	int n,q;
	cin >> n >> q;
	map<long long,long long> m;
	while(q--)
	{
	    int type,val;
	    cin >> type >> val;
	    if(type==1)
	    {
	        m.insert({val,-1});
	    }
	    else
	    {
	        map<long long ,long long>::iterator it;
	        it=m.lower_bound(val);
	        if(it==m.end())
	            cout<<"-1\n";
	        else
	            cout<<it->first<<endl;
	    }
	}
	
	//
	return 0;
}
