#include <bits/stdc++.h>
using namespace std;
struct Point{
	double x,y,z;
	void read(){
	cin>>x>>y>>z;
	}
	Point& operator-=(const Point &b){
		x-=b.x;
		y-=b.y;
		z-=b.z;
		return *this;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(9);
	int tt;cin>>tt;
	while(tt--){
		Point p,q,d,c;
		p.read();
		q.read();
		d.read();
		c.read();
		p-=c;
		q-=c;
		double r;
		cin>>r;
		double low=0.0,high=1e9;
		for(int it=0;it<100;it++){
			Point u;
			double mid=0.5*(low+high);
			u.x=q.x+mid*d.x;
			u.y=q.y+mid*d.y;
			u.z=q.z+mid*d.z;
			u.x-=p.x;
			u.y-=p.y;
			u.z-=p.z;
			double A=u.x*u.x+u.y*u.y+u.z*u.z;
			double B=2*p.x*u.x+2*p.y*u.y+2*p.z*u.z;
			double C=p.x*p.x+p.y*p.y+p.z*p.z;
			double T=-B/(2*A);
			if(T>0){
				double dist=(p.x+T*u.x)*(p.x+T*u.x);
				dist+=(p.y+T*u.y)*(p.y+T*u.y);
				dist+=(p.z+T*u.z)*(p.z+T*u.z);
				if(dist>r*r){
					high=mid;
				}
				else{
					low=mid;
				}
			}
			else{
				high=mid;
			}
		}
		double res=0.5*(low+high);
		cout<<res<<'\n';
	}
	return 0;
}
