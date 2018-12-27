//
//  factory.hpp
//  pp_Smart_point
//
//  Created by wudong on 2018/12/23.
//  Copyright © 2018 wudong. All rights reserved.
//

#ifndef factory_hpp
#define factory_hpp

#include <stdio.h>

class abstract
{
public:
    virtual void funcA() = 0;
    virtual void funcB() = 0;
    
protected:
    virtual ~abstract();
};


class Factory:public abstract
{
public:
    Factory() = default;
    virtual ~Factory();
    void funcA();
    void funcB();
};


#endif /* factory_hpp */
