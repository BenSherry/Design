#pragma once

#include <memory>

#include "IShape.hpp"

class ColorShape : public IShape
{
public:
    ColorShape(std::string color, std::shared_ptr<IShape> shapePtr):
        color_{color},
        shapePtr_(shapePtr){};
    std::string ShowInfo() override
    {
        return shapePtr_->ShowInfo() + ", and it is a "+  color_  +  " one\n"; 
    }
private:
    std::string color_;
    std::shared_ptr<IShape> shapePtr_;
};
