#pragma once

#include "IShape.hpp"

class Circle : public IShape
{
public:
    Circle(double radius) : radius_{radius}{};
    std::string ShowInfo() override
    {
        return "This is a circle";
    }

    void Resize(double factor)
    {
        radius_ *= factor;
    }
private:
    double radius_;
};
