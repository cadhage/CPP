#include <bits/stdc++.h>
using namespace std;
void print_N_mostFrequentNumber(int a[],int n,int k){
	map<int,int> um;
	for(int i=0;i<n;i++)
		um[a[i]]++;
	vector<pair<int,int>> freq_arr(um.begin(),um.end());
	priority_queue<pair<int,int>, vector<pair<int,int>>,[&](auto p1,auto p2){
		if (p1.second == p2.second) 
            return p1.first < p2.first; 
              
        // insert elements in the priority queue on the basis of 
        // decreasing order of frequencies     
        return p1.second < p2.second;
	}
}
int main() 
{ 
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    print_N_mostFrequentNumber(arr, n, k); 
    return 0; 
} 
