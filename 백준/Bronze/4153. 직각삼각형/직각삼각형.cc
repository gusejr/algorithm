#include <stdio.h>

int main()
{
	int a, b, c, mul1 = 0, mul2 = 0,max=30000;
	for (;;)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (a >= b && c)
		{
			mul1 = a * a;
			mul2 = (b * b) + (c * c);
		}
		else if (b >= c && a)
		{
			mul1 = b * b;
			mul2 = (a * a) + (c * c);
		}
		else if (c >= a && b)
		{
			mul1 = c * c;
			mul2 = (a * a) + (b * b);
		}
		if (mul1 == mul2)
		{
			printf("right\n");
		}
		else if(mul1 >= mul2 || mul1 <= mul2)
		{
			printf("wrong\n");
		}
	}
	return 0;
}