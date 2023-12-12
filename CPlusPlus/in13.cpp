#include<bits/stdc++.h>
using namespace std;

int minDays (vector<int> a) {
   // Write your code here
   int c=0;
   for(int i=0;i<a.size()-1;i++){
       if(a[i]<=a[i+1]){
           c+=a[i];
           cout<<a[i]<<'\n';
       }else if(a[i+1]<=a[i]){
           cout<<a[i]<<'\n';
       } 
   }
   return c;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> calories(N);
    for(int i_calories=0; i_calories<N; i_calories++)
    {
    	cin >> calories[i_calories];
    }

    int out_;
    out_ = minDays(calories);
    cout << out_;
}
