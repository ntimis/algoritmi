#include <stdio.h>
int partition(int soldat[],int p, int r)
{
	int i,j,x,aux;
	x=soldat[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(soldat[j]>=x)
		{
			i++;
			aux=soldat[i];
		soldat[i]=soldat[j];
		soldat[j]=aux;
		}
	}
	aux=soldat[i+1];
	soldat[i+1]=soldat[r];
	soldat[r]=aux;
	
	return i+1;
}

void sorteaza(int soldat[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(soldat,p,r);
		sorteaza(soldat,p,q-1);
		sorteaza(soldat,q+1,r);
	}
}

void creaza_matrice(int soldat[],int s[100][100],int n)
{
	int i,j,k=1,m;
	m=n*n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{	
			s[i][j]=soldat[k];
			k++;
		}
}

void print_matr(int s[100][100],int n)
{
	int i,j;
	printf("Soldatii sunt \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
}



void main()
{
	int n,m,i,j,s[100][100],soldat[1000];

	printf("introduceti numarul soldatilor: ");
	scanf("%d",&n);

	m=n*n;

	printf("introduceti inaltimile soldatilor in centimetri:\n");
	for(i=1;i<=m;i++)
	{
		printf("soldat[%d]=",i);
		scanf("%d",&soldat[i]);
	}

	sorteaza(soldat,1,m);

	creaza_matrice(soldat,s,n);

	print_matr(s,n);

}
