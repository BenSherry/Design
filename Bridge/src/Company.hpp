#pragma once

#include <memory>

#include "IProduct.hpp"

class Company
{
private:
    std::shared_ptr<IProduct> productPtr_;
public:
    Company(std::shared_ptr<IProduct> productPtr):productPtr_(productPtr){};
    void MakeMoney()
    {
        productPtr_->Created();
        productPtr_->Selled();
    }

};
