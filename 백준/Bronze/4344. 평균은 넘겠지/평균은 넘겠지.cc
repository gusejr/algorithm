#include <stdio.h>

double average(double people,double *score)
{
	double sum = 0, sum1 = 0, count = 0, rate1=0;
	scanf("%lf", &people);
	for (int j = 0; j < people; j++)
	{
		scanf("%lf", &score[j]);
		sum = sum + score[j];			
	}
	sum1 = sum / people;
	for (int j = 0; j < people; j++)
	{	
		if (score[j] > sum1)
		{
			count++;
		}
	}
	rate1 = count / people*100;
	return rate1;	
}
int main()
{
	int n=0;
	double  people=0, rate, sum, score[1000], sum1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		rate = average(people, score);		
		printf("%.3lf\%%\n", rate);
	}		
}