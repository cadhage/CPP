#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> &a,const pair<int,int> &b){
	return (a.first<b.first);
}
void print(vector<pair<int,int>> vect){
	  for (int i=0; i<vect.size(); i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
  
    } 
}
int main(){
	vector< pair <int,int> > vect; 
    int arr[] = {10, 20, 5, 40 }; 
    int arr1[] = {30, 60, 20, 50};
	int n=sizeof(arr)/sizeof(arr[0]); 
    for(int i=0;i<n;i++){
    	vect.push_back({arr[i],arr1[i]});
	}
	sort(vect.begin(),vect.end(),compare);
	print(vect);
	return 0;
}
