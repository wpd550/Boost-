//
//  factory.cpp
//  pp_Smart_point
//
//  Created by wudong on 2018/12/23.
//  Copyright © 2018 wudong. All rights reserved.
//

#include "factory.hpp"
#include <iostream>


Factory::~Factory()
{
    std::cout<<"Factory 析构函数 \n";
}

abstract::~abstract()
{
    std::cout<<"abstrct 析构函数 \n";
}

void Factory::funcA()
{
    std::cout<<"I'm come from funcA \n";
}

void Factory::funcB()
{
    std::cout<<"I'm come from funcB \n";
}
