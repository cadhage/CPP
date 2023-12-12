#include <bits/stdc++.h>
using namespace std;
//ASSINMENT
struct win{
	int x,y,z,w,r;
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	printf("Enter number of Players: ");
	int n;cin>>n;
	int a[n][3];
	win player[n];
	printf("Now Enter cards of players saperated by space of next line: ");
	for(int i=0;i<n;i++){
		player[i].x=player[i].y=player[i].z=player[i].w=player[i].r=-1;
	}
	for(int i=0;i<n;i++){
		for(int ii=0;ii<3;ii++){
			cin>>a[i][ii];
		}
	}
	//FOR NO MATCHING
	for(int i=0;i<n;i++){
		int aa[3];
		sort(a[i],a[i]+3);
		aa[0]=a[i][0]%13;
		aa[1]=a[i][1]%13;
		aa[2]=a[i][2]%13;
		sort(aa,aa+3);
		if(aa[0]==0)
			player[i]={i,5,INT_MAX,aa[2],aa[1]};
		else player[i]={i,5,aa[2],aa[1],aa[0]};
	}
	
	//FOR ALL EQUAL CARS
	int three_max=0,win_three;
	bool threes=false;
	for(int i=0;i<n;i++){
		sort(a[i],a[i]+3);
		if(a[i][0]%13==a[i][1]%13 && a[i][1]%13==a[i][2]%13){
			three_max=a[i][0]%13;
			threes=true;
			if(three_max==0)
				three_max=INT_MAX;
			player[i]={i,0,three_max,0,0};
		}
	}
	
	//SEQUENCE
	int seq_sum=0,win_seq=0;bool seq=false;
	for(int i=0;i<n;i++){
		sort(a[i],a[i]+3);
		if(a[i][0]%13+1==a[i][1]%13 && a[i][1]%13+1==a[i][2]%13){
			win_seq=i;
			seq_sum=(a[i][0]%13+a[i][1]%13+a[i][2]%13);
			if(seq_sum==3)
				seq_sum=INT_MAX;
			seq=true;
			player[i]={i,2,seq_sum,0,0};
		//	cout<<seq_sum;
		}
	}
	
	//TWOS
	int twos_max=0,twos__max=0,win_twos=0;
	bool twos=false;
	for(int i=0;i<n;i++){
		sort(a[i],a[i]+3);
		if(!threes && a[i][0]%13==a[i][1]%13){
			win_twos=i;
			twos=true;
			twos_max=a[i][0];
			twos__max=a[i][2];
			player[i]={i,4,twos_max,twos__max,0};
		}
		else if(!threes && a[i][1]%13==a[i][2]%13){
			win_twos=i;
			twos=true;
			twos_max=a[i][1];
			twos__max=a[i][0];
			player[i]={i,4,twos_max,twos__max,0};
		}
		else if(!threes && a[i][0]%13==a[i][2]%13){
			win_twos=i;
			twos=true;
			twos_max=a[i][1];
			twos__max=a[i][1];
			player[i]={i,4,twos_max,twos__max,0};
		}
	}
	//FOR COLOR
	int color_max=0,win_color=0;
	bool color=false;
	for(int i=0;i<n;i++){
		sort(a[i],a[i]+3);
		if(a[i][0]>=0 && a[i][0]<=12 && a[i][1]>=0 && a[i][1]<=12 && a[i][2]>=0 && a[i][2]<=12  ){
			win_color=i;
			color=true;
			color_max=a[i][2]%13;
			if(seq)
				player[i]={i,1,color_max,0,0};
			else player[i]={i,3,color_max,0,0};
		}
		if(a[i][0]>=13 && a[i][0]<=25 && a[i][1]>=16 && a[i][1]<=25 && a[i][2]>=13 && a[i][2]<=25 ){
			win_color=i;
			color_max=a[i][2]%13;
			color=true;
			if(seq)
				player[i]={i,1,color_max,0,0};
			else player[i]={i,3,color_max,0,0};
		}
		if(a[i][0]>=26 && a[i][0]<=38 && a[i][1]>=26 && a[i][1]<=38 && a[i][2]>=26 && a[i][2]<=38){
			win_color=i;
			color_max=a[i][2]%13;
			color=true;
			if(seq)
				player[i]={i,1,color_max,0,0};
			else player[i]={i,3,color_max,0,0};
		}
		if(a[i][0]>=39 && a[i][0]<=51 && a[i][1]>=39 && a[i][1]<=51 && a[i][2]>=39 && a[i][2]<=51  ){
			win_color=i;
			color_max=a[i][2]%13;
			color=true;
			if(seq)
				player[i]={i,1,color_max,0,0};
			else player[i]={i,3,color_max,0,0};
		}
	}
	//FINDING RESULTS
	int mx=INT_MIN,win_i=0;
	bool fst=false;
	for(int i=0;i<n;i++){
		if(player[i].y==0 && player[i].z>mx){
			mx=player[i].z;
			win_i=i;
			fst=true;
		}
	}
	if(fst)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';
	
	bool scd=false;
	for(int i=0;i<n;i++){
		if(player[i].y==1 && player[i].z>mx){
			mx=player[i].z;
			win_i=i;
			scd=true;
		}
	}
	if(scd)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';
	
	bool trd=false;
	for(int i=0;i<n;i++){
		if(player[i].y==2 && player[i].z>mx){
			mx=player[i].z;
			win_i=i;
			trd=true;
		}
	}
	if(trd)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';
	
	bool frt=false;
	for(int i=0;i<n;i++){
		if(player[i].y==3 && player[i].z>mx){
			mx=player[i].z;
			win_i=i;
			frt=true;
		}
	}
	if(frt)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';

	bool fft=false;
	int mxx=0;
	for(int i=0;i<n;i++){
		if(player[i].y==4 && player[i].z>mx && mxx==player[i].w>mxx){
			mx=player[i].z;
			mxx=player[i].w;
			win_i=i;
			fft=true;
		}
	}
	if(fft)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';
	
	bool sx=false;
	int m1=0,m2=0,m3=0;
	for(int i=0;i<n;i++){
		if(player[i].y==5){
			if(player[i].z>m1){
				m1=player[i].z;
				win_i=i;
				sx=true;
			}
		}
	}
	if(sx)
		cout<<"Winner is Player number: "<<win_i+1<<'\n';
	return 0;
}
