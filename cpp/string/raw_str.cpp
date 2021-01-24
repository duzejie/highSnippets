
//^%{  "原始字符串字面量" id=20210123008 [string] [string,c++]

/*t{                //start to comment this snippet, support markdown format
C++11 原始字符串字面量
原始字面量很容易理解，即不进行转义的完整字符串。
定义1 ANSI：    R “xxx(raw string)xxx” 
定义1 Unicode： LR “xxx(raw string)xxx” 
其中，原始字符串必须用括号（）括起来，括号的前后可以加其他字符串，所加的字符串会被忽略，并且加的字符串必须在括号两边同时出现。
t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <iostream>
#include <string>
//^}                //#end a collapsible part
int main_r() {
    // 一个普通的字符串，'\n'被当作是转义字符，表示一个换行符。
    std::string normal_str = "First line.\nSecond line.\nEnd of message.\n";

    // 一个raw string，'\'不会被转义处理。因此，"\n"表示两个字符：字符反斜杠 和 字母n。
    std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";

    std::cout << normal_str << std::endl;
    std::cout << raw_str << std::endl;
    std::cout << R"foo(Hello, world!)foo" << std::endl;

    // raw string可以跨越多行，其中的空白和换行符都属于字符串的一部分。
    std::cout <<R"(
                   Hello,
                   world!
                   )" << std::endl;

    std::wstring ws = LR"abcdefg(杜泽杰duzejie)abcdefg";
    std::wcout<<ws<<std::endl;
    std::wcout<<ws[2]<< std::endl;
    std::cout<<ws.c_str()<<std::endl;
  
    return 0;
}
//^%}                         // mark end
