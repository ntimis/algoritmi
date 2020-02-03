#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct elev
{
	int inaltime;
	int pozitie;   //pastreaza pozitia elevului din clasa (intre 1 si n)
	struct elev *next;
}tip_elev;

typedef struct lista
{
	tip_elev *head;
}tip_lista;

tip_elev* init_elev( int h,int k)
{
	tip_elev *x;
	x=(tip_elev*)malloc(sizeof(tip_elev));
	x->inaltime=h;
	x->pozitie=k;
	x->next=NULL;
	return x;
}

tip_elev* cauta_fata(int poz[],int v[], int hbaiat, int n)
{
	int i,x=0,j=0;
	tip_elev *elem;
	elem=NULL;
	for(i=n;i>=1;i--)
	{
		if(v[i]<hbaiat)	//dupa ce gasesc fata potrivita pt baiatul respectiv iau inaltimea fetei si pun infinit in locul acesteia pentru a nu o mai lua inca o data la o cautare viitoare.
		{				
			x=v[i];
			v[i]=INT_MAX;
			break;
		}
		else j++;
	}
	if(x==0 )
	{
		if(v[1]==INT_MAX || hbaiat<v[1])
		{
			printf("s-a gasit UN BAIAT fara pereche!\n");
			return NULL;
		}
	}
	else
	{
		elem=init_elev(x,poz[i]);
		return elem;
	}
}
int partition (int poz[],int v[],int p, int r)
{
	int x,i,j,aux,temp;
	x=v[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(v[j]<=x) 
		{
			i++;
			aux=v[i];
			v[i]=v[j];
			v[j]=aux;

			aux=poz[i];
			poz[i]=poz[j];
			poz[j]=aux;
		}
	}
	temp=v[i+1];
	v[i+1]=v[r];
	v[r]=temp;

	temp=poz[i+1];
	poz[i+1]=poz[r];
	poz[r]=temp;
	
	return i+1;
}


void sorteaza_inaltime(int poz[],int v[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(poz,v,p,r);
		sorteaza_inaltime(poz,v,p,q-1);
		sorteaza_inaltime(poz,v,q+1,r);
	}
	return;
}


void verifica_fete(int F[],int f)
{
	while(F[f]!=INT_MAX && f>0)
	{
		printf("s-a gasit O FATA fara pereche!\n");
		f--;
	}
	return;
}
	
void afiseaza_perechi(tip_lista L[],int n,int F[],int pozF[], int f)
{
	int i,j=1;
	for(i=1;i<=n;i++)
	{
		if(L[i].head->next!=NULL) 
		{
			printf("Perechea %d: pozitia %d cu pozitia %d.\n",j,L[i].head->pozitie,L[i].head->next->pozitie);
			j++;
		}
		if(L[i].head->next==NULL) printf("Baiatul de pe pozitia %d nu are pereche.\n",L[i].head->pozitie);
	}
	
	for(i=1;i<=f;i++)
	{
		if(F[i]!=INT_MAX) printf("Fata de pe pozitia %d nu are pereche.\n",pozF[i]);
	}
	
	return;
}

void main()
{
	int j,i,n,B[100],F[100],b,f,pozB[100],pozF[100];
	tip_lista L[100];
	tip_elev *elem;


	printf("introduceti numarul de elevi:");
	scanf("%d",&n);
	if(n%2==0) b=f=n/2;   //verific daca numarul elevilo e par->baieti=fete=n/2.
	else				  //daca nu, avem un baiat in plus.
	{
		b=n/2+1;
		f=n/2;
	}
	
	printf("introduceti inaltimile baietilor (in centimetri) :");
	j=1;
	for(i=1;i<=b;i++)
	{
		printf("B[%d]=",i);
		scanf("%d",&B[i]);
		pozB[i]=j;  //salvez pozitia baiatului in clasa
		j=j+2;
	}

	printf("introduceti inaltimile fetelor (in centimetri) :");
	j=2;
	for(i=1;i<=f;i++)
	{
		printf("F[%d]=",i);
		scanf("%d",&F[i]);
		pozF[i]=j;  //salvez pozitia fetei in clasa
		j=j+2;
	}
	printf("\n");
	
	sorteaza_inaltime(pozB,B,1,b);//sortez elevii dupa inaltime crescator
	sorteaza_inaltime(pozF,F,1,f);		//in acelasi timp, in ambele sortari, voi retine si pozitiile initiale ale elevilor in veztorii pozB si pozF.

	for(i=1;i<=b;i++)      //pun inaltimile baietilor in blocul de liste pe poziti de la 1 la nr baieti.
	{
		elem=init_elev(B[i],pozB[i]);
		L[i].head=(tip_elev*)malloc(sizeof(tip_elev));
		L[i].head=elem;
	}
		

	for(i=1;i<=b;i++)			//caut pereche pt baieti
	{
		elem=cauta_fata(pozF,F,B[i],f);
		(L[i].head)->next=elem;	
	}
	
	
	verifica_fete(F,f);	//verific daca e vreo fata fara pereche
	
	printf("\n");
	afiseaza_perechi(L,b,F,pozF,f);
}

		
