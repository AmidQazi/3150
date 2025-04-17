#include "lab7.h"
#include <iostream>
#include <string>

BigFraction product_bigint( BigFraction &a,BigFraction &b)
{
    bigint nume = a.first * b.first;
    bigint deno = a.second * b.second;
    return {nume, deno};
}

BigFraction sum_bigint( BigFraction &a,  BigFraction &b)
{
    bigint nume = a.first*b.second + a.second*b.first;
    bigint deno = a.second * b.second;
    return {nume, deno};
}

TEST_CASE("sum. product test")
{
    BigFraction a = {bigint("2"), bigint("3")}; //  2/3
    BigFraction b = {bigint("2"), bigint("5")}; //  2/5

    BigFraction sum_ab = sum_bigint(a,b); // 16/15
    CHECK(sum_ab.first == bigint("16"));
    CHECK(sum_ab.second == bigint("15"));

    BigFraction product_ab = product_bigint(a,b); // 4/15
    CHECK(product_ab.first == bigint("4"));
    CHECK(product_ab.second == bigint("15"));

}