#pragma once

// 访问者接口类，Visit 接受需要访问的元素，进行不同的操作
#include<memory>
class GoLang;
using SharedGoLang = std::shared_ptr<GoLang>;
class PythonLang;
using SharedPython = std::shared_ptr<PythonLang>;
class Ivisitor
{
public:
    virtual ~Ivisitor() = default;
    virtual void Visit(SharedGoLang goLang) = 0;
    virtual void Visit(SharedPython goLang) = 0;
};

