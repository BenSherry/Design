#pragma once

#include <iostream>

#include "Company.hpp"

class ClothesCompany : public Company
{
public:
    ClothesCompany(std::shared_ptr<IProduct> productPtr):Company(productPtr){};
    void MakeMoney()
    {
        Company::MakeMoney();
        std::cout << "Clothes is making money now...\n";
    }
};
