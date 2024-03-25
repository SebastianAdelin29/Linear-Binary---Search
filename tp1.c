#include<stdlib.h>
#include<stdio.h>

void interschimbare(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void descrescator(int v[], int n) 
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				interschimbare(&v[i], &v[j]);
			}
		}
	}
}

int linear_search(int x, int v[])
{
	int n = sizeof(v);
	for (int j = 0; j < n; j++)
	{
		if (v[j] == x)
			printf("\nElementul cu indexul %d", j);
	}
	return 0;
}

int binary_search(int x, int v[], int n)
{
	int stanga = 0;
	int dreapta = n - 1; 

	while (stanga <= dreapta) 
	{
		int k = (stanga + dreapta) / 2;
		if (v[k] == x) {
			printf("\nElementul cu indexul %d ", k);
			return 1;
		}
		else if (v[k] < x)
			dreapta = k - 1; 
		else
			stanga = k + 1; 
	}
	return 0;
}


int main()
{
	int v[255], n;
	printf("Specificati nr de elemente ale vectorului: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nv[%d]=", i);
		scanf("%d", &v[i]);
	}
	descrescator(v, n);
	int x; //variabila pe care o cautam in vector
	printf("\nAlegeti x= ");
	scanf("%d", &x);	
	printf("\n1->Cautarea liniara\n2->Cautarea binara\n3->Exit");
	while (1)
	{
		int optiune;
		printf("\noptiune: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 1:
			linear_search(x, v);
				break;
		case 2:binary_search(x,v,n);
			break;
		case 3:
			exit(0);
		}
	}
}