#include <iostream>
#include <algorithm>
#include <memory>

#include "ICountryMachine.hpp"
#include "Branch.hpp"
#include "Leaf.hpp"

int main()
{
    Branch country{"China", "0x01"};
    std::shared_ptr<ICountryMachine> countryPtr = std::make_shared<Branch>(country);
    std::shared_ptr<ICountryMachine> provincePtr = std::make_shared<Branch>("zhejiang", "0x0101");
    std::shared_ptr<ICountryMachine> cityPtr = std::make_shared<Branch>("hangzhou", "0x010101");
    std::shared_ptr<ICountryMachine> citizenPtr = std::make_shared<Leaf>("xiaoming", "0x01010101");
    countryPtr->add(provincePtr);
    provincePtr->add(cityPtr);
    cityPtr->add(citizenPtr);
    std::cout << provincePtr->getParent()->getMachineName() << "\n";
    std::cout << cityPtr->getParent()->getMachineName() << "\n";
    std::cout << citizenPtr->getParent()->getMachineName() << "\n";
    citizenPtr->add(std::make_shared<Leaf>("xiaozhang", "0x01010102"));
    
    countryPtr->remove(provincePtr);
    if (provincePtr->getParent() == nullptr)
    {
        std::cout << "Province is removed \n";
    }

}
