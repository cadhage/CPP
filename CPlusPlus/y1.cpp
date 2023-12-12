// C++ program to print print all primes in a range 
// using concept of Segmented Sieve 
#include <bits/stdc++.h> 
using namespace std; 

// This functions finds all primes smaller than limit 
// using simple sieve of eratosthenes. It stores found 
// primes in vector prime[] 
int c=0,cc=0;
void simpleSieve(int limit, vector<int>& prime) 
{ 
	bool mark[limit + 1]; 
	memset(mark, false, sizeof(mark)); 

	for (int i = 2; i <= limit; ++i) { 
		if (mark[i] == false) { 
			// If not marked yet, then its a prime 
			prime.push_back(i); 
			for (int j = i; j <= limit; j += i) 
				mark[j] = true; 
		} 
	} 
} //urns number of primes between segment [a,b]
int segmentedSieve ( int a, int b ) {
    if ( a == 1 ) a++;
 	int arr[b+1];
    int sqrtn = sqrt ( b );
 
    memset ( arr, 0, sizeof arr ); // Make all index of arr 0.
    
 	vector<int> prime;
	simpleSieve(sqrtn,prime);
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        int p = prime[i];
        int j = p * p;
 
        // If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
 
        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; // mark them as not prime
        }
    }
 
    int res = 0;
    for ( int i = a; i <= b; i++ ) {
        // If it is not marked, then it is a prime
        if ( arr[i-a] == 0 ) res++;
    }
    return res;
} 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long l, r,d,tt;
    //cin>>tt;
    //while(tt--){
	    cin >> l>>r>>d;
	    int c=0,cc=0;
	    //cout<<c<<' '<<cc<<'\n';
	    cout<<segmentedSieve(1,4)/(r-l+1);
	   // primesInRange(l,r+1,d);
	    
	//}
    return 0;
}

