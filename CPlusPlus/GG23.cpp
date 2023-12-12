#include <bits/stdc++.h>
using namespace std;
vector<int> t(1000,0);
int sum=0;
int total_nodes=0;
void genrateSubsets(int a[],int n,int t_size,
				int index,int req_sum){
	total_nodes++; 
    if( sum == req_sum ) 
    { 
        // We found subset 
        //printSubset(t, t_size); 
        // Exclude previously added item and consider next candidate 
        subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum); 
        return; 
    } 
    else
    { 
        // generate nodes along the breadth 
        for( int i = ite; i < s_size; i++ ) 
        { 
            t[t_size] = s[i]; 
            // consider next level node (along depth) 
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum); 
        } 
    } 
}
int main() 
{ 
    int weights[] = {10, 7, 5, 18, 12, 20, 15}; 
    int size = ARRAYSIZE(weights); 
    generateSubsets(weights, size,0,0, 35); 
    printf("Nodes generated %dn", total_nodes); 
    return 0; 
} 
