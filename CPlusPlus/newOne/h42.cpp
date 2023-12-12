#include<bits/stdc++.h>
using namespace std;

vector<long long> solve (vector<int> A, vector<long long int> R, vector<long long int> L) {
   int n=sizeof(R)/sizeof(R[0]);
   for(long long i=0;i<R.size();i++){
   		for(long long k=0;k<A.size();k++){
   				
		}
   }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A=0; i_A<N; i_A++)
        {
        	cin >> A[i_A];
        }
        int Q;
        cin >> Q;
        vector<long long int> L(Q);
        for(int i_L=0; i_L<Q; i_L++)
        {
        	cin >> L[i_L];
        }
        vector<long long int> R(Q);
        for(int i_R=0; i_R<Q; i_R++)
        {
        	cin >> R[i_R];
        }
        for(long long i=0;i<R.size();i++){
        //	long long sum=0;
			cout<<accumulate((A.begin()+L[i])%A.size(),A.end(),0)<<"\n";
		}
    }
}
