#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <optional>
#include <functional>

class IHotDrink
{
public:
    virtual void prePareDrink(int volume) = 0;
};

class Tea : public IHotDrink
{
public:
    void prePareDrink(int volume) override
    {
        std::cout << "Let's drink some tea" << "\n";
    }
};

class Coffee : public IHotDrink
{
public:
    void prePareDrink(int volume) override
    {
        std::cout << "Let's drink some coffee" << "\n";
    }
};

class IHotDrinkFactory
{
public:
    virtual std::shared_ptr<IHotDrink> make() = 0;
};

class TeaFactory : public IHotDrinkFactory
{
public:
    std::shared_ptr<IHotDrink> make() override
    {
        return std::make_shared<Tea>();
    }
};

class CoffeeFactory : public IHotDrinkFactory
{
public:
    std::shared_ptr<IHotDrink> make() override
    {
        return std::make_shared<Coffee>();
    }
};

class DrinkFactory
{
private:
    std::map<std::string, std::shared_ptr<IHotDrinkFactory>> hot_factories_;

public:
    DrinkFactory()
    {
        hot_factories_["tea"] = std::make_shared<TeaFactory>();
        hot_factories_["coffee"] = std::make_shared<CoffeeFactory>();
    }

    std::optional<std::shared_ptr<IHotDrink>> makeDrink(std::string name)
    {
        if (hot_factories_.find(name) == hot_factories_.end())
        {
            std::cout << "no " << name << " on menu\n";
            return std::nullopt;
        }
        return hot_factories_[name]->make();
    }
};

class DrinkWithVolumeFactory
{
private:
    std::map<std::string, std::function<std::shared_ptr<IHotDrink>()>> factorys_;
public:
    DrinkWithVolumeFactory()
    {
        auto teaMaker = [](){
            return std::make_shared<Tea>();};
        auto coffeeMaker = [](){
            return std::make_shared<Coffee>();};
        factorys_["tea"] = teaMaker;
        factorys_["coffee"] = coffeeMaker;
    }

    std::optional<std::shared_ptr<IHotDrink>> MakeDrink(std::string drinkName)
    {
        if (factorys_.find(drinkName) == factorys_.end())
        {
            return std::nullopt;
        }
        return factorys_[drinkName]();
    }
};
