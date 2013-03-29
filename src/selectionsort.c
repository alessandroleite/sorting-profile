#include "selectionsort.h"

void selection_sort(int v[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < n; j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		swap(v, i, min);
	}
}

