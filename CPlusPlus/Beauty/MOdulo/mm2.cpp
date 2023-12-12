#include <stdio.h>
int NextPrime(int);
int IsPrime(int);
int main()
{
	int l,k,j,t,i;
	char s[500];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&l);
		scanf("%s",&s);
		for(j=0;j<l;j++)
		{
			i=s[j];
			if(i==65 || i==66 || i==67 || i==68 || i==69)
			s[j]=67;
			else if(i==70 || i==72 || i==71)
			s[j]=71;
			else if(i==73 || i==74 || i==75 || i==76)
			s[j]=73;
			else if(i==77 || i==78 || i==79 || i==80 || i==81)
			s[j]=79;
			else if(i==82 || i==83 || i==84 || i==85 || i==86)
			s[j]=83;
			else if(i==87 || i==88 || i==89 || i==90)
			s[j]=89;
			else if(i==97 || i==98 || i==99 )
			s[j]=97;
			else if(i==100 || i==101 || i==102 )
			s[j]=101;
			else if(i==103 || i==104 || i==105 )
			s[j]=103;
			else if(i==106 || i==107 || i==108)
			s[j]=107;
			else if(i==109 || i==110 || i==111 )
			s[j]=109;
			else if(i==112 || i==113 || i==114 ||i==115 || i==116 || i==117||i==118 || i==119 || i==120||i==121 || i==122 )
			s[j]=113;
			else if(i==94 || i==95)
			s[j]=97;
			else if(i==91 || i==92 || i==93)
			s[j]=89;
			else if(i==123 || i==124 || i==125)
			s[j]=113;
			else
			s[j]=67;
			}
			puts(s);
	}
	return 0;
}
int NextPrime(int n)
{
	do n++;
	while(!IsPrime(n));
	return(n);
}
int IsPrime(int n)
{
	int i;
	for(i=2;i<n-1;i++)
	{
		if(n%i==0)
		{
			return(0);
		}
		
	}
	return(1); 
}
