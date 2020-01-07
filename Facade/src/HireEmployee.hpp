#pragma once

#include <iostream>
#include <string>

class HireEmployee
{
public:
    HireEmployee(std::string eduBackGround, std::string skill):
        eduBackGround_(eduBackGround),
        skill_(skill){};
    void GetResumeFromWeb()
    {
        std::cout << "we read resume from google\n";
    };

    void ChooseResume()
    {
        std::cout << "we choose 10 resumes \n";
    }

    void InterviewFromTech()
    {
        std::cout << "we have a interview about Technique\n";
    }

    void InterviewFromHR()
    {
        std::cout << "we have a interview about salary and profit\n";
    }
private:
    std::string eduBackGround_;
    std::string skill_;
};
