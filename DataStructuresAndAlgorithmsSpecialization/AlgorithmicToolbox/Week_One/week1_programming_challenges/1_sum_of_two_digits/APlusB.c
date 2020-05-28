#include <stdio.h>

static int sum_of_two_digits(int, int);

int main()
{
	int digit_one = 0;
	int digit_two = 0;
	
	scanf("%d%d", &digit_one, &digit_two);

	printf("%d", sum_of_two_digits(digit_one, digit_two));

	return 0;
}

static int sum_of_two_digits(int digit_one, int digit_two)
{
	return (digit_one + digit_two);
}
