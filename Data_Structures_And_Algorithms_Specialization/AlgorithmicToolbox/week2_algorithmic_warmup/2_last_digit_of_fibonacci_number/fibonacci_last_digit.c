#include <stdio.h>
#define MAXNUM 10000000

static int fibonacci_naive_one(int n);
static int fibonacci_naive_two(int n);
static int fibonacci_fast(int n);

int main()
{
	int n = 0;
	int res1 = 0;

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
	int index = 0;
	int f0 = 0;
	int f1 = 0;
	int f2 = 0;

	f0 = 0;
	f1 = 1;

	if (n == 0)
	{
		return f0;
	}
	else if (n == 1)
	{
		return f1;
	}
	else
	{
		for (index = 2; index <= n; ++index)
		{
			f2 = (f0 + f1) % 10;
		        f0 = f1;
			f1 = f2;	
		}
		return f2;
	}
}
