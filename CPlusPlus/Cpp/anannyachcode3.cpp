#include <bits/stdc++.h>

using namespace std;
void solver(vector<int> nums,int target){
 	set<int> set;
    vector<int> ans;
    for(auto i=0;i<nums.size();i++){
        if(set.find(target-nums[i])!=set.end()){
//            ans.push_back(it);
//            ans.push_back(target-it);
			cout<<nums[i]<<" "<<target-nums[i]<<'\n';
        }
        else set.insert(nums[i]);
    }
	//return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,sum;cin>>n>>sum;
  vector<int> a;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  solver(a,sum);
  return 0;
}

