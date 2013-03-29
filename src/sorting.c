#include <time.h>

#include "quicksort.h"
#include "heapsort.h"
#include "selectionsort.h"
#include "mergesort.h"

int main(int argc, char **argv)
{

	enum algorithms { qs, hs, ss, ms };

	clock_t begin_p, end_p, begin_alg, end_alg;
	double p_time_spent, a_time_spent;

	int n, i, alg, po = 0, s = 0;

	if (argc == 1)
	{
		printf("What is the vector's size? ");
		scanf("%d", &n);

		if (n <= 0)
		{
			printf("Wrong vector size!\n");
			exit(1);
		}

		printf("Please, choose an algorithm. (1)-quick (default), (2)-heap,(3)-selection,(4)-merge. ");
		scanf("%d", &alg);

		printf("Print the vectors (1)-Yes, (0)-No? Default: (0).");
		scanf("%d", &po);

	} else if (argc == 5)
	{

		if (sscanf(argv[1], "%d", &n) != 1)
		{
			printf("Vector size scanf failed.\n");
			exit(-1);
		}

		if (sscanf(argv[2], "%d", &alg) != 1)
		{
			printf("Algorithm type scanf failed.\n");
			exit(-1);
		}

		if (sscanf(argv[3], "%d", &po) != 1)
		{
			printf("Print option scanf failed.\n");
			exit(-1);
		}

		if (sscanf(argv[4], "%d", &s) != 1)
		{
			printf("sleep time scanf failed.\n");
			exit(-1);
		}
	}else
	{
		printf("Usage sorting <vector size> <algorithm> <print> <sleep time> \n");
		exit(-1);
	}

	int *v;
        v = (int *)malloc(n * sizeof(int));

	begin_p = clock();

	srand(time(NULL ));
	for (i = 0; i < n; i++)
	{
		v[i] = (int) rand() % 1000;
	}

	printf("Going to sleep\n");
 	sleep(s);
	printf("I am awake\n");

	if (po)
	{
		printf("The unsorted vector is:\n");
		print(v, n);
	}

	begin_alg = clock();
	switch (alg - 1)
	{
	case hs:
		heap_sort(v, n);
		break;
	case ss:
		selection_sort(v, n);
		break;
	case ms:
		merge_sort(0, n, v);
		break;
	default:
		quick_sort(v, 0, n - 1);
		break;
	}
	end_alg = clock();

	a_time_spent = (double) (end_alg - begin_alg) / CLOCKS_PER_SEC;

	if (po)
	{
		printf("Vector sorted in %f seconds:\n", a_time_spent);
		print(v, n);
	}

	end_p = clock();
	p_time_spent = (double) (end_p - begin_p) / CLOCKS_PER_SEC;

	printf("Done in %f seconds!\n", p_time_spent);

        free(v);

	return 0;
}
