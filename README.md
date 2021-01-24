# snippets


> snippets is a easy-using C++ general snippets that is designed to be as simple, small and flexible as possible. It is created as an alternative to existing large libraries and provides some unique features. Most functions are writed very small and one Header only. In addtion, there are no 3rd-party dependencies.

## modules


## Features
- Very small
- Easy to use
- Headers only (most functions depend on only one header )  
- No 3rd-party dependencies
- Cross-platform

## snippets的文件结构
按照如下方式 snippets的文件结构。
```
code_snippets_root
   ├─notebook1                   // usually folders
   │  ├─ section1                // usually folders
   │  ├─ section2                // put very similar class of codes  in one section folder
   │  ├─ section3
   │  │  ├─ page1                // usually folders
   │  │  ├─ page2                // put very similar fuction of codes  in one page dir
   │  │  │    ├─ snippet1        // usually a source file(xx.cpp\xx.py) or a markdown file(xx.md)
   │  │  │    ├─ snippet2        // with special format
   │  │  │    └─ snippet3        // a source file can hold many snippet.
   │  │  ├─ page3
   │  │  └─ page4
   │  └─ section4
   ├─ notebook2
   │  ├─test
   │  │  └─string
   │  ├─time
   │  └─win
   ├─ notebook3
   └─ notebook4

``` 

## format
### C/C++源代码的snippet
对于C/C++源代码，一个snippets的格式如下：
using ` //^%{ ` start a snippet,  followed by id,  categories and tags.
usinf ` //^%} ` end a spippet
using ` /*t{ ` and  `t}*/`  include a tip, which gives doc to the snippet.
using ` //run `, mark a function which can run this snippets.
using ` //^{ ` and  `//^}`  a collapsible part.
**syntax**
```cpp
//^%{  "title or name" id=20210123001 [category1,category2,category2] [tag1,tag2]

/*t{                //start to comment this snippet, support markdown format
# H1 title
docment example example
t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include  <io.h>
#include <string>
//^}                //#end a collapsible part


static bool my_function(std::string& folderName)
{
	//codes
	return true;
}
//run:
#include <iostream>
int main_my_function(){           //must start with `main_`
    std::string folderName;
    my_function(folderName);
    std::cout<< "you opened folder:" << folderName<<std::endl;
    return 0;
}
//^%}                         // mark end

```

### python源代码的snippet
对于python源代码，一个snippets的格式如下：
using ` #^%{ ` start a snippet,  followed by id,  categories and tags.
usinf ` #^%} ` end a spippet
using ` '''t{ ` and  `t}''' `  include a tip, which gives doc to the snippet.
using ` #run `, mark a function which can run this snippets. 

**syntax**
```python
#^%{ "title or name" id=20210123002 [category1,category2,category2] [tag1,tag2]

'''t{                #start to comment this snippet, support markdown format
# H1 title
docment example example
t}'''                #end to comment this snippet, support markdown format

#^{                //#start a collapsible part
import aa
import bbbbb as b
#^}                //#end a collapsible part

def my_function()
	#codes
	return folderName

#run:
def main_my_function()           #must start with `main_`
    folderName = my_function()
    print(folderName}
    
#^%}                         // mark end

```







