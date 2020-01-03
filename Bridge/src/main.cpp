#include <iostream>
#include <memory>

#include "IProduct.hpp"
#include "House.hpp"
#include "Clothes.hpp"
#include "Company.hpp"
#include "HouseCompany.hpp"
#include "ClothesCompany.hpp"

int main()
{
    House house;
    Clothes clothes;
    auto housePtr = std::make_shared<House>(house);
    auto clothesPtr = std::make_shared<Clothes>(clothes);
    HouseCompany houseCompany{housePtr};
    ClothesCompany clothesCompany{clothesPtr};
    houseCompany.MakeMoney();
    clothesCompany.MakeMoney();

    ClothesCompany clothesCompany2{housePtr};
    clothesCompany2.MakeMoney();

}
