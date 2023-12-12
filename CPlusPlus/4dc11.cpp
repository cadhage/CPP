#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 +6 ;
vector<bool> isPrime(N+1,true);
vector<int> ans(N+1,0);
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	isPrime[0] = isPrime[1] = false;
	for(int i=2 ; i*i <= N ; i++){
		if(isPrime[i]){
		for(int j=i*i ; j<=N; j+=i)
			isPrime[j] = false;
		}
	}
	ans[0] = ans[1] = 0;
	for(int i=2; i<=N ; i++) 
		ans[i] = (isPrime[i]==true) + ans[i-1];
	
	int Q,L,R; cin >> Q;
	while(Q--){
		cin >> L >> R;
		if(L>R) 
			swap(L,R);
		cout << ans[R]- ans[L-1] << "\n";
	}
}
