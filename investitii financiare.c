#include <stdio.h>
#include <limits.h>

int partition(int INV[],int VAL[],int RISC[],int p,int r)
{
int x,i,j,aux,temp;
x=VAL[r]-RISC[r];
i=p-1;
for(j=p;j<=r-1;j++)
{
if(VAL[j]-RISC[j]>=x)
{
i++;

aux=VAL[i];
VAL[i]=VAL[j];
VAL[j]=aux;

aux=INV[i];
INV[i]=INV[j];
INV[j]=aux;

aux=RISC[i];
RISC[i]=RISC[j];
RISC[j]=aux;
}
}
temp=VAL[i+1];
VAL[i+1]=VAL[r];
VAL[r]=temp;

temp=INV[i+1];
INV[i+1]=INV[r];
INV[r]=temp;

temp=RISC[i+1];
RISC[i+1]=RISC[r];
RISC[r]=temp;
return i+1;
}

void sorteaza(int INV[],int VAL[],int RISC[],int p,int r)
{
int q;
if(p<r)
{
q=partition(INV,VAL,RISC,p,r);
sorteaza(INV,VAL,RISC,p,q-1);
sorteaza(INV,VAL,RISC,q+1,r);
}
return;
}
int maxim(int q,int p)
{
if(q>p) return q;
else return p;
}
int min(int q,int p)
{
if(q>p) return p;
else return q;
}

int solutie(int INV[],int VAL[],int RISC[],int rez[],int n)
{
int i,q,j,r[100],p=0;
r[0]=0;
for(j=1;j<=n;j++)
{
q=INT_MIN;
for(i=1;i<=j;i++) 
{

if(q<VAL[i]+r[j-i])
{
q=VAL[i]+r[j-i];
rez[j]=INV[i];
p=p+VAL[i]-RISC[i];
}
}
r[j]=q;

}
return p;
}
void main()
{
int i,n,INV[100],VAL[100],RISC[100],rez[100],profitmax;
printf("introduceti numarul investitiilor:");
scanf("%d",&n);

printf("introduceti valoarea fiecarei investitii si riscul acesteia(intre 1 si 10):");
for(i=1;i<=n;i++)
{
INV[i]=i;

printf("VAL[%d]=",i);
scanf("%d",&VAL[i]);

printf("RISC[%d]=",i);
scanf("%d",&RISC[i]);
}

sorteaza(INV,VAL,RISC,1,n);

profitmax=solutie(INV,VAL,RISC,rez,n);

printf("profitul maxim obtinut este:%d",profitmax);
printf("\ncombinatia de investitii este:");
for(i=1;i<=n;i++) printf("%d ",rez[i]);
}


