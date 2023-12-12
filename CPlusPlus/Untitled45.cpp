#include <bits/stdc++.h>
using namespace std;
struct Box{
	int h;
	int w;
	int d;
	};
int compare (const void *a, const void * b) 
{ 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
}
int maxStackHeight(Box a[],int n){
	Box dp[3*n];
	int index=0;
	for(int i=0;i<n;i++){
		dp[index].h=a[i].h;
		dp[index].d=max(a[i].d,a[i].w);
		dp[index].w=min(a[i].d,a[i].w);
		index++;
		dp[index].h=a[i].d;
		dp[index].d=max(a[i].h,a[i].w);
		dp[index].w=min(a[i].h,a[i].w);
		index++;
		dp[index].h=a[i].d;
		dp[index].d=max(a[i].h,a[i].w);
		dp[index].w=min(a[i].h,a[i].w);
		index++;
	}
	n=3*n;
	qsort (dp, n, sizeof(dp[0]), [](int *a,int *b){
		return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w );}); 
	 int msh[n]; 
   for (int i = 0; i < n; i++ ) 
      msh[i] = dp[i].h; 
  
   /* Compute optimized msh values in bottom up manner */
   for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( dp[i].w < dp[j].w && 
              dp[i].d < dp[j].d && 
              msh[i] < msh[j] + dp[i].h 
            ) 
         { 
              msh[i] = msh[j] +dp[i].h; 
         } 
  
  
   /* Pick maximum of all msh values */
   int max = -1; 
   for ( int i = 0; i < n; i++ ) 
      if ( max < msh[i] ) 
         max = msh[i]; 
  
   return max; 
}
int main(){
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  printf("The maximum possible height of stack is %d\n", 
         maxStackHeight (arr, n) ); 
	return 0;
	
}

