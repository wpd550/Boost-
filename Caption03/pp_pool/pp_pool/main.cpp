//
//  main.cpp
//  pp_pool
//
//  Created by wudong on 2018/12/27.
//  Copyright © 2018 wudong. All rights reserved.
//

#include <iostream>
#include <boost/version.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>

using namespace boost;

//简单内存池的使用 POD
void case1()
{
    pool<> pl(sizeof(int));
    int *p = static_cast<int*>(pl.malloc());
    assert(pl.is_from(p));
    std::cout<<"*p == "<<*p<<"\n";
    pl.free(p); //一般不需要调用，只有在你认为内存池不够用的时候才调用
    
    for(int i=0;i<100;i++)
    {
        int *p1 = static_cast<int*>(pl.ordered_malloc(10)); //连续的10个int
    }
    
}

class demo {
public:
    int a,b,c;
    demo(int a1,int b1,int c1):a(a1),b(b1),c(c1){}
    
};

void case2()
{
    object_pool<demo> pl;
    
    demo *p = pl.construct(2,3,4);
    
    assert(p->a == 2);
}
int main(int argc, const char * argv[]) {
    std::cout << "version == " <<BOOST_VERSION<<"\n";
    
//    case1();
    case2();
    return 0;
}
