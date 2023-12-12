// CPP program to find all subsets by backtracking. 
#include <bits/stdc++.h> 
using namespace std; 
bool checkValidPair(int num1, int num2) 
{ 
	string s1 = to_string(num1); 
	string s2 = to_string(num2); 
	for (int i = 0; i < s1.size(); i++) 
		for (int j = 0; j < s2.size(); j++) 
			if (s1[i] == s2[j]) 
				return true; 
	return false; 
} 
void subsetsUtil(vector<int>& A, vector<vector<int> >& res, 
				vector<int>& subset, int index) 
{ 
	res.push_back(subset); 
	for (int i = index; i < A.size(); i++) {  
		subset.push_back(A[i]);  
		subsetsUtil(A, res, subset, i + 1); 
		subset.pop_back(); 
	} 

	return; 
}  
vector<vector<int> > subsets(vector<int>& A) 
{ 
	vector<int> subset; 
	vector<vector<int> > res; 

	// keeps track of current element in vector A; 
	int index = 0; 
	subsetsUtil(A, res, subset, index); 

	return res; 
}  
void solver(vector<int> temp,int n){
	int sum=0;
//	for(auto i:temp){
////		cout<<i<<' ';
//	}
//	cout<<" -> ";
	for(int i=1;i<n;i++){
		int cur_max=0;
		if(!checkValidPair(temp[i],temp[i-1])){
			cout<<temp[i-1]<<"-"<<temp[i]<<' ';
			curr
		}
		else {
			cur_max=max(mx,max(temp[i],temp[i-1]));	
		}
	}
	cout<<'\n';
//	cout<<sum<<'\n';
}
int main() 
{ 
	vector<int> array = { 121,23,3,333,4}; 
	vector<vector<int> > res = subsets(array); 
	for (int i = 0; i < res.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < res[i].size(); j++){
			temp.push_back(res[i][j]);
		}
//		for(auto it: temp){
//			cout<<it<<' ';
//		}
		solver(temp,temp.size());
		//cout <<"->"<<temp.size()<<endl; 
	} 
	return 0; 
} 

