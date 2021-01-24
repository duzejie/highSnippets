
//=============================================================================================================
//^%{  "list files and dirs in path " id=20210123002 [file,path] [file,dir]

//^{                //#start a collapsible part
#include <string>
#include <vector>
#include <cstring> // for strcat()

#ifdef _MSC_VER //|| _WIN32
#include <io.h>
#else //__GNUC__  _UNIX  linux
#include <sys/stat.h>
#include <sys/types.h>
//#include <unistd.h>
#include <dirent.h>
#endif
//^}                //#end a collapsible part

bool listFiles(std::string dirIn, std::vector<std::string> &files, std::vector<std::string> &dirs);

#ifdef _MSC_VER //|| _WIN32
bool listFiles(std::string dirIn, std::vector<std::string> &files, std::vector<std::string> &dirs)
{
    files.clear();
    dirs.clear();
    char dir[500];
    if (dirIn == "")
        return false;
    if (dirIn == ".")
        dirIn = "./";
    if (dirIn[dirIn.size() - 1] != '\\')
        dirIn = dirIn + "\\";
    dirIn = dirIn + "*.*";
    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(dirIn.c_str(), &findData);
    if (handle == -1)
    {
        printf("Failed to find first file!\n");
        return false;
    }
    do
    {
        if (findData.attrib & _A_SUBDIR && strcmp(findData.name, ".") //== 0
            && strcmp(findData.name, "..")                            //== 0
            )                                                         // 是否是子目录并且不为"."或".."
        {
            //cout << findData.name << "\t<dir>\n";
            dirs.push_back(findData.name);
        }
        else if (strcmp(findData.name, ".")      //== 0
                 && strcmp(findData.name, "..")) //== 0
        {
            //cout << findData.name << "\t" << findData.size << endl;
            files.push_back(findData.name);
        }
    } while (_findnext(handle, &findData) == 0);
    //cout << "Done!\n";
    _findclose(handle);
    return true;
}

#else //__GNUC__  _UNIX  linux

bool listFiles(std::string path, std::vector<std::string> &files, std::vector<std::string> &dirs)
{
    DIR *dir;
    struct dirent *ptr;
    if ((dir = opendir(path.c_str())) == NULL)
    {
        perror("Open dri error...");
        return false;
    }

    while ((ptr = readdir(dir)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else if (ptr->d_type == 8) //file
            files.push_back(ptr->d_name);
        else if (ptr->d_type == 10) //link file
            continue;
        else if (ptr->d_type == 4)
        {
            dirs.push_back(ptr->d_name); //dir
            //std::string path = dirIn;
            //getAllFiles(path+"/"+ptr->d_name,files);
            ;
        }
    }
    closedir(dir);
    return true;
}

#endif

//run: --------
#include <iostream>
int main()
{
    char dir[200];
    std::cout << "Enter a directory (ends with \'\\\'): ";
    std::cin.getline(dir, 200);
    std::vector<std::string> files;
    std::vector<std::string> dirs;
    listFiles(dir, files, dirs);
    for (auto s : files)
        std::cout << s << std::endl;
    for (auto s : dirs)
        std::cout << s << std::endl;
    return 0;
}

//^%}                         // mark end
