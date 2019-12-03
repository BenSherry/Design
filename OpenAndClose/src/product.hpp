#pragma once

#include <iostream>

enum class Color
{
    RED,
    GREEN,
    BLUE
};

enum class Size
{
    SMALL,
    MIDDLE,
    MAX
};

class Product
{
public:
    Product(std::string name, Color color, Size size):
        name_(name),
        color_(color),
        size_(size){}

    Color GetColor()
    {
        return color_;
    }

    Size GetSize()
    {
        return Size();
    }

    std::string GetName()
    {
        return name_;
    }
private:
    std::string name_;
    Color color_;
    Size size_;
};