#include <stdio.h>

static int fibonacci_huge_naive(long long n, int m);
static int fibonacci_huge(long long n, int m);
static int get_pisano_period(int m);

int main()
{
	long long n = 0;
	int m = 0;
	int res = 0;

	scanf("%lld%d", &n, &m);
	res = fibonacci_huge_naive(n, m);
	res = fibonacci_huge(n, m);
	printf("\n%d\n", res);

	return 0;
}

static int fibonacci_huge_naive(long long n, int m)
{
	int f0 = 0;
	int f1 = 1;
	int f2 = 0;
	long long index = 0;

	if (n < 2)
	{
		return n;
	}
	for (index = 2; index <= n; ++index)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}

	return f2%m;
}

static int fibonacci_huge(long long n, int m)
{
	int period = 0;
	int f0 = 0;
	int f1 = 1;
	int f2 = 0;
	int mod = 0;
	int index = 0;

	period = get_pisano_period(m);
	mod = n % period;

	if (mod < 2)
	{
		return mod;
	}

	for (index = 1; index < mod; index++)
	{
		f2 = (f0 + f1)%m;
		f0 = f1;
		f1 = f2;
	}

	return (f2 % m);
}

static int get_pisano_period(int m)
{
	int index = 0;
	int f0 = 0;
	int f1 = 1;
	int f2 = 0;
	int f3 = 0;

	for (index = 0; index < (m * m); index++)
	{
		f2 = (f0 + f1)%m;
		f0 = f1;
		f1 = f2;

		if ((f0 == 0) && (f1 == 1))
		{
			return (index + 1);
		}
	}
}

