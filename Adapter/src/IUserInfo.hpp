#pragma once

#include <string>
#include <iostream>

class  IUserInfo
{
public:
    virtual std::string getUserName() = 0;
    virtual std::string getOfficeAddress() = 0;
};
