//
//  sample.cpp
//  pp_Smart_point
//
//  Created by wudong on 2018/12/23.
//  Copyright © 2018 wudong. All rights reserved.
//

#include "sample.hpp"
#include <iostream>

class sample::impol
{
public:
    void  print()
    {
        std::cout<<"impl print"<<std::endl;
    }
};

sample::sample():p(new impol){}

void sample::print()
{
    p->print();
}
