#include <stdio.h>
char *cul[]={"alb","galben","rosu","albastru"};
int k,st[4];
void init(int k)
{
	st[k]=-1;
}
void tipar()
{
	int i;
	for(i=0;i<3;i++)
		printf("%s ",cul[st[i]]);
	printf("\n");

}
int succesor(int k)
{
	if(st[k]<3)
	{
		st[k]++;
		return 1;
	}
	else return 0;
}
int valid(int k)
{
	int ev=1,i;
	if(k==1)
		if((st[k]!=1)&&(st[k]!=3))
			ev=0;
	for(i=0;i<k;i++)
		if(st[i]==st[k])
			ev=0;
	return ev;
}
void back(int k)
{
	if(k==3)
		tipar();
	else
	{
		init(k);
		while(succesor(k))
			if(valid(k))
				back(k+1);
	}
}
int main()
{
	back(0);
}
