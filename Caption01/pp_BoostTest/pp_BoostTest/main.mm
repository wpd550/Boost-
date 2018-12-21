//
//  main.m
//  pp_BoostTest
//
//  Created by wudong on 2018/12/14.
//  Copyright © 2018 wudong. All rights reserved.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/version.hpp>
#include <boost/config.hpp>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <stdlib.h>
#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/date_time/gregorian/greg_month.hpp>

#include <string>


using namespace boost;
using namespace boost::gregorian;
using namespace std;
//using namespace boost::gregorian::greg_month

void case1(){
    timer t;
    boost::progress_timer t1;
    std::cout<<"Boost版本 ："<<BOOST_VERSION<<std::endl;
    std::cout<<BOOST_PLATFORM<<std::endl;
    std::cout<<BOOST_COMPILER<<std::endl;
    std::cout<<BOOST_STDLIB<<std::endl;
    std::cout<<"now time elapsed:"<<t.elapsed()<<"s"<<std::endl;
    
    progress_display pd(100);
    for(int i = 0;i<100;i++)
    {
        ++pd;
        usleep(100000);
    }
    std::cout<<"now time elapsed:"<<t1.elapsed()<<"s"<<std::endl;
}

void case2()
{

    date d1 ;
    date d2(2010,1,1);
    date d3(2000,Jan,1);
    date d4(d2);
    
    assert(d1 == date(not_a_date_time));
    assert(d2 == d4);
    assert(d3 < d4);
    //本地日期
    std::cout<<day_clock::local_day()<<std::endl;
    //utc 日期
    std::cout<<day_clock::universal_day()<<std::endl;
    date d5(from_string("1992-12-31"));
    std::cout<<d5<<std::endl;
}

void case3()
{
    date d(2007,9,18);
    assert(d.year() == 2007);
    assert(d.month() == 9);
    assert(d.day() == 18);
    auto str = d.year_month_day();
    std::cout<<str.year<<"-"<<str.month<<"-"<<str.day<<endl;
    
    std::cout<<d.day_of_year()<<endl;
    std::cout<<d.day_of_week()<<endl;
    std::cout<<d.week_number()<<endl;
}

void case4()
{
    date d(1992,8,12);
    cout<<to_simple_string(d)<<endl;
}

int main(int argc, const char * argv[]) {
//    case1();
    case2();
    case4();

    
    return 0;
}



