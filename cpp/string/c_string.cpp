//^%{  "c字符串处理" id=20210123005 [string] [string, c]

/*t{                //start to comment this snippet, support markdown format      

#c字符串常用
函数名: strcpy
char *strcpy(char *dest, const char *src);
功  能: 将参数src字符串拷贝至参数dest所指的地址
返回值: 返回参数dest的字符串起始地址
说  明: 如果参数dest所指的内存空间不够大，可能会造成缓冲溢出的错误情况，在编写程序时需特别留意，或者用strncpy()来取代

函数名: strncpy
功  能: 将字符串src前n个字符拷贝到字符串dest
用  法: char *strncpy(char *dest, const char *src, size_t n);
返回值: 返回参数dest的字符串起始地址
说  明: 不像strcpy()，strncpy()不会向dest追加结束标记'\0'；
       src和dest所指的内存区域不能重叠，且dest必须有足够的空间放置n个字符；


函数名: strcat
功  能: 字符串拼接函数
用  法: char *strcat(char *dest, const char *src);
返回值: 返回dest字符串起始地址
说  明: strcat() 会将参数src字符串复制到参数dest所指的字符串尾部；
       dest最后的结束字符'\0'会被覆盖掉，并在连接后的字符串的尾部再增加一个'\0'；
       dest与src所指的内存空间不能重叠，且dest要有足够的空间来容纳要复制的字符串；

函数名: strncat
功  能: 将n个字符追加到字符串的结尾
用  法: char *strncat(char *dest, const char *src, size_t n);
返回值: 返回dest字符串起始地址
说  明: strncat()将会从字符串src的开头拷贝n个字符到dest字符串尾部，dest要有足够的空间来容纳要拷贝的字符串；
       如果n大于字符串src的长度，那么仅将src全部追加到dest的尾部；
       strncat()会将dest字符串最后的'\0'覆盖掉，字符追加完成后，再追加'\0'；


函数名: strchr
功  能: 在一个字符串中查找给定字符的第一个匹配之处
用  法: char *strchr(const char *str, int c);
返回值: 如果找到指定的字符则返回该字符所在地址，否则返回NULL
说  明: 返回的地址是字符串在内存中随机分配的地址再加上你所搜索的字符在字符串的位置；
       字符串str的结束标志‘\0’也会被纳入检索范围，所以str的最后一个字符也可以被定位；
       如果希望查找某字符在字符串中最后一次出现的位置，可以使用 strrchr() 函数；

函数名: strcmp
功  能: 字符串比较
用  法: int strcmp(const char *s1, const char *s2);
返回值: 根据ASCII码比较，若参数s1和s2字符串相同则返回0，s1若大于s2则返回大于0的值，s1若小于s2则返回小于0的值
说  明: 它是区分大小写比较的，如果希望不区分大小写进行字符串比较，可以使用stricmp函数


函数名: strlen
功  能: 计算指定的字符串s的长度，不包括结束字符'\0'
用  法: size_t strlen(const char *s);
返回值: 返回字符串s的字符数
说  明: strlen() 函数计算的是字符串的实际长度，遇到第一个'\0'结束；
       如果你只定义没有给它赋初值，这个结果是不定的，它会从首地址一直找下去，直到遇到'\0'停止；
       sizeof返回的是变量声明后所占的内存数，不是实际长度，此外sizeof不是函数，仅仅是一个操作符，strlen()是函数；


函数名: strstr
功  能: 检索子串在字符串中首次出现的位置
用  法: char *strstr( char *str, char * substr );

函数名 : strtok
功  能 : 根据分界符将字符串分割成一个个片段
用  法 : char *strtok(char *s, const char *delim);
返回值 : 返回下一个分割后的字符串指针，如果已无从分割则返回NULL
说  明 : 当strtok()在参数s的字符串中发现到参数delim的分割字符时则会将该字符改为'\0'字符；
       在第一次调用时，strtok()必须赋予参数s字符串，往后的调用则将参数s设置成NULL；

# const_cast
char* p = const_cast<char*>(tmp); //onst char*转化为char*，利用const_cast<char*>

t}*/
//#end to comment this snippet, support markdown format

//^%}                         // mark end



