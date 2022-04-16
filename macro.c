#include <stdio.h>
#include <string.h>

int ia = 10086, ib = 10001;
double da = 1.0086, db = 1.0001;
char stra[] = "10086", strb[] = "10001";

int max_int(int a, int b)
{
    return a < b ? b : a;
}

double max_double(double a, double b)
{
    return a < b ? b : a;
}

char* max_str(char* a, char* b)
{
    return strcmp(a, b) > 0 ? a : b;
}

int main()
{
    printf("%d\n", max_int(ia, ib));
    printf("%.4lf\n", max_double(da, db));
    printf("%s\n", max_str(stra, strb));

    return 0;
}
