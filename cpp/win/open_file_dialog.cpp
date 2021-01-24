//^%{ "打开文件对话框" id=20210123018 [windows,file] [dialog]
/*t{  
#打开文件对话框
//在win32下就可以方便的打开文件。
g++ .\dialog.cpp  -static-libgcc -lgdi32 -lcomdlg32  //need install cygWin or MinGW OR  compiled in VS C++
t}*/
//^{
#include <windows.h>
#include <Commdlg.h>
#include <string>
#include <iostream>
//^}
static std::string GetOpenFile(char* filter=NULL,char* title=NULL, char* initDirectory=NULL)
{	
	std::string filename;//文件名
	//打开文件
	OPENFILENAME ofn = { 0 };
	TCHAR strFilename[MAX_PATH] = { 0 };//用于接收文件名
	ofn.lStructSize = sizeof(OPENFILENAME);//结构体大小
	ofn.hwndOwner = GetForegroundWindow();//拥有着窗口句柄
	if (filter)
	{
		ofn.lpstrFilter = filter;//设置过滤
	}
	else
	{
		ofn.lpstrFilter = TEXT("所有文件\0*.*\0\0");//设置过滤
	}	

	ofn.nFilterIndex = 1;//过滤器索引
	ofn.lpstrFile = strFilename;//接收返回的文件名，注意第一个字符需要为NULL
	ofn.nMaxFile = sizeof(strFilename);//缓冲区长度
	ofn.lpstrInitialDir = initDirectory;//初始目录为默认
	//对话框标题
	if (title)
	{
		ofn.lpstrTitle = title;
	}
	else
	{
		ofn.lpstrTitle = TEXT("请选择一个文件");
	}	
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//文件、目录必须存在，隐藏只读选项
	if (GetOpenFileName(&ofn))
	{
		filename = strFilename;
	}
	return filename;
}

//run:
int main_GetOpenFile()
{
	std::string filename = GetOpenFile(const_cast<char*>(TEXT("PNG背景图片\0*.png\0所有文件\0*.*\0\0")), const_cast<char*>("打开PNG背景图片"));
	if (!filename.empty())
	{
		//给对应窗口赋值
	}
    return 0;
}
//^%}



