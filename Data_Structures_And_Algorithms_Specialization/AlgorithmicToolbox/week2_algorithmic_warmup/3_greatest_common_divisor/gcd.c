#include <stdio.h>

static int gcd_naive(long long a, long long b);
static int gcd_fast(long long a, long long b);

int main()
{
	long long a = 0;
	long long b = 0;
	int res1 = 0;

	scanf("%lld%lld", &a, &b);
	//res1 = gcd_naive(a, b);
	res1 = gcd_fast(a, b);
	printf("%d\n", res1);

	return 0;
}

static int gcd_naive(long long a, long long b)
{
	long long index = 0;
	int gcd = 0;

	for (index = b; index >= 0; --index)
	{
		if (((a % index) == 0) && ((b % index) == 0))
		{
			gcd = index;
			break;
		}
	}

	return gcd;
}

static int gcd_fast(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd_fast(b, (a % b));
	}
}
