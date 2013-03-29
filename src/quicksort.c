#include "quicksort.h"

int partition(int v[], int p, int r)
{
	int c = v[r], j = p, k;
	for (k = p; k < r; k++)
	{
		if (v[k] < c) {
			swap(v, j, k);
			j++;
		}
	}
	v[r] = v[j];
	v[j] = c;
	return j;
}

void quick_sort(int v[], int i, int f)
{
	if (f > i)
	{
		int k = partition(v, i, f);
		quick_sort(v, i, k - 1);
		quick_sort(v, k + 1, f);
	}
}
