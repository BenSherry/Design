#include <iostream>
#include <algorithm>
#include "ProductFilter.hpp"

int main()
{
    Product iphone1("iphone1", Color::BLUE, Size::SMALL);
    Product iphone4s("iphone4s", Color::RED, Size::MAX);
    Product iphoneX("iphoneX", Color::RED, Size::MAX);

    Products products {std::make_shared<Product>(iphone1),
        std::make_shared<Product>(iphone4s),
        std::make_shared<Product>(iphoneX)};
    
    ProductFilter productFilter;
    Products filterByColor = productFilter.FilterbyColor(products, Color::RED);
    std::for_each(filterByColor.begin(),
        filterByColor.end(),
        [](std::shared_ptr<Product> productPtr){
        std::cout <<productPtr->GetName()<<"\n";});

    ColorSpecification<std::shared_ptr<Product>> redSpec{Color::RED};
    SizeSpecification<std::shared_ptr<Product>> sizeSpec{Size::MAX};
    BetterFilter<std::shared_ptr<Product>> filter;
    auto filterByColorBetter = filter.filter(products, redSpec);
    std::for_each(filterByColorBetter.begin(),
        filterByColorBetter.end(),
        [](std::shared_ptr<Product> productPtr){
        std::cout <<productPtr->GetName()<<"\n";});

}