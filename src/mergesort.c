#include "mergesort.h"

void merge(int p, int q, int r, int v[])
{
	int i = p, j = q, k = 0;
	int w[r - p];

	while (i < q && j < r)
	{
		if (v[i] <= v[j])
		{
			w[k++] = v[i++];
		} else
		{
			w[k++] = v[j++];
		}
	}

	while (i < q)
	{
		w[k++] = v[i++];
	}

	while (j < r)
	{
		w[k++] = v[j++];
	}

	for (i = p; i < r; i++)
	{
		v[i] = w[i - p];
	}
}

/**
 * v[p..r-1]
 */
void merge_sort(int p, int r, int v[])
{
	if (p < r - 1)
	{
		int q = (p + r) / 2;

		merge_sort (p, q, v);
		merge_sort (q, r, v);
		merge (p, q, r, v);
	}
}
