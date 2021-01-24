
//^%{  "字符串转数字" id=20210123010  [string] [string,c]
/*t{                //start to comment this snippet, support markdown format
# C++字符串处理  
C++ 转字符串   
std::to_string();  
C++ stringstream 分割及类型转换  
## std::string字符串常用命令  
string s;//定义  
命令	        例子	                 作用
+	            x+y	                    将y接在x后面，返回新的字符串的值。
<,>,==，<=,>=,！=	x< y	             按位比较x,y的大小关系(和整形判断一样)，返回bool类型值。
=	            x=y	                    赋值,将y的值付给x。
find()	        s.find(s1,pos)	        字符串s从pos开始(包括pos)匹配，返回第一个查找到的第一个字符的位置。若找不到，返回string::npos。
empty()	        s.empty()	            返回bool类型值，判断s是否为空。
size()	        s.size()	            返回int类型值，字符串s的长度。
length()	    s.length()	            和size(),一样，可以互换。
erase()	        s.erase(pos,len)	    字符串s从pos开始(包括pos)，删除len个字符。
substr()	    s.substr(pos,len)	    返回字符串s从pos开始(包括pos)的len个字符。
replace()	    s.replace(pos,len,s1)	将字符串s从pos开始(包括pos)的len个字符替换成s1。
insert()	    s.insert(pos,s1)	    将字符串s1插入字符串s第pos个位置之前
clear()	        s.clear()	            清空字符串，也可以s=”“(双引号)。
swap()	        s.swap(s1)	            将s和s1交换。
c_str()	        printf(“%s”,s.c_str);	用scanf和printf时要用到，将字符串转成字符型数组。
t}*/
//#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
//^}                //#end a collapsible part

//char *或vector<char>转string

/* Convert a string to an integer.  */
int to_int(std::string str)
{
    return atoi(str.c_str());
}
/* Convert a string to a long integer.  */
int to_long_int(std::string str)
{
    return atol(str.c_str());
}
/* Convert a string to a long long integer.  */
int to_llong_int(std::string str)
{
    return atoll(str.c_str());
}
/* Convert a string to a floating-point number.  */
double to_float(std::string str)
{
    return atof(str.c_str());
}
/**
 *  @pEnd  Reference to an already allocated object of type char*, whose value is set by the function to the next character in str after the numerical value.
 *   This parameter can also be a null pointer, in which case it is not used.
 */
double to_double(std::string str, char **pEnd)
{
    return strtod(str.c_str(), pEnd);
}
double to_long_double(std::string str, char **pEnd)
{
    return strtold(str.c_str(), pEnd);
}

//run:
int main_to()
{
    string num = "12345646.3242345";
    cout<< to_int(num)<<endl;
    cout<< to_double(num,NULL)<<endl;
    return 0;
}

//^%}                         // mark end














