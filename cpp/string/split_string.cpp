//^%{  "字符串分割" id=20210123009  [string] [string,c++]
/*t{                //start to comment this snippet, support markdown format
字符串分割函数,类似python的split
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

vector<string> split(char s[], const char *delim)
{
    char *token = strtok(s, delim);
    vector<string> vstr;
    while (token != NULL)
    {
        string stmp = token;
        vstr.push_back(stmp);
        token = strtok(NULL, delim);
    }
    return vstr;
}

//参数都为string版
vector<string> split(string s, string delim)
{
    char *ss = const_cast<char *>(s.c_str());
    const char *ddelim = delim.data();
    char *token = strtok(ss, ddelim);
    vector<string> vstr;
    while (token != NULL)
    {
        string stmp = token;
        vstr.push_back(stmp);
        token = strtok(NULL, ddelim);
    }
    return vstr;
}
//run:
int main_split()
{
    //若用string调用如下
    string s = "192.168", sm = ".";
    vector<string> ss = split(const_cast<char *>(s.c_str()), sm.data());
}
//^%}                         // mark end
