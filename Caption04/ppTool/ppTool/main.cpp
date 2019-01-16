//
//  main.cpp
//  ppTool
//
//  Created by wudong on 2019/1/11.
//  Copyright © 2019 wudong. All rights reserved.
//

#include <iostream>
#include <boost/noncopyable.hpp> //不可拷贝类
#include <boost/version.hpp>
#include <vector>
#include <string>

class do_not_copy: boost::noncopyable
{
public:
    int a =10;
};


//template<class T>
//struct Alloc{};
//template<class T>
//using Vec = std::vector<T,Alloc<T>>;
//Vec<int> V;


template<class T>
struct A;


template <typename InputIterator>
std::pair<InputIterator, size_t> max_sequence(InputIterator first,
                                              InputIterator last)
{
    InputIterator maxfirst = last;
    size_t maxlen = 0;
    while (first != last) {
        InputIterator seqfirst = first;
        size_t len = 1;
        InputIterator prev = seqfirst;
        ++first;
        while (first != last && *prev + 1 == *first) {
            ++len;
            prev = first;
            ++first;
        }
        if (maxlen < len) {
            maxlen = len;
            maxfirst = seqfirst;
        }
    }
    return std::pair<InputIterator, size_t>(maxfirst, maxlen);
}

struct MyStruct
{
    MyStruct(int&& a){
        std::cout<<"右值引用 a = "<<++a<<std::endl;
    }
    MyStruct(int& a)
    {
        std::cout<<"左值引用 a = "<<a<<std::endl;
    }
};

#define PP 5
void case4()
{
    MyStruct mystruct(PP);
    int a=20;
    MyStruct mystruct1(std::forward<int>(a));
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"PP ="<<PP<<std::endl;
    
    std::string str1 = "domon";
    std::string str2 = "hp";
    std::cout<<"str1 = "<<str1<<std::endl;
    std::string str3 = std::move(str1);
    std::cout<<"str1 = "<<str1<<std::endl;
    
}

template<typename T>
void test1(T&& t)
{
    std::cout<<"rValue"<<std::endl;
}
template<typename T>
void test1(T& t)
{
    std::cout<<"lValue"<<std::endl;
}

template <typename T>
void test2(T&& t) {
    test1(t);
    test1(std::move(t));
    test1(std::forward<T>(t));
}


void case5()
{
    test2(10);
    int a=10;
    std::cout<<"-----------------\n";
    test2(a);// a 默认被转化为lValue
    /**
     lValue
     rValue
     lValue
     */
    std::cout<<"-----------------\n";
    test2(std::forward<int>(a)); //保持右值引用
    /**
     lValue
     rValue
     rValue
     */
    std::cout<<"-----------------\n";
    test2(std::move(a)); //保持右值引用,move 函数对内置变量无效，对类使用
    std::cout<<"a = "<<a<<std::endl;
}


//不可拷贝类
void case1()
{
    do_not_copy A;
    std::cout<<A.a<<std::endl;
//    do_not_copy B(A);  //不支持拷贝构造g函数
    do_not_copy C;
//    C = A;      // 不支持复制构造函数
    
}

void case2()
{
    using flags =std::ios_base::fmtflags;
    flags fl = std::ios_base::dec;
}

void case3()
{
    std::vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vec1(10);
    std::copy(vec.begin(), vec.end(), vec1.begin());
    for(auto&& i: vec1)
    {
        std::cout<<i<<std::endl;
    }
    
    max_sequence(vec.begin(), vec.end());
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "version: "<< BOOST_VERSION<<"\n";
    
//    case3();
//    case4();
    case5();
    return 0;
}
