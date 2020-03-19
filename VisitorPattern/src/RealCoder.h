#pragma once

#include"visitor.h"
#include "Languages.h"
#include<iostream>
// 定义了两个访问者
class RealCoder : public Ivisitor
{
public:
    void Visit(SharedGoLang goLang)
    {
        std::cout<<"Real coder will write code to learn golang......"<<std::endl;
    }
    void Visit(SharedPython pythonLand)
    {
        std::cout<<"Real coder will write code to learn python......"<<std::endl;
    }
};
class FakeCoder : public Ivisitor
{
public:
    void Visit(SharedGoLang goLang)
    {
        std::cout<<"Fake coder will install some  GoLang IDE tools......"<<std::endl;
    }
    void Visit(SharedPython goLang)
    {
        std::cout<<"Fake coder will install some  pyhton IDE tools......"<<std::endl;
    }
};

