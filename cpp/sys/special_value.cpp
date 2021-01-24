
//^%{  "c++特殊值" id=20210123014 [sys] [sys]

/*t{                //start to comment this snippet, support markdown format
c++特殊值，各种宏和内置值
t}*/
//#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <memory>
#include <iostream>
#include <string>
#include <any>

using namespace std;
//^}                //#end a collapsible part
int main(){
    std ::cout << __LINE__<<  __FILE__ <<std ::endl;
    std::cout << __cplusplus << std::endl;
    //auto ini = {1,2,3,4,5,6,"duzejie"};
    initializer_list<any> ini = {1,2,3,4,5,6};
    for(auto x:ini)
        cout<<any_cast<int>(x)<<endl;
    return 0;
}
//^%}                         // mark end

