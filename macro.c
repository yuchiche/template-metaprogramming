#include <stdio.h>
#include <string.h>

int ia = 10086, ib = 10001;
double da = 1.0086, db = 1.0001;
char stra[] = "10086", strb[] = "10001";

#define max(a, b) a < b ? b : a

int main()
{
    printf("max(ia, ib) = %d\n", max(ia, ib));
    printf("max(da, db) = %.4lf\n", max(da, db));
    printf("max(stra, strb) = %s\n", max(stra, strb));
    printf("max(ia == ib, ia) = %d\n", max(ia == ib, ia));

    return 0;
}
