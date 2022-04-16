#include <iostream>
#include <cstring>

int ia = 10086, ib = 10001;
double da = 1.0086, db = 1.0001;
char stra[] = "10086", strb[] = "10001";

template <typename T>
T max(T a, T b)
{
    return a < b ? b : a;
}

template<>
char* max(char* a, char* b)
{
    return strcmp(a, b) ? a : b;
}

int main()
{
    std::cout << "max(ia, ib) = " << max(ia, ib) << std::endl;
    std::cout << "max(da, db) = " << max(da, db) << std::endl;
    std::cout << "max(stra, strb) = " << max(stra, strb) << std::endl;
    // std::cout << "max(ia == ib, ia) = " << max(ia == ib, ia) << std::endl;
    std::cout << "10010 + max(ia, ib) = " << 10010 + max(ia, ib) << std::endl;
    std::cout << "max(ia++, ib++) = " << max(ia++, ib++) << ", ia = " << ia << ", ib = " << ib << std::endl;
    std::cout << "ia = " << ia << ", ib = " << ib << std::endl;

    return 0;
}
