#pragma once

#include <memory>

#include "HireEmployee.hpp"

class HireEmployeeFacade
{
public:
    HireEmployeeFacade(std::string eduBackGround, std::string skill)
    {
        hireEmployeePtr_ = std::make_shared<HireEmployee>(eduBackGround, skill);
    }

    void HireSomeOne()
    {
        hireEmployeePtr_->GetResumeFromWeb();
        hireEmployeePtr_->ChooseResume();
        hireEmployeePtr_->InterviewFromTech();
        hireEmployeePtr_->InterviewFromHR();
    }
private:
    std::shared_ptr<HireEmployee> hireEmployeePtr_;

};
