#include "heapsort.h"

void heapify(int v[], int i, int n)
{
	int max = 2 * i + 1;
	int right = max + 1;

	if (max < n)
	{

		if (right < n && v[max] < v[right])
		{
			max = right;
		}

		if (v[max] > v[i])
		{
			swap(v, max, i);
			heapify(v, max, n);
		}
	}
}

void build_heap(int v[], int n)
{
	int i;
	for (i = (n / 2) - 1; i >= 0; i--)
	{
		heapify(v, i, n);
	}
}

void heap_sort(int v[], int n)
{
	build_heap(v, n);
	int i;

	for (i = n - 1; i > 0; i--)
	{
		swap(v, 0, i);
		heapify(v, 0, i);
	}
}
