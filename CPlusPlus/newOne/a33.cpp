#include <bits/stdc++.h>
using namespace std;
void rightrotate(vector<int> &arr, int n, int outofplace, int cur) 
{ 
    char tmp = arr[cur]; 
    for (int i = cur; i > outofplace; i--) 
        arr[i] = arr[i-1]; 
    arr[outofplace] = tmp; 
} 
void rearrange(vector<int> &a,int n){
	int outofplace=-1;
	for(int i=0;i<n;i++){
		if(outofplace>=0){
			if(((a[i]>=0) && a[outofplace]<0)||
				((a[i]<0)&&a[outofplace]>=0))
			{
				rightrotate(a,n,outofplace,i);
				if(i-outofplace>2)
					outofplace+=2;
				else
					outofplace=-1;
			}
		}
		if(outofplace==-1){
			if(((a[i]>=0)&&(!(i&0x01)))||
				((a[i]<0)&&(i&0x01))){
					outofplace=i;
				}
		}
	}
}
int main(){
	vector<int> a={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	for(auto i:a)
		cout<<i<<' ';
	rearrange(a,a.size());
	cout<<"\n\n";
	for(int it:a){
		cout<<it<<" ";
	}
	return 0;
}
