#include <stdio.h>
#include <string.h>

int main()
{
	int count = 0;
	char arr[1000001];	
	gets(arr);
	const char* delimiter = " ";
	char* ptoken = strtok(arr, delimiter);
	while (ptoken!=NULL)
	{
		ptoken = strtok(NULL, delimiter);
		count++;	
	}
	printf("%d ", count);
}