//
// Created by SHERRY on 2019/6/4.
//

#ifndef VISTOR_PATTERN_VAR_VISITOR_H
#define VISTOR_PATTERN_VAR_VISITOR_H


#include<variant>
#include<iostream>
#include<vector>
#include<algorithm>

using var = std::variant<int, double, std::string>;
struct Visitor
{
    void operator()(double it)
    {
        std::cout<< "this is a double:"<<it <<std::endl;
    }
    void operator()(std::string it)
    {
        std::cout<< "this is a string:"<<it <<std::endl;
    }
    void operator()(int it)
    {
        std::cout<< "this is a int:"<<it <<std::endl;
    }
};

void visit_element()
{
    std::vector<var> var_vec;
    var var1 {1}, var2{3.4}, var3{"hello"};
    var_vec.push_back(var1);
    var_vec.push_back(var2);
    var_vec.push_back(var3);
    Visitor visitor;
    for(auto &&elem:var_vec)
    {
        std::visit(visitor,elem);
    }

}

#endif //VISTOR_PATTERN_VAR_VISITOR_H
