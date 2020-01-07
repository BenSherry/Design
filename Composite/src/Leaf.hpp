#pragma once

class Leaf : public ICountryMachine
{
public:
    Leaf(std::string name, std::string id) : 
    name_{name},
    id_(id),
    parentPtr_{nullptr}{};
    void add(CountryMachineptr countryMachineptr) override
    {
        std::cout << "it is leaf node, can not add sub node...\n";
    }

    void remove(CountryMachineptr countryMachineptr) override
    {
        std::cout << "it is leaf node, can not remove sub node...\n";
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
    CountryMachineptr parentPtr_;
};
