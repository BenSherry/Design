#pragma once

#include <iostream>
#include <string>
#include <memory>

class Address
{
private:
    std::string street_;
    std::string city_;
    int suite_;
    Address(){};

public:
    Address(const std::string& street, const std::string& city, const int suite)
        :street_{street},
        city_{city},
        suite_{suite}
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Address& obj)
    {
            return os
        << "street: " << obj.street_
        << " city: " << obj.city_
        << " suite: " << obj.suite_;
    }
};

class Contact : public std::enable_shared_from_this<Contact>
{
private:
    std::string name_;
    std::shared_ptr<Address> addressPtr_;

public:
    Contact(std::string name, std::shared_ptr<Address> addressPtr):
        name_(name),addressPtr_(addressPtr){}

    Contact(std::string name, Contact& other):
        name_(name),
        addressPtr_(other.addressPtr_)
    {
    };
    
    std::shared_ptr<Contact> Clone(std::string name)
    {
        return std::make_shared<Contact>(name, *this);
    }
    void ShowContact()
    {
        std::cout << "This is " << name_ << std::endl;
        std::cout << *addressPtr_ << std::endl;
    }
};
