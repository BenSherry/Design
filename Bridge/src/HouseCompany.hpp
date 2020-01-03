#pragma once

#include <iostream>

#include "Company.hpp"

class HouseCompany : public Company
{
public:
    HouseCompany(std::shared_ptr<IProduct> productPtr):Company(productPtr){};
    void MakeMoney()
    {
        Company::MakeMoney();
        std::cout << "House is making money now...\n";
    }
};