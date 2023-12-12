#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first


#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)


int main()
{
	fastio;
	ll t;
	cin>>t;
	while(t--)
    {
    	string str1,str2;
    	ll l,r,c=0,val,val1,j;
    	cin>>str1>>str2>>l>>r;
    	if(str1=="sunday") val=0;
    	else if(str1=="monday") val=1;
    	else if(str1=="tuesday") val=2;
    	else if(str1=="wednesday") val=3;
    	else if(str1=="thursday") val=4;
    	else if(str1=="friday") val=5;
    	else if(str1=="saturday") val=6;

    	if(str2=="sunday") val1=0;
    	else if(str2=="monday") val1=1;
    	else if(str2=="tuesday") val1=2;
    	else if(str2=="wednesday") val1=3;
    	else if(str2=="thursday") val1=4;
    	else if(str2=="friday") val1=5;
    	else if(str2=="saturday") val1=6;
    	val=(val1-val+8)%7;
    	while(val<=r)
    	{
    		if(val>=l)
    		{
    			c++;
    			j=val;
    		}
    		val+=7;
    	}
    	if(c>1)
    		cout<<"many";
    	else if(c==1)
    		cout<<j;
    	else
    		cout<<"impossible";
    	cout<<endl;
    }
    
    return 0;
}
