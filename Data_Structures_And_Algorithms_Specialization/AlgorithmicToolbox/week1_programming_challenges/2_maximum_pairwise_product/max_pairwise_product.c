#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 200000

static long long max_pairwise_prodcut(long long arr[], long long n);
static long long max_pairwise_prodcut_fast(long long arr[], long long n);

int main()
{
	long long n = 0;
	long long index = 0;
	long long arr[MAXNUM];
	long long res1 = 0;
	long long res2 = 0;

/* Stress testing the code. */
#if 0
	while (1)
	{
		n = rand() % 1000 + 2;
		printf("\n%d\n", n);
		for (index = 0; index < n; ++index)
		{
			arr[index] = rand() % 100000;
		}
		for (index = 0; index < n; ++index)
		{
			printf("%lld\t", arr[index]);
		}
		printf("\n");

		res1 = max_pairwise_prodcut(arr, n);
		res2 = max_pairwise_prodcut_fast(arr, n);

		if (res1 != res2)
		{
			printf("res1: %lld\t res2: %lld", res1, res2);
			break;
		}
		else
		{
			printf("\nOK\n");
		}
	}
#endif
#if 1
	scanf("%lld", &n);

	for (index = 0; index < n; ++index)
	{
		scanf("%lld", &arr[index]);
	}

	printf("\n%lld\n", max_pairwise_prodcut_fast(arr, n));
#endif

	return 0;
}

static long long max_pairwise_prodcut(long long arr[], long long n)
{
	long long index_one = 0;
	long long index_two = 0;
	long long max = 0;

	{
		for (index_one = 0; index_one < n; ++index_one)
		{
			for (index_two = index_one + 1; index_two < n; ++index_two)
			{
				if ((arr[index_one] * arr[index_two]) > max)
				{
					max = arr[index_one] * arr[index_two];
				}
			}
		}
	}

	return max;
}

static long long max_pairwise_prodcut_fast(long long arr[], long long n)
{
	long long index_one = 0;
	long long index_two = 0;
	long long max_one = -1;
	long long max_two = -1;
	long long result = 0;

	for (index_one = 0; index_one < n; ++index_one)
	{
		if ((max_one == -1) || (arr[index_one] > arr[max_one]))
		{
			max_one = index_one;
		}
	}

	for (index_two = 0; index_two < n; ++index_two)
	{
		if ((index_two != max_one) && ((max_two == -1) || (arr[index_two] > arr[max_two])))
		{
			max_two = index_two;
		}
	}

	return (arr[max_one] * arr[max_two]);

}
