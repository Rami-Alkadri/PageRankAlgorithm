#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include "PageRank.h"
#include <vector>
#include <unordered_map>


using namespace std;

bool compareMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    if (matrix1.size() != matrix2.size()) return false;
    for (size_t i = 0; i < matrix1.size(); ++i) {
        if (matrix1[i].size() != matrix2[i].size()) return false;
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            if (matrix1[i][j] != matrix2[i][j]) return false;
        }
    }
    return true;
}

TEST_CASE("Matrix Multiplied by Vector") {
    vector<double> expectedMatrix = {0.5, 0.5};
    vector<vector<double>> inputMatrix = {{1, 0}, {0, 1}};
    vector<double> inputVector = {0.5, 0.5};
    

}