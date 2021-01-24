
//^%{ "保存文件对话框" id=20210123019 [windows,file] [dialog]
/*t{  
#保存文件对话框
//在win32下就可以方便的打开文件。
g++ .\dialog.cpp -static-libgcc -lgdi32 -lcomdlg32  //need install cygWin or MinGW OR  compiled in VS C++
t}*/

//^{
#include <windows.h>
#include <Commdlg.h>
#include <string>
#include <iostream>
//^}
static std::string GetSaveFile(char* filter = NULL, char* title = NULL, char* initDirectory = NULL)
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

	ofn.Flags = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;//目录必须存在，覆盖文件前发出警告
	ofn.lpstrDefExt = TEXT("aep");//默认追加的扩展名
	if (GetSaveFileName(&ofn))
	{
		filename = strFilename;
	}
	return filename;
}

//run:
int main_GetSaveFile()
{
	std::string filename = GetSaveFile(static_cast<char*>(("PNG背景图片\0*.png\0所有文件\0*.*\0\0")), "打开PNG背景图片");
	if (!filename.empty())
	{
		//给对应窗口赋值
	}
	return 0;
}
//^%}




