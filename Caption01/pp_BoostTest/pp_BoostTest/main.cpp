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
#include <boost/asio/ip/address.hpp>

using namespace boost;
using namespace boost::gregorian;

int main(int argc, const char * argv[]) {
    
    {
//        timer t;
        progress_timer t1;
        std::cout<<"Boost版本 ："<<BOOST_VERSION<<std::endl;
        std::cout<<BOOST_PLATFORM<<std::endl;
        std::cout<<BOOST_COMPILER<<std::endl;
        std::cout<<BOOST_STDLIB<<std::endl;
//        std::cout<<"now time elapsed:"<<t.elapsed()<<"s"<<std::endl;
        
//        progress_display pd(100);
//        for(int i = 0;i<100;i++)
//        {
//            ++pd;
//            usleep(100000);
//        }
        std::cout<<"now time elapsed:"<<t1.elapsed()<<"s"<<std::endl;
      
    }
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
        date d5 = boost::asio::ip::from_string(day_clock::local_day());
        std::cout<<d5<<std::endl;
    }
    return 0;
}
