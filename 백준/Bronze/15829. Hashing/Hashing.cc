#include <stdio.h>
#include <math.h>
int main()
{
	int L, newL, division;
	long long sum = 0, newnum = 0;
	char arr[51] = { 0 };
	scanf("%d %s", &L, arr);
	for (int i = 0; i < L; i++) //문자열 증가
	{
		newL = arr[i] - 96;
		if (i == 0)
		{
			sum = sum + newL * 1;
		}
		else
		{
			newnum = newL * 31;
			newnum = newnum % 1234567891;
		}
		for (int j = 0; j < i - 1; j++)  //31 곱하기
		{
			newnum = newnum * 31;
			newnum = newnum % 1234567891;
		}
		sum = sum + newnum;
	}
	printf("%lld", sum);
}