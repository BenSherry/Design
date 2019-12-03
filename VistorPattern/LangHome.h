//
// Created by SHERRY on 2019/5/11.
//

#ifndef VISTOR_PATTERN_LANGHOME_H
#define VISTOR_PATTERN_LANGHOME_H
#include "RealCoder.h"
#include"Languages.h"
#include <list>
#include<algorithm>
using SharedLangs = std::shared_ptr<ILangElement>;
class LangHome
{
public:
    void Attach(SharedLangs lang)
    {
        langs_.push_back(lang);
    }

    void  Detach(SharedLangs lang)
    {
        langs_.remove(lang);
    }

    void Accept(std::shared_ptr<Ivisitor> visitor)
    {
        /*
         * 下面三种方式都完成了对list的遍历操作
         * 即list里面的每一个被访问者都会接受访问者
         * /
        /*for (auto it = langs_.begin(); it != langs_.end(); ++it)
        {
            (*it)->Accept(visitor);
        }*/
      /* for(const auto & lang:langs_)
        {
            lang->Accept(visitor);
        }*/
       std::for_each(langs_.begin(),langs_.end(),[visitor]( std::shared_ptr<ILangElement> p){p->Accept(visitor);});

    }
private:
    std::list<SharedLangs> langs_;

};
#endif //VISTOR_PATTERN_LANGHOME_H
