#pragma once

#include <map>
#include <iostream>
#include <string>

class OuterUserInfo
{
private:
    std::map<std::string,std::string> userInfoMap_;

public:
    OuterUserInfo()
    {
        userInfoMap_["name"] = "Bourbon";
        userInfoMap_["Addr"] = "0A768";
    }

    std::map<std::string,std::string> getUserInfo()
    {
        return userInfoMap_;
    }
};
