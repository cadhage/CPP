#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
int v[1001]={0};
void dfs(int s,int length)
{
    v[s]=length;

    for(auto i:arr[s])
    {
        if(v[i]==0)
        {
            dfs(i,length+1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        x--;y--;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    int length=1;
    dfs(1,length);
    int q;
    cin>>q;
    int mn=INT_MAX;
    int mnn=0;
    while(q-->0){
        int x;
        cin>>x;
        x;
        if(mn>v[x]){
            mn= v[x];
            mnn=x;
        }
    }
    cout<<mnn<<endl;
    return 0;
}

