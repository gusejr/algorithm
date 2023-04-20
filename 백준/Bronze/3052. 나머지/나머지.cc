#include <stdio.h>

int main()
{
	int arr[10], num[42] = {0}, count = 0, n;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] = arr[i] % 42;
		n = arr[i];
		num[n]++;
	}
	for (int i = 0; i < 42; i++)
	{
		if (num[i] != 0)
		{
			count++;
		}
	}
	printf("%d", count);
}