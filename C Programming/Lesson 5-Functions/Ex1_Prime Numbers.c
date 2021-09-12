#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printNumbers(int min, int max)
{
	for(min++; min<max; min++)
	{
		int i;
		for(i=2; i<=(int)sqrtf(min); i++)
		{
			if(min%i == 0)
				break;
		}
		if(i==(int)sqrtf(min)+1)
			printf("%d ", min);
	}
}

int main()
{
	printf("Enter two numbers(intervals): ");

	int min,max;

	fflush(stdout);
	scanf("%d %d", &min, &max);

	if(min>max)
		return 0;

	printf("Prime numbers between %d and %d are: ", min, max);
	printNumbers(min, max);

	return 0;
}
