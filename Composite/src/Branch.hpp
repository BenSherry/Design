#pragma once

#include <algorithm>

#include "ICountryMachine.hpp"
using CountryMachineptr = std::shared_ptr<ICountryMachine>;

class Branch : public ICountryMachine, public std::enable_shared_from_this<Branch>
{
public:
    Branch(std::string name, std::string id) : 
    name_{name},
    id_(id),
    parentPtr_{nullptr}{};
    void add(CountryMachineptr countryMachineptr) override
    {
        subMachine_.push_back(countryMachineptr);
        countryMachineptr->setParents(shared_from_this());
        
    }

    void remove(CountryMachineptr countryMachineptr) override
    {
        subMachine_.erase(std::remove_if(
            subMachine_.begin(),
            subMachine_.end(),
            [countryMachineptr](CountryMachineptr elem)
                {
                    if (elem->getMachineId().compare(countryMachineptr->getMachineId()) == 0)
                    {
                        elem->setParents(nullptr);
                        return true;
                    }
                    return false;}),
        subMachine_.end());
    }
    CountryMachineptr getParent() override
    {
        return parentPtr_;
    }

    std::string getMachineName() override
    {
        return "This is machine :" +  name_;
    }

    std::string getMachineId() override
    {
        return id_;
    }
private:
    void setParents(CountryMachineptr countryMachineptr) override
    {
        parentPtr_ = countryMachineptr;
    }


    std::string name_;
    std::string id_;
    std::vector<CountryMachineptr> subMachine_;
    CountryMachineptr parentPtr_;
};
