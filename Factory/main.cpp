#include <iostream>

#include "IHotDrink.hpp"

int main()
{
    std::cout <<"please add your code and have fun...\n";
    CoffeeFactory coffeeFactory;
    coffeeFactory.make()->prePareDrink(200);

    DrinkFactory drinkFactory;
    auto tea = drinkFactory.makeDrink("tea");
    if (tea != nullptr)
    {
        tea.value()->prePareDrink(100);
    }

    auto cola = drinkFactory.makeDrink("cola");
    if (cola != std::nullopt)
    {
        cola->get()->prePareDrink(100);
    }

    DrinkWithVolumeFactory drinkWithVolumeFactory;
    drinkWithVolumeFactory.MakeDrink("tea").value()->prePareDrink(14);

    std::map<std::string, std::function<std::string(int, int)>> functionMap;
    auto func1 = [](int m, int n){ std::string result = "hahahaha"; return result;};
    auto func2 = [](int m, int n){ std::string result = "heheheheheh"; return result;};
    functionMap["func1"] = func1;
    functionMap["func2"] = func2;
    std::cout << functionMap["func1"](1, 2) << "\n";
    std::cout << functionMap["func2"](1, 2) << "\n";
}
