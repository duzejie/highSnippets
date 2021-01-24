
//^%{  "折叠表达式" id=20210123015 [template] [折叠表达式]

/*t{                //start to comment this snippet, support markdown format
折叠表达式
t}*/
//#end to comment this snippet, support markdown format

#include <iostream>
#if __cplusplus >= 201402L
#elif __cplusplus >= 201102L
#include <memory>
template <typename T, typename... Args>
std ::unique_ptr<T> make_unique(Args &&... args)
{
    return std ::unique_ptr<T>(new T(std ::forward<Args>(args)...));
}
#endif
//-------------------------------------------------------
#if __cplusplus >= 201703L
//折叠表达式
template <typename... T>
auto sum(T... t)
{
    return (t + ...);
}
//std ::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std ::endl;
#elif __cplusplus >= 201103L
#endif
//-------------------------------------------------------
#if __cplusplus >= 201703L
template <typename T0, typename... T>
void print(T0 t0, T... t)
{
    std ::cout << t0;
    if constexpr (sizeof...(t) >= 1)
    {
        std ::cout << " ";
        print(t...);
    }
}
#elif __cplusplus >= 201103L
template <typename T>
void print(T x)
{
    std ::cout << x;
}
template <typename T, typename... Args>
void print(T x, Args... args)
{
    //std :: cout << sizeof ...( args ) << std :: endl ;
    std ::cout << x << " ";
    print(args...);
}
#endif
//run
using namespace std;
int main()
{
    print(1, "23", "ty\n");
    print(1, 2, 3, "34www\n");
    std::cout << __cplusplus << std::endl;
    std ::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std ::endl;
    std ::cout << __LINE__ << __FILE__ << std ::endl;
    auto pointer = make_unique<int>(10);
}
//^%}                         // mark end

