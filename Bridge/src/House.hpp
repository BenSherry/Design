#pragma once

#include <iostream>

#include "IProduct.hpp"

class House : public IProduct
{
public:
    void Created() override
    {
        std::cout << "House is created \n";
    }

    void Selled() override
    {
        std::cout << "House is selled \n";
    }

};
