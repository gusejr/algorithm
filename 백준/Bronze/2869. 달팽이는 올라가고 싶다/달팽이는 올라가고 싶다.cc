#include <stdio.h>

int main()
{
	double a, b, v, sum = 0;
	scanf("%ld %ld %ld", &a, &b, &v);
	sum = (v - b) / (a - b);
	if (int(sum)<sum)
	{
		sum = sum + 1;
		printf("%d", int(sum));
	}
	else
	{
		printf("%d", int(sum));
	}
}