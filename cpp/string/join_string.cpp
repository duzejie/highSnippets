//^%{  "字符串join" id=20210123007 [string] [string,c++]
/*t{                //start to comment this snippet, support markdown format
字符串join,类似python的join
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

//以下给出类似于Python 中join功能的实现，后续不断完善
string join(const vector<string> &vs, const string &s)
{
    int n = vs.size();
    string restr;
    for (int i = 0; i < n - 1; ++i)
        restr = restr + vs[i] + s;
    restr += vs[n - 1];
    return restr;
}

int main(){
    vector<string> vs{"12","23","duz"};
    string s="-";
    std::cout<<join(vs,s)<<std::endl;
    return 0;
}



//^%}                         // mark end










