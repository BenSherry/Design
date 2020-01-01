#pragma once

#include<string>

#include "IUserInfo.hpp"

class UserInfo : public IUserInfo
{
public:
    std::string getUserName() override
    {
        std::string username = "john";
        return username;
    }

    std::string getOfficeAddress()
    {
        std::string officeAddress = "0A707";
        return officeAddress;
    }
};
