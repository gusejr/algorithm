#include <stdio.h>

int main()
{
	int N;
	int tile[1001] = { 0 };
	scanf("%d", &N);
	tile[1] = 1;
	tile[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
	}
	printf("%d", tile[N]);
}