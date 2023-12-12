#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int k;cin>>k;
		char a[10000];
		cin>>a;
		int l=strlen(a);
		int m,n=0;
		for(int i=0;i<l;i++){
			if(a[i]=='P'){
				n++;
			}
		}
		if((n*100)/k>=75){
			cout<<"0\n";
		}
		else{
			int o=0;
			for(int o=n;o<l;o++){
				if((o*100)/k>=75){
					break;
				}
			}
			int p=0;
			for(int i=2;i<l-2;i++){
				if(a[i]=='A' && ((a[i-1]=='P' && a[i+1]=='P') || 
				(a[i-1]=='P' && a[i+2]=='P') || (a[i-2]=='P' && 
				a[i+1]=='P') || (a[i-2]=='P' && a[i+2]=='P')))
	            {
	                p++;
	            }
			}
			if(o-n<=p){
				cout<<o-n<<'\n';
			}
			else{
				cout<<"-1\n";
			}
		}
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
24868984
int main() 
{
	int i,j;
	cin>>i;
	for(j=0;j<i;j++)
	{
	    int k;
	    cin>>k;
	    char a[10000];
	    cin>>a;
	    int l=strlen(a);
	    int m,n=0;
	    for(m=0;m<l;m++)
	    {
	        if(a[m]=='P')
	        {
	            n++;
	        }
	    }
	    if((n*100)/k>=75)
	    {
	        cout<<"0\n";
	    }
	    else
	    {
	        int o;
	        for(o=n;o<l;o++)
	        {
	            if((o*100)/k>=75)
	            {
	                break;
	            }
	        }
	        int p=0;
	        for(m=2;m<l-2;m++)
	        {
	            if(a[m]=='A' && ((a[m-1]=='P' && a[m+1]=='P') || (a[m-1]=='P' && a[m+2]=='P') || (a[m-2]=='P' && a[m+1]=='P') || (a[m-2]=='P' && a[m+2]=='P')))
	            {
	                p++;
	            }
	        }
	        if(o-n<=p)
	        {
	            cout<<o-n<<"\n";
	        }
	        else
	        {
	            cout<<"-1\n";
	        }
	    }
	}
	return 0;
}

*/
