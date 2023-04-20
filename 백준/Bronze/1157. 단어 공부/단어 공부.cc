#include <stdio.h>
#include <string.h>

int main()
{
	char word[1000001];
	int max = 0, count = 0, arr[26] = { 0 }, num = 0;
	scanf("%s", word);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if ('a' <= word[i] && word[i] <= 'z')
		{
			word[i] = word[i] - 32;
		}
	}
	for (int i = 0; i < len; i++)
	{
		arr[word[i] - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			num = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i])
		{
			count++;
		}
	}
	if (count == 1)
	{
		printf("%c", num + 65);
	}
	else if (count > 1)
	{
		printf("?");
	}
}