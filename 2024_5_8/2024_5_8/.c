#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



int main()
{
	double huigourenshu = 0.0;
	double xiao = 0.0;
	double zui = 0.0;

	for (int i = 0; i < 10; i++)
	{
		int c = scanf("%lf %lf", &xiao, &zui);
		huigourenshu = (15 * zui - xiao * 0.4) / 90;
		printf("%d    %lf\n", i, huigourenshu);
	}

	return 0;
}