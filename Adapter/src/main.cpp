#include <iostream>
#include <algorithm>
#include <memory>

#include "UserInfoAdapter.hpp"
#include "UserInfo.hpp"

int main()
{
    UserInfo user;
    std::shared_ptr<IUserInfo> userInfoPtr = std::make_shared<UserInfo>(user);
    std::cout << "Address:" << userInfoPtr->getOfficeAddress() << "\n";
    std::cout << "Name:" << userInfoPtr->getUserName() << "\n";

}

/**********************************************************************
 * 1.对于父类中的普通函数，子类中同名函数会隐藏父类的实现，不管参数列表是否相同
 * 2.父类中的纯虚函数，是子类必须实现的函数，因此建议父类中函数用 =0 修饰，子类
 * 函数用override修饰
 **********************************************************************/
