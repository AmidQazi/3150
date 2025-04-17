#ifndef LAB7_H
#define LAB7_H

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include <iostream>
#include "bigint.h"

#include <utility>

using BigFraction = std::pair<bigint, bigint>;

BigFraction product_bigint( BigFraction &a,  BigFraction &b);

BigFraction sum_bigint( BigFraction &a,  BigFraction &b);


#endif