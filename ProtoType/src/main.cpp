#include <iostream>
#include <algorithm>
#include "ProtoType.hpp"

int main()
{
    auto addressPtr {std::make_shared<Address>("Bakerstreet", "London", 221)};
    auto contactPtr {std::make_shared<Contact>("John", addressPtr)};
    std::cout << *addressPtr <<std::endl;
    contactPtr->ShowContact();
    auto contactClonePtr = contactPtr->Clone("Jason");
    contactClonePtr->ShowContact();
}
