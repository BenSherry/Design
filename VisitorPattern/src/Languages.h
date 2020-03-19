#pragma once

#include"LangElememt.h"
/*定义了两个被访问者GoLang PythonLang。
 * 回顾一下，访问者的Visit函数接受被访者，这里被访问者Accept函数接受访问者
 * 那这里两个函数怎么调用？
 * Accept()作为真正调用的外部接口，Accept内部调用visitor的visit()
 * （Accept函数把自身的this指针作为函数参数传递给visit()）
 */
class GoLang : public ILangElement,public std::enable_shared_from_this<GoLang>
{
public:
     void Accept(std::shared_ptr<Ivisitor> vistor) override
     {
         vistor->Visit(shared_from_this()); // visit()接受智能指针，这里需要把this指针转化为shared_ptr
     }
};
class PythonLang : public ILangElement,public std::enable_shared_from_this<PythonLang>
{
public:
    void Accept(std::shared_ptr<Ivisitor> vistor) override
    {
        vistor->Visit(shared_from_this());
    }
};
