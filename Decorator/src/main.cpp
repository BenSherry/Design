#include <iostream>
#include <algorithm>
#include <memory>

#include "IShape.hpp"
#include "Circle.hpp"
#include "ColorShape.hpp"

int main()
{
    auto circlePtr =  std::make_shared<Circle>(13.4);
    auto redCirclePtr = std::make_shared<ColorShape>("Red",circlePtr);
    std::cout << redCirclePtr->ShowInfo();
}

/******************************************
 * when we want to enhance a class, except add derived class, or change class it self
 * some times we can make a decoator, in this example, we had a class circle, then we
 * want to add property color, we made another class ColorShape, and it make Circle as 
 * a property,then it calls circle's function and expand it.
 * 
 * note that , in this case, ColorShape and circle all based on IShape, so we can even
 * mkake another decorator to decorate this decorator(ColorShape)
 * ***************************************/