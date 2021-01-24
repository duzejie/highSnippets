
//^%{  "宽体字符和本地化" id=20210123012  [string] [string,c++]

/*t{                //start to comment this snippet, support markdown format

t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <string>
#include <iostream>

#include<string>
#include <locale>
#include <codecvt>

using namespace std;
//^}                //#end a collapsible part

namespace du
{
        using convert_typeX = std::codecvt_utf8<wchar_t>;

        static std::wstring s2ws(const std::string& str)
        {
            std::wstring_convert<convert_typeX, wchar_t> converterX;

            return converterX.from_bytes(str);

        }

        static std::string ws2s(const std::wstring& wstr)
        {
            std::wstring_convert<convert_typeX, wchar_t> converterX;

            return converterX.to_bytes(wstr);

        }
}

int main()
{
    wcout.imbue(locale(locale(),"zh_CN.utf8",LC_CTYPE)); 
//    setlocale(LC_ALL, "zh_CN.utf8");  //locale -a

    wstring wstr = L"杜泽杰duzejie";   
    std::wcout << wstr<<endl ;     

    wchar_t wc=        wstr[1];   
    std::wcout << wc <<endl;
    
    //std::cout << du::ws2s(wc) ;
    wstring ws1(wstr[1],1);
    setlocale(LC_ALL, "C");
    std::wcout<<L"--杜泽杰---"<<endl;
    std::cout<<"--杜泽杰---"<<endl;
    return 0;
}


int main2()
{
    setlocale(LC_ALL, "zh_CN.utf8");  // $locale -a #列出系统支持的编码，在程序调用宽体字符前设置编码格式。
                                      // 会导致wcout与cout冲突，只能全局用宽体字符
    wstring wstr = L"杜泽杰duzejie";
    char *s = (char*)&wstr[1];
    //char   *s = wstr[1].data();
    //wcout<< wstr[1]<<endl;

    if(wstr[1]==L'泽')
        wcout<<L"yes"<<endl;
    if(L'6'< L'9')
        wcout<<L"yes"<<endl;

    std::wcout<<L"--杜泽杰---"<<endl;
    return  0;
}


//^%}                         // mark end

