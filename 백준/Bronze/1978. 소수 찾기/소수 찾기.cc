#include <stdio.h>

int main()
{
	int n, primenumber[101] = { 0 }, delnum[1001] = { 0 }, mul = 0, count = 0, idx, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &primenumber[i]);  //입력받음
		idx = primenumber[i];  //입력받으거 옮겨줌
		delnum[idx]++;		
	}
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			mul = i * j;
			if (mul > 1000)
			{
				mul = 0;
			
			}			
			delnum[mul] =  0 ;
		}
	}
	for (int i = 0; i <= 1000; i++)
	{
		delnum[0] = 0;
		delnum[1] = 0;
		if (delnum[i] > 0)
		{
			sum = sum + delnum[i];
		}
	}
	printf("%d", sum);
}