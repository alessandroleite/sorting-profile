#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"

void swap(int v[], int a, int b)
{
	int t = v[a];
	v[a] = v[b];
	v[b] = t;
}


void print(int v[], int size)
{
	int i = 0;

	printf("[");
	for (; i < size; i++)
	{
		printf("%d ", v[i]);
	}
	printf("]\n");
}
