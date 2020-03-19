#pragma once

#include"visitor.h"
// 被访问者接口类，Accept接口接受一个具体的访问者
class ILangElement
{
public:
    virtual ~ILangElement() = default;
    virtual void Accept(std::shared_ptr<Ivisitor> vistor) = 0;
};

