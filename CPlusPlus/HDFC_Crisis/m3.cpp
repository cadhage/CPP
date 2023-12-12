#include <bits/stdc++.h>
using namespace std;

int correct_no_of_pills(int yr, int month, int date, int m[]){
    if(date%2==1){
        
        date--;
    }
    if(m[month]==28){
        return (28-date)/2+16;
    }
    else if(m[month]==30){
        return (30-date)/2+16;
    }
    else if(m[month]==29){ 
        return (30-date)/2; 
    }
    else if(m[month]==31){
        return (32-date)/2; 
    }
}

int main() {
	int yyyy,mm,dd;
	int test_cases;
	cin>>test_cases;
	char colon;
	for(int i=0; i<test_cases; i++){
	
	    scanf("%d:%d:%d",&yyyy,&mm,&dd);
	    int noofdaysinmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	    if((yyyy%4==0 && yyyy%400==0) || (yyyy%4==0 && yyyy%100!=0)){
	        noofdaysinmonth[2]=29;
	    }
	    int result=correct_no_of_pills(yyyy,mm,dd,noofdaysinmonth);
	    cout<<result<<endl;
	}
	return 0;
}
