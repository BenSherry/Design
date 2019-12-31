#include <iostream>
#include <algorithm>
#include "Singleton.hpp"

std::shared_ptr<DateBase> DateBase::dataBasePtr_ = nullptr;
std::mutex DateBase::mutex_;
int main()
{
    auto dataBasePtr = DateBase::getDataBase();
    auto dataBasePtr1 = DateBase::getDataBase();
    auto dbv2_1 = DateBase_v2::getInstance();
    auto dbv2_2 = DateBase_v2::getInstance();
}
