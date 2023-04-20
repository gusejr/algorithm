#include <stdio.h>
#include <string.h>

int main()
{
	int n, x;
	char s[21];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &x,s,sizeof(s));
		int len = strlen(s);
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < x; k++)
			{
				printf("%c", s[j]);
			}

		}
		printf("\n");
	}
}