#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

struct VectorPair {
    int index1, index2;
    double similarity;
};

// Function to compute the dot product
double dotProduct(const vector<double>& a, const vector<double>& b) {
    double product = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        product += a[i] * b[i];
    }
    return product;
}

// Function to compute the magnitude of a vector
double magnitude(const vector<double>& v) {
    double sum = 0.0;
    for (double val : v) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Function to calculate cosine similarity
double cosineSimilarity(const vector<double>& a, const vector<double>& b) {
    return dotProduct(a, b) / (magnitude(a) * magnitude(b));
}

int main() {
    ifstream infile("vectors.txt");
    vector<vector<double>> vectors;
    string line;

    // Reading vectors from file
    while (getline(infile, line)) {
        stringstream ss(line);
        vector<double> vec;
        double num;
        while (ss >> num) {
            vec.push_back(num);
        }
        if (!vec.empty()) {
            vectors.push_back(vec);
        }
    }

    vector<VectorPair> results;
    int n = vectors.size();

    // Calculating cosine similarity for all pairs
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double sim = cosineSimilarity(vectors[i], vectors[j]);
            results.push_back({i, j, sim});
        }
    }

    // Sorting pairs by cosine similarity (descending)
    sort(results.begin(), results.end(), [](const VectorPair& a, const VectorPair& b) {
        return a.similarity > b.similarity;
    });

    // Displaying the pairs sorted by similarity
    for (const auto& pair : results) {
        cout << "Vector " << pair.index1 + 1 << " and Vector " << pair.index2 + 1 << ": Cosine Similarity = " << pair.similarity << endl;
    }

    return 0;
}
