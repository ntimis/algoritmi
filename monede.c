#include <stdio.h>

	int main()
	{
		int n, suma=100, p;
		int b[100], i;
			
		printf("n="); scanf("%d", &n);
						
		for(i=0; i<n; i++)
		{
			printf("b[%d]=", i); scanf("%d", &b[i]);
		}
		printf("Introduceti suma de bani:"); scanf("%d", &suma);
		for(i=0; i<n; i++)
		{
			p=suma/b[i];
			suma=suma%b[i];
			
			printf("suma are %d bancnote de %d lei\n", p, b[i],suma);
		}
			

		return 0;

	}
