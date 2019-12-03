#include "product.hpp"
#include <vector>
#include <memory>
#include <algorithm>

typedef std::vector<std::shared_ptr<Product>> Products;

class ProductFilter
{
public:
    Products FilterbyColor(Products items, Color color)
    {
        Products result;
        for(auto item:items)
        {
            if(item->GetColor() == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Products FilterbySize(Products items, Size size)
    {
        Products result;
        for(auto item:items)
        {
            if(item->GetSize() == size)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Products FilterbyColorAndSize(Products items, Color color, Size size)
    {
        Products result;
        for(auto item:items)
        {
            if(item->GetSize() == size && item->GetColor() == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

template<typename T>
class Specification
{
public:
    virtual bool Is_Satisfied(T item) = 0;

};

template <typename T>
class ColorSpecification:public Specification<T>
{
public:
    explicit ColorSpecification(Color color):color_(color){};
    virtual bool Is_Satisfied(T item) override
    {
        return item->GetColor() == color_;
    };
private:
    Color color_;
};

template <typename T>
class SizeSpecification:public Specification<T>
{
public:
    explicit SizeSpecification(Size size):size_(size){};
    virtual bool Is_Satisfied(T item) override
    {
        return item->GetSize() == size_;
    };
private:
    Size size_;
};

template <typename T>
class BetterFilter
{
public:
    std::vector<T> filter(std::vector<T> items,
        Specification<T>& spec)
        {
           std::vector<T> result;
           for (auto item:items)
           {
               if(spec.Is_Satisfied(item))
               {
                   result.push_back(item);
               }
           }
           return result;
        }
};
