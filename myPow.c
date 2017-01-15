#include <stdio.h>
#include <limits.h>

double myPow(double x, int n) {
	if (n == 0) return 1.0;
	if (n < 0)  {
		x = 1 / x;
		if (n == INT_MIN) {
			++n;
			x *= x;
	}
		n *= -1;
	}
	return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}

int main()
{
	int n = INT_MIN;
	printf("%d, %.9f\n", n, myPow(2.0000, -2147483648));
	return 0;
}
