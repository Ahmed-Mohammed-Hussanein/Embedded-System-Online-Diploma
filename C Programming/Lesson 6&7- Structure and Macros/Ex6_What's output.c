#include <stdio.h>
#include <stdlib.h>

union job{
	char name[32];
	float salary;
	int worker_no;
} u;

struct job1{
	char name[32];
	float salary;
	int worker_no;
} s;

int main()
{
	printf("size of union = %d\n", sizeof(u));
	printf("size of structure = %d\n", sizeof(s));
	return 0;
}