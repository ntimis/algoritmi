#include <stdio.h>
void printeaza(int s[],int x,int n)
{
	int i;
	printf("Solutia %d:",x);
	for(i=1;i<=n;i++)
			{
				if(s[i]!=0 && s[i]!=n)
				printf("%d ",s[i]);
				if(s[i]==n)
					printf("%d 0",s[i]);
			}
	printf("\n");
}

int verif_cond(int v[],int n,int k)
{
	int i,ok;
	ok=1;
	for(i=1;i<=n;i++)
			{
				if(v[i]==v[k] && i!=k) ok=0;  
			}
	return ok;
}
int calc_suma(int v[],int n)
{
	int i,s=0;
	for(i=1;i<=n;i++)
	{
		s=s+v[i];
	}
	return s;
}

void main()
{
	int i,ok, n,k=1,s=0,v[10000],x=0;
	printf("introduceti numarul dorit:");
	scanf("%d",&n);
	for(i=1;i<=n;i++) v[i]=0;
	while(k>0)
	{	
		if(s==n)
		{
			x++;
			printeaza(v,x,n);
			v[k]=0;
			k=k-1;
			s=0;
		}
		else
		{

			v[k]++;
			ok=verif_cond(v,n,k);
			if(ok==1)
			{	
				s=calc_suma(v,n);
				if(s<=n) k++;
				else
				{
					v[k]=0;
					k--;
				}
			}
			if(ok==0) s=0;		
		}
	}
}


	
