#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class ICountryMachine
{
public:
    virtual void add(std::shared_ptr<ICountryMachine> countryMachineptr) = 0;
    virtual void remove(std::shared_ptr<ICountryMachine> countryMachineptr) = 0;
    virtual std::shared_ptr<ICountryMachine> getParent() = 0;
    virtual void setParents(std::shared_ptr<ICountryMachine> countryMachineptr) = 0;
    virtual std::string getMachineId() = 0;
    virtual std::string getMachineName() = 0;
};
