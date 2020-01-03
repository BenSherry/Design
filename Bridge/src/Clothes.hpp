#pragma once

#include <iostream>

#include "IProduct.hpp"

class Clothes : public IProduct
{
public:
    void Created() override
    {
        std::cout << "Clothes is created \n";
    }

    void Selled() override
    {
        std::cout << "Clothes is selled \n";
    }

};
