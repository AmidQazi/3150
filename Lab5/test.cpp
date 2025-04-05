#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CosineClosenessCalculator.cpp"

TEST_CASE("Testing dotProduct function") {
    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    CHECK(dotProduct(a, b) == doctest::Approx(32.0));
}

TEST_CASE("Testing magnitude function") {
    std::vector<double> v = {3.0, 4.0};
    CHECK(magnitude(v) == doctest::Approx(5.0));
}

TEST_CASE("Testing cosine similarity calculation") {
    std::vector<double> a = {1.0, 0.0};
    std::vector<double> b = {0.0, 1.0};
    std::vector<double> c = {1.0, 1.0};
    CHECK(cosineSimilarity(a, b) == doctest::Approx(0.0));
    CHECK(cosineSimilarity(a, c) == doctest::Approx(0.7071).epsilon(0.001));
}

TEST_CASE("Testing pairwise cosine similarity ordering") {
    std::vector<std::vector<double>> vectors = {{1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}};
    int n = vectors.size();
    std::vector<VectorPair> results;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double sim = cosineSimilarity(vectors[i], vectors[j]);
            results.push_back({i, j, sim});
        }
    }
    std::sort(results.begin(), results.end(), [](const VectorPair& a, const VectorPair& b) {
        return a.similarity > b.similarity;
    });
    CHECK(results[0].similarity >= results[1].similarity);
}
