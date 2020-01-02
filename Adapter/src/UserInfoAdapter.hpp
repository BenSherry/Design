#pragma once

#include <iostream>
#include <string>
#include "IUserInfo.hpp"
#include "OuterUserInfo.hpp"

class UserInfoAdapter : public IUserInfo
{
public:
    UserInfoAdapter(OuterUserInfo outerUserInfo):
        name_{outerUserInfo.getUserInfo()["name"]},
        address_{outerUserInfo.getUserInfo()["Addr"]}{};

    std::string getUserName() override
    {
        return name_;
    }

    std::string getOfficeAddress() override
    {
        return address_;
    }
private:
    std::string name_;
    std::string address_;
};
