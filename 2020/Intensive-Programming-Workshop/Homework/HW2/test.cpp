#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Counter.hpp"



TEST_CASE( "testing with int", "[count]") {
    std::vector<int> v1 (4,1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(5);
    Counter c(v1);
    REQUIRE(c.Count() == 13);
    REQUIRE(c.Count(1) == 4);
    REQUIRE(c.Count(2) == 3);
    REQUIRE(c.Count(1,3) == 7);
    c.Increment(1);
    REQUIRE(c.Count(1) == 5);
    c.Increment(1,3);
    REQUIRE(c.Count(1) == 8);
    REQUIRE(c.MostCommon() == 1);
    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    REQUIRE(c.MostCommon(2) == v2);
    REQUIRE(c.LeastCommon() == 5);
    std::map<int,double> m1;
    m1[1] = 8/17;
    m1[2] = 3/17;
    m1[3] = 5/17;
    m1[5] = 1/17;
    REQUIRE(c.Normalized() == m1);
    std::set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(5);
    REQUIRE(c.Keys() == s1);


}

