
//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif




#define pc putchar_unlocked
inline void inp(int *ar)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*ar=0;
	while (c>33)
	{
		*ar=*ar*10+c-'0';
		c=getchar_unlocked();
	}
}

inline void writeInt (int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) { pc('0'); pc(' '); return ;}
	while ((rev % 10) == 0) { count++; rev /= 10;}
	rev = 0;
	while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
	while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
	while (count--) pc('0');
	pc(' ');
	return ;
}
#define si(n) inp(&n)
#define pi(n) writeInt(n)





typedef struct node{

    int val,prior,size;
    struct node *l,*r;

}node;


typedef node* pnode;

int sz(pnode t){

    return t?t->size:0;

}

void upd_sz(pnode t){

    if(t)t->size=sz(t->l)+1+sz(t->r);

}

void split(pnode t,pnode &l,pnode &r,int pos,int add=0){

    if(!t)return void(l=r=NULL);

    int curr_pos = add + sz(t->l);

    if(curr_pos<=pos)  

        split(t->r,t->r,r,pos,curr_pos+1),l=t;

    else

       split(t->l,l,t->l,pos,add),r=t;

    upd_sz(t);

}

void merge(pnode &t,pnode l,pnode r) { 

    if(!l || !r) t = l?l:r;

    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;

    else    merge(r->l,l,r->l),t=r;

    upd_sz(t);

}

const int N=1e5+5;
int a[N];

void init(pnode &t,int x)
{
	t->prior=rand();
	t->val=x;
	t->size = 1;
	t->l=t->r=NULL;
}

void print(pnode t)
{
	if(!t) return;
	print(t->l);
	pi(a[t->val]);
	print(t->r);
}


int main()
{
int r,n,m,q,l,k,ans,i,j,res=0,fl;
pnode t;
//t=1;
//cin>>(t);
	cin>>n>>q;
	Loop(i,n)
	{
		si(a[i]);
		pnode it=new node;
		init(it,i);
		if(i == 1)
			t=it;
		else
			merge(t,t,it);
	}

	int type;

	pnode ll,rr,ll2,rr2,tt,tt2;
	while(q--)
	{
		si(type);
		si(l);
		si(r);
		if(type == 1)
		{
			if(l == 1)
				continue;


			split(t,ll,rr,l-2); // part1
			split(rr,ll2,rr2,r-l); // part2
		
			// parts ll1 , ll2 , rr
			merge(tt,ll2,ll);
			merge(tt,tt,rr2);
		}
		else
		{
			if(r == n)
				continue;
			split(t,ll,rr,r-1);
			split(ll,ll2,rr2,l-2);
			merge(tt,ll2,rr);
			merge(tt,tt,rr2);
		}

		t=tt;
	}
	print(t);
	cout<<'\n';





return 0;
}

