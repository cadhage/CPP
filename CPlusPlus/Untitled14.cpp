#include<bits/stdc++.h>
using namespace std;
bool isSafe(int sol[][0],int i,int j,int previ,int prevj,int n);
void solver(string s, int n,int sol[][0]);
int main(){
		int q;cin>>q;
        for(int ii=0;ii<q;ii++){
        int n;cin>>n;
        int sol[n][n];
         for (int i = 0; i <n;i++) {
           for (int j = 0; j < n;j++) {
               sol[i][j]=0;
           }
       }
        char str[100];
        cin.get(str,100);
        solver(str,n,sol);
        cout<<"\n";
        }
    }
   bool isSafe(int n,int sol[][n],int i,int j,int previ,int prevj){
         if(sol[i][j]==0 &&(sol[i][prevj]==1) && (prevj<=j))
            return true;
        if(sol[i][j]==0 &&(sol[previ][j]==1 ))
            return true;
        return false;
     }	
    void solver(string s, int n,int sol[][n]) {
     sol[0][0]=1;
     int i=0,j=0;
      for (int k = 0; k < 2*n-2;k++) {
        if(s(k)=='E'){
         j=j+1;
         sol[i][j]=1;
         
        }
        else if(s[k]=='S'){
         i=i+1;
         sol[i][j]=1;
        }

     }
     cout<<"Case #x: ";
      int previ=0,prevj=0,resi=0,resj=0;
      for (i = 0; i <n;i++) {
        for (j = 0; j <n;j++) {
            if(isSafe(n,sol,i,j,previ,prevj)){
            
                if(j==resj+1 && i==resi+1 )
                   cout<<"SE"; 
                else if(j==resj+1 && i>=resi)
                    cout<<"E";
                else if(j==resj+2 && i>=resi)
                    cout<<"EE"; 
                else if(i==resi+1 && j>=resj)
                    cout<<"S";
                else if(i==resi+2 && j>=resj)
                    cout<<"SS";
                else if(i<resi || resj<j)
                    continue;
                 if(i==sol.length-1 && j>=resj){
                    cout<<"E";
                }
                else if(j==sol.length-1 && i>=resi){
                    cout<<"S";
                }
              //System.out.println(i+" "+j);
                resi=i;
                resj=j;
                // if(i==sol.length-1){
                //     System.out.print("E");
                //     break;
                // }
                // if(j==sol.length-1){
                //     System.out.print("S");
                //     break;
                // }
                
            }
            prevj=j;
            
            //System.out.println("")
        }
        previ=i;
     }
  
    }

