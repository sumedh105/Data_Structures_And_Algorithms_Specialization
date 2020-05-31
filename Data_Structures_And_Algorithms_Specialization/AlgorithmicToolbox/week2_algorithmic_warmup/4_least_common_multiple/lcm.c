#include <stdio.h>

static long long lcm_naive(long long a, long long b);
static long long lcm_fast(long long a, long long b);
static long long gcd(long long a, long long b);

int main()
{
	long long a = 0;
	long long b = 0;
	long long res = 0;

	scanf("%lld%lld", &a, &b);
	//res = lcm_naive(a, b);
	res = lcm_fast(a, b);

	printf("\n%lld\n", res);

	return 0;
}

static long long lcm_naive(long long a, long long b)
{
	long long index = 0;

	for (index = 1; index < (a * b); ++index)
	{
		if ((index%a == 0) && (index%b == 0))
		{
			return index;
		}
	}
}

static long long lcm_fast(long long a, long long b)
{
	return ((a * b) / gcd(a, b));
}

static long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}
