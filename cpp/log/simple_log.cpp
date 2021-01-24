//^%{  "very simple log system" id=20210123004 [tools] [tools,log]

/*t{                //start to comment this snippet, support markdown format
not thread safe
t}*/                //#end to comment this snippet, support markdown format

//^{                //#start a collapsible part
#include<iostream>
#include <sstream> 
#include <string>       // std::string
#include <ctime>
//^}                //#end a collapsible part
class SimpleLog
{
private:        
    bool out;
    bool quit;
    std::ostream &o;
public:
    template<class T>
    SimpleLog & operator << (T t){        
        if (out)           
            o <<t<<" ";         
        return *this;
    }
    SimpleLog(bool test, bool isQuit, std::ostream &os):out(test), quit(isQuit), o(os){   } 
    ~SimpleLog(){      
        if(quit)
            exit(0);       ///          
    }
};

static std::string  getCurrentTimeStr0(){
	time_t t = time(NULL);
	char ch[64] = {0};
	strftime(ch, sizeof(ch) - 1, "[%Y-%m-%d %H:%M:%S]", localtime(&t));     //年-月-日 时-分-秒
	return ch;
}

#define CHECK(x)       if (!(x)){ std::cerr<<std::endl;std::cerr<< getCurrentTimeStr0() <<"CHECK failed: "<<__FILE__<<", line:" <<__LINE__<< ". "; } SimpleLog(!(x), !(x),std::cerr)
#define INFO                      std::clog<<std::endl;std::clog<< getCurrentTimeStr0() <<"INFO:         "<<__FILE__<<", line:" <<__LINE__<< ". ";   std::clog
#define WARNING(x)     if (!(x)){ std::clog<<std::endl;std::clog<< getCurrentTimeStr0() <<"WARNING:      "<<__FILE__<<", line:" <<__LINE__<< ". "; } SimpleLog(!(x), false, std::clog)   
#define CAUTION                   std::clog<<std::endl;std::clog<< getCurrentTimeStr0() <<"CAUTION:      "<<__FILE__<<", line:" <<__LINE__<< ". ";   SimpleLog(true, false, std::clog)   

//run:
#include<iostream>

int main()
{   
    CHECK(2==2)<<"相等吗？";
    INFO << 12335 <<"DUZEJIE TEST";
    CHECK(3==3) <<"相等吗？"<<"相等吗？"<<"相等吗？";
    WARNING(2==3)<<2 <<" and " << 3 << "不相等";
    CAUTION <<3 <<" and " << 3 << "不相等";
    CHECK(3==4) << "3与4不相等"<< "3与4不相等"<<3<<4;
    return 0;
}

//^%}                         // mark end
