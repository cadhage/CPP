#include <bits/stdc++.h>
using namespace std;
int findXoR(vector<int> a){
	int res = 0; 
	int N=a.size();
	for(auto i:a)
		res^=i; 
    return res; 
}
int printPowerSet(int *set, int set_size,int k) 
{ 	int ek=0,lk=0,gk=0;
	vector<int> a;
    unsigned int pow_set_size = pow(2, set_size); 
    int counter, j; 
  
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++) 
    { 
    for(j = 0; j < set_size; j++) 
    { 
        /* Check if jth bit in the counter is set 
            If set then print jth element from set */
        if(counter & (1 << j)) 
            a.push_back(set[j]); 
    } 
//    for(auto i:a)
//    	cout<<i<<" ";
    //cout<<endl;
    int res=findXoR(a);
    if(res>k)
    	gk++;
    if(res==k)
    	ek++;
    if(res<k)
    	lk++;
    a.clear();
    } 
	cout<<pow(lk+ek,2)+pow(ek+gk,2)+pow(gk+lk,2)-(pow(lk,2)+pow(ek,2)+pow(gk,2))<<endl;
} 
int main(){
	int q;cin>>q;
	while(q-->0){
		int n,k;cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printPowerSet(a, n,k); 
	}
	return 0;
}
