#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


double myPow(double x, int n) {
    double ret = 1.0;

    if (n > 0)
    {
        for (int i = 3; i <= n; i += 3)
        {
            ret = ret * x * x * x;
        }
        for (int i = n % 3; i > 0; i--)
        {
            ret *= x;
        }
        return ret;
    }

    for (int i = 0; -i > n; i += 3)
    {
        ret = ret * x * x * x;
    }

    for (int i = (-n) % 3; i > 0; i--)
    {
        ret *= x;
    }
    ret = 1.0 / ret;

    return ret;
}
int main()
{
    double ret = myPow(2.1, 3);
    printf("%lf", ret);
    return 0;
}