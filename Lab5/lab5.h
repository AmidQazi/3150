#ifndef LAB5_H
#define LAB5_H

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>

struct pair_vecs{
    int vec1;
    int vec2;
    double cos_distance; 
};

// read vectors from a given file
std::vector<std::vector<double>> readVecs(const std::string& filename);

double cos_distance(const std::vector<double>& u, const std::vector<double>& v );

std::vector<pair_vecs> distance_pairs(const std::vector<std::vector<double>>& vecs);

bool compare_cos_distance(const pair_vecs& pair1, const pair_vecs& pair2 );

#endif