#include "lab5.h"
#include<fstream>
#include<iostream>
#include<cmath>

std::vector<std::vector<double>> readVecs(const std::string& filename)
{
    std::ifstream fin(filename);

    //k: dimension, n: number of vecs
    int n, k;
    fin >> n >> k; 

    std::vector<std::vector<double>> vecs; //2D
    for (int i = 0; i < n; i++){
        std::vector<double> v;
        v.reserve(k);

        for(int j = 0; j< k;  j++)
        {
            double v_value;
            fin >> v_value;
            v.push_back(v_value); //read values for each vector: v_x, v_y, v_z ... v_k
        }
        vecs.push_back(v);  // read vectors : v1, v2, v3 ... vn
    }
    
    return vecs;
}

// cos-distance
// dot-product
static double dotP(const std::vector<double>& u, const std::vector<double>& v)
    {
        double result = 0.0;
        for (int i = 0; i < u.size(); i++){
            result += u[i] * v[i];
        }
        return result;
    }

//euc_distance norm
static double norm(const std::vector<double>& u)
    {
        double result= 0.0;
        for (double i : u)
        {
            result += i * i; // i ** 2
        }
        return std::sqrt(result);
    }

double cos_distance(const std::vector<double>& u, const std::vector<double>& v ){
        double dot_u_v = dotP(u, v);
        double norm_u = norm(u);
        double norm_v = norm(v);

        double cos_similarity_u_v = dot_u_v / (norm_u * norm_v);
        return (1.0 - cos_similarity_u_v); 
    }

std::vector<pair_vecs> distance_pairs(const std::vector<std::vector<double>>& vecs)
{
    std::vector<pair_vecs> pair_distances;
    int n = static_cast<int>(vecs.size()); // get number of vectors

    // n*(n-1)/2
    for(int i=0; i < n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double cos_distance_value = cos_distance(vecs[i], vecs[j]);
            pair_distances.push_back({i, j, cos_distance_value});
        }
    }
    return pair_distances;
}

bool compare_cos_distance(const pair_vecs& pair1, const pair_vecs& pair2 )
{
    return pair1.cos_distance < pair2.cos_distance;
    // pair1.cos_distance < pair2.cos_distance return TRUE
}

TEST_CASE("Test functions: dotP, norm, cos_distance")
{
    std::vector<double> v1{0.0, 1.0};
    std::vector<double> v2{1.0, 0.0};
    CHECK(cos_distance(v1, v2) == 1.0);
}

TEST_CASE("Test functions: distance_pairs"){
    std::vector<std::vector<double>> vectors{
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 1.0}
    };

    auto pairs_results = distance_pairs(vectors); //n = 3
    // n*(n-1) /2 = 3 
    CHECK(pairs_results.size() == 3);

    // mannual
    double d1 = 1.0 - 1.0/(std::sqrt(2.0));
    double d2 = 1.0 - 1.0/(std::sqrt(2.0));
    double d3 = 1;

    bool match01=false; 
    for (auto &pair_distance :pairs_results )
    {
        if(pair_distance.vec1 == 0 && pair_distance.vec2 == 1)
        {
            CHECK(d1 == pair_distance.cos_distance );
            match01 = true; 
        }
    }
    CHECK(match01);
}
TEST_CASE("Test func: readVecs, compare_cos_distance")
{
    std::string file_name = "vectors_file.txt";
    auto vectors = readVecs(file_name);
    CHECK(vectors.size() == 5); //n = 4, function readVecs works

    // k = 2
    for(const auto& vec : vectors){
        CHECK(vec.size() == 5);
    }
    
    // compute cos distance
    auto distances = distance_pairs(vectors);
    //n=4, n*(n-1)/2
    CHECK(distances.size() == 10);

    //compare_cos_distance
    std::sort(distances.begin(), distances.end(), compare_cos_distance);

    std::cout << "Sorted vector pairs:\n";
    for(const auto& pair_vec : distances)
    {
        std::cout << "vector1_index: " << pair_vec.vec1 << "\tvector2_index: " << pair_vec.vec2 << "\t cos_distance: " << pair_vec.cos_distance <<"\n";
    }
}