#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	while(q-->0){
		int n,m;cin>>n>>m;
		int a[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		// k must be smaller than or equal to n 
	int k=n/2,sm=0,temp=0;
  	vector<int> suma;
   for (int i=0; i<n-k+1; i++) 
   {
    
      // column of first cell in current sub-square of size k x k 
      for (int j=0; j<n-k+1; j++) 
      { 
          // Calculate and print sum of current sub-square 
          int sum = 0,count=0; 
          for (int p=i; p<k+i; p++) 
             for (int q=j; q<k+j; q++){
                 sum += a[p][q]; 
				 count++;
				 }
		int prev;
		if((i==0&&j==0))
			temp=prev=sum;
        if((i==0 || i==2 )&&(j==0 || j==2))
		   	cout<<prev<<" "<<sum<<" ";
		   	prev=sum;
      } 
      

	}
	cout<<sm;
	}
	return 0;
}
