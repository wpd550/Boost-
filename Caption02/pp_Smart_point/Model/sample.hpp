//
//  sample.hpp
//  pp_Smart_point
//
//  Created by wudong on 2018/12/23.
//  Copyright © 2018 wudong. All rights reserved.
//

#ifndef sample_hpp
#define sample_hpp

#include <stdio.h>
#include <boost/smart_ptr.hpp>
#include <iostream>

class sample
{
    
private:
    class impol;
    boost::shared_ptr<impol> p;
public:
    sample();
    void print();
};

class node
{
public:
    ~node()
    {
        std::cout<<"delete \n";
    }
    typedef boost::shared_ptr<node> ptr_type;
    ptr_type next;
};

struct counted_data
{
    int m_count = 0;
    
};


#endif /* sample_hpp */
