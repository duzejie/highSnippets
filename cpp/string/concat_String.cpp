
//^%{  "concat to a string" id=20210123006 [string] [string,c++]

/*t{                //start to comment this snippet, support markdown format
concat to a string
t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <iostream>
#include <string.h>
#include <sstream>
#include  <io.h>
#include <string>
//^}                //#end a collapsible part
using namespace std;
template<typename OS,typename T>
static void ostr(OS& o,T t)
{
    o << t;
}
template<typename... ARG>
auto makeString(ARG... arg)->string
{
    ostringstream os;
    int arr[] = { (ostr(os,arg),0)...};
    arr[0]=0;
    return os.str();
}
//run:
int main()
{
//#ifdef _MSC_VER
//    std::cerr<< (strrchr(__FILE__, '\\') + 1);
//#else
    std::cerr<< __FILE__;
//#endif
    cout << "Hello World!" << endl;
    cout << makeString(1, 2.3, "my name is", '\t',"lc") << endl;
    return 0;
}
//^%}                         // mark end

