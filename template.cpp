#include <iostream>
#include <cstring>

int ia = 10086, ib = 10001;
double da = 1.0086, db = 1.0001;
char stra[] = "10086", strb[] = "10001";

class MyClass
{
public:
    int n;
    bool operator>(const MyClass &lhs) { return n < lhs.n; }
    friend std::ostream& operator<<(std::ostream &os, const MyClass &lhs)
    {
        os << "MyClass::n = " << lhs.n;
        return os;
    }
};
MyClass mca{10086}, mcb{10001};

template <typename From, typename To>
struct Convertible
{
    static void auxiliary(To);
    template <typename U, typename = decltype(auxiliary(std::declval<U>()))>
    static std::true_type test(void*);
    template <typename U>
    static std::false_type test(...);

    static constexpr bool value = decltype(test<From>(nullptr))::value;
};

template<bool condition, typename IfType, typename ElseType>
struct IfElse
{
    using Type = IfType;
};

template<typename IfType, typename ElseType>
struct IfElse<false, IfType, ElseType>
{
    using Type = ElseType;
};

template <typename T1, typename T2>
struct CommonType
{
    using Convert2T1 = Convertible<T2, T1>;
    using Convert2T2 = Convertible<T1, T2>;
    static_assert(Convert2T1::value || Convert2T2::value, "No conversion between T1 and T2");
    static_assert(!(Convert2T1::value && Convert2T2::value), "Bidirectional conversion between T1 and T2");
    using Type = typename IfElse<Convert2T1::value, T1, T2>::Type;
};

template <typename T>
struct CommonType<T, T>
{
    using Type = T;
};

template<typename T>
struct LessThanComparable
{
    template <typename U, typename = decltype(std::declval<U>() < std::declval<U>())>
    static std::true_type test(void*);
    template <typename U>
    static std::false_type test(...);

    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <typename T, typename LTC = LessThanComparable<T>>
T max(T a, T b)
{
    static_assert(LTC::value, "T is not less than comparable.");
    return a < b ? b : a;
}

template <typename T1, typename T2, typename R = CommonType<T1, T2>,
    typename LTCR = LessThanComparable<R>>
typename R::Type max(T1 a, T2 b)
{
    static_assert(LTCR::value, "Common type is not less than comparable.");
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
    std::cout << "10010 + max(ia, ib) = " << 10010 + max(ia, ib) << std::endl;
    std::cout << "max(ia++, ib++) = " << max(ia++, ib++) << ", ia = " << ia << ", ib = " << ib << std::endl;
    std::cout << "ia = " << ia << ", ib = " << ib << std::endl;

    // test for bidirectional convertible types
    // std::cout << "max(ia == ib, ia) = " << max(ia == ib, ia) << std::endl;
    // std::cout << "max(ia, ia == ib) = " << max(ia, ia == ib) << std::endl;

    // test for not convertible types
    // std::cout << "max(ia, mcb) = " << max(ia, mcb) << std::endl;
    // std::cout << "max(mca, ib) = " << max(mca, ib) << std::endl;

    // test for not less than comparable types
    // std::cout << "max(mca, mcb) = " << max(mca, mcb) << std::endl;

    return 0;
}
