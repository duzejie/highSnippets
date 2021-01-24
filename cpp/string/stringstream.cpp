
//^%{  "title or name" id=20210123011  [string] [string,c++]

/*t{                //start to comment this snippet, support markdown format
stringstream 可用于类型转换和分割字符串
t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <iostream>
#include <sstream>
using namespace std;
//^}                //#end a collapsible part

int main(){
           
    std::stringstream ss ;
    //# 分割字符串
    string s="123 345 678";    
    int a, b, c;
    ss.clear();
    ss.str(s);
    ss >> a >> b >> c;
    std::cout<<"a "<<a<<" b "<<b<<" c "<<c<<std::endl;

    //类型转换
    double Number=0;       
    std::string str = "232.453452"; 
    ss.clear();
    ss.seekg(ss.beg);  //必要时需要更改字符流中指针位置
    std::cout<<ss.str()<<std::endl;
    ss << str;   
    std::cout<<ss.str()<<std::endl;
    ss >> Number;       
    std::cout<<Number+1<<std::endl;
    //
    std::string str1 = "12 345 56.6";
    ss.clear();
    ss.str(str1);
    ss >> Number;   
    std::cout<<Number+1<<std::endl;
    ss >> Number;   
    std::cout<<Number+1<<std::endl;

    std::cout<<ss.str()<<std::endl;
    return 0;  
}
//^%}                         // mark end

