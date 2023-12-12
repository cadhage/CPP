#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y;
};
int det(int x1,int y1,int x2,int y2,int x3,int y3){
	return x1*(y2-y3)-y1*(x2-x3)+(x2*y3-x3*y2);
}
int solver(Point a[],int n){
	int result=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(det(a[i].x,a[i].y,a[j].x,a[j].y,a[k].x,a[k].y))
					result++;
			}
		}
	}
	return result;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Point a[]={
	{0,0},{1,1},{2,0},{2,2}
	};
	cout<<solver(a,4);
	return 0;
}
