#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int* pa = NULL;
	pa = (int*)malloc(5000);
	if (pa == NULL)
	{
		perror("malloc");
		return 1;
	}

	for (int i = 0; i < 100; i++)
	{
		pa[i] = i;
	}

	int* ps = NULL;
	ps = (int*)realloc(pa, 100000);
	if (ps == NULL)
	{
		perror("realloc");
		return 1;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("%d", pa[i]);
	}

	printf("\n%p", pa);
	printf("\n%p", ps);


	free(pa);
	free(ps);
	pa = NULL;
	ps = NULL;

	return 0;
}
