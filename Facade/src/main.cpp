#include <iostream>
#include <algorithm>

#include "HireEmployeeFacade.hpp"

int main()
{
    HireEmployeeFacade hireEmployeeFacade{"Master", "MachineLearning"};
    hireEmployeeFacade.HireSomeOne();
}

/**************************************************
 * The Façade design pattern is a way of putting a simple 
 * interface in front of one or more complicated subsystems. 
 * ************************************************/
