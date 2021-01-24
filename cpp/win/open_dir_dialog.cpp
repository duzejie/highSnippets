

//^%{ "选择文件夹对话框" id=20210123017 [windows,file] [dialog]

/*t{  
#选择文件夹
在编程过程中，许多地方需要与文件打交道，这个时候需要打开文件，保存文件或者选择文件夹。在win32系统api中，提供了支持。
通过以下代码可以获得合适的文件夹。
g++ .\dialog.cpp   //need install cygWin or MinGW OR  compiled in VS C++
t}*/

//^{
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <shlobj.h>
#include  <tchar.h>
#include <string>
//^}

static bool SelectFolderPath(std::string& folderName)//选择文件夹
{
	TCHAR szBuffer[MAX_PATH] = { 0 };
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = GetForegroundWindow();
	bi.pszDisplayName = szBuffer;
	bi.pidlRoot = NULL;
	bi.lpszTitle = "从下面选文件夹目录:";
	bi.ulFlags = BIF_NEWDIALOGSTYLE;;
	LPITEMIDLIST idl = SHBrowseForFolder(&bi);
	if (NULL == idl) return false; 	
	SHGetPathFromIDList(idl, szBuffer);
	folderName = szBuffer;
	return true;
}
//run:
#include <iostream>
int main_SelectFolderPath(){
    std::string folderName;
    SelectFolderPath(folderName);
    std::cout<< "you opened folder:" << folderName<<std::endl;
    return 0;
}
//^%}
