#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <mutex>

class DateBase // lazy
{
private:
    DateBase(){std::cout << "DateBase instance created\n";}
public:
    DateBase(DateBase&)=delete;
    DateBase& operator=(const DateBase&)=delete;
    ~DateBase(){std::cout << "destruct called \n";}
    static std::shared_ptr<DateBase> getDataBase()
    {
        // it is not effective, we can lock only when dataBasePtr_ is nullptr
        // if do this, double check is needed here
        // http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
        std::lock_guard<std::mutex> lk(mutex_);
        if (dataBasePtr_ == nullptr)
        {
            dataBasePtr_ = std::shared_ptr<DateBase>(new DateBase);
        }
        return dataBasePtr_;
    }
private:
    static std::shared_ptr<DateBase> dataBasePtr_;
    static std::mutex mutex_;
};

class DateBase_v2
{
private:
    DateBase_v2(){std::cout << "DateBase_v2 instance created\n";}
public:
    ~DateBase_v2(){std::cout << "DateBase_v2 destruct called \n";}

public:
    static std::shared_ptr<DateBase_v2> &getInstance()
    {
        static std::shared_ptr<DateBase_v2> db_v2ptr = std::shared_ptr<DateBase_v2>(new DateBase_v2);
        return db_v2ptr;
    }
};
