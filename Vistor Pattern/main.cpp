#include <iostream>
#include "RealCoder.h"
#include"Languages.h"
#include "LangHome.h"
void TestvisitorDirectly()
{
    std::shared_ptr<GoLang> pgolang{new GoLang};
    std::shared_ptr<Ivisitor> pcoder(new RealCoder());
    std::shared_ptr<Ivisitor> pfakecoder(new FakeCoder());
    // 这里只能使用智能指针的方式调用调用Accept()，否则会出现bad weak_ptr
    pgolang->Accept(pcoder);
    pgolang->Accept(pfakecoder);
    std::shared_ptr<PythonLang> ppythonlang{new PythonLang};
    ppythonlang->Accept(pcoder);
    ppythonlang->Accept(pfakecoder);
}
void TestVistotbyUseLangHome()
{
    // 把需要的调用封装在了类 LangHome；
    LangHome langHome;
    std::shared_ptr<GoLang> pgolang{new GoLang};
    std::shared_ptr<PythonLang> ppythonlang{new PythonLang};
    langHome.Attach(pgolang);
    langHome.Attach(ppythonlang);
    std::shared_ptr<Ivisitor> pcoder(new RealCoder());
    std::shared_ptr<Ivisitor> pfakecoder(new FakeCoder());
    langHome.Accept(pcoder);
    langHome.Accept(pfakecoder);
}
int main() {
    return 0;
}
/* 有两个元素，不同的的访问者访问的时候，会出现不同的效果，我们可以考虑使用访问者模式来实现
 * 这个例子里，这两个元素是两种编程语言，python和go（PythonLang和GoLang），
 * 访问者也有两种，真正的程序员和虚假的程序员（RealCoder 和 FakeCoder）
 * 真正的程序员学一门语言会认真的编程，虚假的程序员会搭建一下环境就ok了，这就是不同的访问者访问同一个元素会有不同的效果
 */