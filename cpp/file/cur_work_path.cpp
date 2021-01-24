
//^%{  "current work path " id=20210123001 [file,path] [cwd,path]

/*t{                //start to comment this snippet, support markdown format
get current work path
t}*/
//#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include <stdio.h>
#ifdef _MSC_VER
#include <direct.h>
#else
#include <unistd.h>
#endif
//^}                //#end a collapsible part
char *pwd()
{
    char *buffer;
#ifdef _MSC_VER //|| _WIN32
    buffer = _getcwd(NULL, 0);
#else //__GNUC__  _UNIX  linux
    buffer = getcwd(NULL, 0);
#endif
    if ((buffer) == NULL)
    {
        perror("getcwd error");
    }
    return buffer;
}

//run: --------
#include <iostream>
int main()
{ //must start with `main_`
    std::cout << "your work path:" << pwd() << std::endl;
    return 0;
}
//^%}                         // mark end
