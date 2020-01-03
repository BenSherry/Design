#pragma once

#include <iostream>
#include <string>

class IProduct
{
public:
    virtual void Created() = 0;
    virtual void Selled() = 0;
};
