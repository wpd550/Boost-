//
//  main.cpp
//  pp_Smart_point
//
//  Created by wudong on 2018/12/21.
//  Copyright © 2018 wudong. All rights reserved.
//

#include <iostream>
#include <boost/version.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/make_unique.hpp>
#include <string>
#include "sample.hpp"
#include "factory.hpp"
using namespace boost;
using namespace std;


class Ando {
public:
    Ando(){}
    ~Ando(){
        std::cout<<"Ando 对象析构"<<endl;
    }
    
    
public:
    int a;
};

//scoped_ptr 不能指向数组
/**
 1.
 */
void case1()
{
    scoped_ptr<std::string> sp(new std::string("text"));
    scoped_ptr<Ando> sa(new Ando); //自动释放
    cout<<"I'm Scoped point :"<<*sp<<endl;

    //delete sa; 错误 智能指针自行管理指正对象
    //sp = nullptr; 错误 复制构造私有化
    
    scoped_ptr<int> sp1(new int);
    cout<<*sp1<<endl;
    
}

//unique_ptr
/**
 1. 改变指向对象的时候，源对象自动释放
 2. 不能指向数组
 3. 使用release可以释放指针的管理全，reset  释放指针
 
 */
void case2()
{
    unique_ptr<std::string> uq(new std::string("Ando Master"));
    unique_ptr<Ando> uq1 ,uq2;
    uq1 = boost::make_unique<Ando>();
    uq1 = boost::make_unique<Ando>();
    uq1.release();
    cout<<*uq<<endl;

}

//shared_ptr

/**
 智能指针，采用引用计数，可以赋值操作
 **/
void case3()
{
    boost::shared_ptr<std::string> sp =boost::make_shared<std::string>("VPN");
    
    cout<<"*sp ---> "<<*sp<<endl;
    cout<<"sp.cout"<<sp.use_count()<<"\n";

    {
        boost::shared_ptr<std::string> sp1 = sp;
        cout<<"sp.cout"<<sp.use_count()<<"\n";
    }
    //sp.reset();
    
    assert(sp.unique());
    assert(sp);
    cout<<"sp.cout"<<sp.use_count()<<"\n";
    cout<<"*sp ---> "<<*sp<<endl;
}

/** share_ptr
 1. 使用桥接模式
 */
void case4()
{
    sample s;
    s.print();
}


//此处可以创建工厂构造
boost::shared_ptr<Factory> creat()
{
    return boost::make_shared<Factory>();
}

// 工厂类自动管理对象模型
void case5()
{
    auto factory = creat();
    factory->funcA();
    factory->funcB();
}

// 循环引用
void case6()
{
    auto p1 = boost::make_shared<node>();
    auto p2 = boost::make_shared<node>();
    p1->next = p2;
    cout<<"p2.use_count = "<<p2.use_count()<<endl;
    p2->next = p1;
    cout<<"p1.use_count = "<<p1.use_count()<<endl;
}

void intrusive_ptr_add_ref(counted_data* p)
{
    ++p->m_count;
}
void intrusive_ptr_release(counted_data* p)
{
    if(--p->m_count == 0)
    {
        delete p;
    }
}

void case7()
{
   
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout <<"Boost-Version: " <<BOOST_VERSION<<std::endl;
    
//    case1();
//    case2();
//    case3();
//    case4();
//    case5();
    case6();
    
    return 0;
}
