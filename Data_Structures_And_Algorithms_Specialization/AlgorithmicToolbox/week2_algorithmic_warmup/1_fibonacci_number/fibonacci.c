#include <stdio.h>
#define MAXNUM 45

static int fibonacci_naive_one(int n);
static int fibonacci_naive_two(int n);
static int fibonacci_fast(int n);

int main()
{
	int n = 0;
	int res1 = 0;
	int res2 = 0;

	scanf("%d", &n);

	res1 = fibonacci_naive_two(n);
	printf("%d\n", res1);
}

static int fibonacci_naive_one(int n)
{
	if ((n == 0) || (n == 1))
	{
		return n;
	}
	else
	{
		return (fibonacci_naive_one(n - 1) + fibonacci_naive_one(n - 2));
	}
}

static int fibonacci_naive_two(int n)
{
	int arr[MAXNUM] = {0};
	int index = 0;

	arr[0] = 0;
	arr[1] = 1;

	if (n == 0)
	{
		return arr[0];
	}
	else if (n == 1)
	{
		return arr[1];
	}
	else
	{
		for (index = 2; index <= n; ++index)
		{
			arr[index] = (arr[index - 1] + arr[index - 2]); 
		}
		return arr[index - 1];
	}
}
