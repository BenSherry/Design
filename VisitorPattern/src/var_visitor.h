#pragma once

#include<variant>
#include<iostream>
#include<vector>
#include<algorithm>
#include"visitor.h"
#include "Languages.h"
// std::variant 的简单例子
using var = std::variant<int, double, std::string>;
struct Visitor
{
    void operator()(double it)
    {
        std::cout<< "this is a double:"<<it <<std::endl;
    }
    void operator()(std::string it)
    {
        std::cout<< "this is a string:"<<it <<std::endl;
    }
    void operator()(int it)
    {
        std::cout<< "this is a int:"<<it <<std::endl;
    }
};

void visit_element()
{
    std::vector<var> var_vec;
    var var1 {1}, var2{3.4}, var3{"hello"};
    var_vec.push_back(var1);
    var_vec.push_back(var2);
    var_vec.push_back(var3);
    Visitor visitor;
    for(auto &&elem:var_vec)
    {
        std::visit(visitor,elem);
    }

}

// 使用c++17 原生访问者模式实现前面realcoder and fakecoder 的功能
class RealCoder_C
{
public:
    void operator()(SharedGoLang goLang)
    {
        std::cout<<"Real coder will write code to learn golang......"<<std::endl;
    }
    void operator()(SharedPython pythonLand)
    {
        std::cout<<"Real coder will write code to learn python......"<<std::endl;
    }
};
class FakeCoder_C
{
public:
    void operator()(SharedGoLang goLang)
    {
        std::cout<<"Fake coder will install some  GoLang IDE tools......"<<std::endl;
    }
    void operator()(SharedPython goLang)
    {
        std::cout<<"Fake coder will install some  pyhton IDE tools......"<<std::endl;
    }
};

void test_coder_c()
{
    using var_langs_t = std::variant<SharedGoLang, SharedPython>;
    std::shared_ptr<GoLang> pgolang{new GoLang};
    std::shared_ptr<PythonLang> ppythonlang{new PythonLang};
    var_langs_t v1 {pgolang}, v2 {ppythonlang};
    std::vector<var_langs_t> var_vec;
    var_vec.push_back(v1);
    var_vec.push_back(v2);
    RealCoder_C rc;
    FakeCoder_C fc;

    for(auto &&elem:var_vec)
    {
        std::visit(rc,elem);
        std::visit(fc,elem);
    }
}
