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

TEST_CASE("Small Matrix Vector Multiplication") {
    //identity matrix
    vector<double> expectedMatrix = {0.5, 0.5};
    vector<vector<double>> inputMatrix = {{1, 0}, {0, 1}}; // {1,0} row 0, {0,1} row 1
    vector<double> inputVector = {0.5, 0.5};
    vector<double> result = PageRank::multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result == expectedMatrix);

  //normal
    vector<double> expectedMatrix2 = {10.5, 10};
    vector<vector<double>> inputMatrix2 = {{4, 0.5}, {0, 2}};
    vector<double> inputVector2 = {2, 5};
    vector<double> result2 = PageRank::multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result2 == expectedMatrix2);

  //invalid multiplication, size issues...
    vector<double> invalid_sized_matrix = {0.5, 0.5, 0.5, 0.5};
    REQUIRE_THROWS_AS(mPageRank::multiplyMatrixByVector(invalid_sized_matrix, inputVector), invalid_argument);

}

TEST_CASE("Medium Matrix Vector Multiplication") {
    //identity matrix 5x5
    vector<double> expectedMatrix = {0.5, 0.5, 0.5, 0.5, 0.5};
    vector<vector<double>> inputMatrix = {{1, 0, 0, 0, 0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}}; 
    vector<double> inputVector = {0.5, 0.5, 0.5, 0.5, 0.5};
    vector<double> result = PageRank::multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result == expectedMatrix);

  //normal
    vector<double> expectedMatrix2 = {37.45, 19.4, 35.55, 27.7, 36.9};
    vector<vector<double>> inputMatrix2 = {{3,2,6,7,1}, {1,0.5,2,4,2.5}, {2,9,1,1,6}, {3,4,1.5,4,3.5}, {1,2,7,2,4}};
    vector<double> inputVector2 = {0.4, 2, 3, 1.75, 2};
    vector<double> result2 = PageRank::multiplyMatrixByVector(inputMatrix2, inputVector2);
    REQUIRE(result2 == expectedMatrix2);

  //invalid multiplication, size issues...
    vector<vector<double>>invalid_sized_matrix = {{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},}; // 5x5
    vector<double> bad_input1 = {1}; // 1x1
    vector<double> bad_input2 = {1,1,1,1}; // 4x1 matrix

    REQUIRE_THROWS_AS(mPageRank::multiplyMatrixByVector(invalid_sized_matrix, bad_input1), invalid_argument);
    REQUIRE_THROWS_AS(mPageRank::multiplyMatrixByVector(invalid_sized_matrix, bad_input2), invalid_argument);
}
TEST_CASE("Large Matrix Vector Multiplication") {
  
    vector<double> expectedMatrix = {101.3, 90.65, 57.9, 73.8, 75.4, 41.18, 42.2, 54, 95.62, 28.6, 65.02, 30.52, 63, 84.4, 54.3};
    vector<vector<double>> inputMatrix = {{3,0,3,0,2,0,0,3,0,3,0,10,3,0,0},{2,4,0,1,0,0,0,0,1,3.6,2,0,0,9.3,2},{1,5,0,0,0,0,7.2,3,0,0,0,2,0,0,3},{0,4,0,1,3,5,5,0,1,0,5,5,1,0,0},{5,5, 1, 2, 0, 2, 0, 5, 0, 0, 10, 0, 0, 2, 1},{0, 2, 0, 0, 1, 5, 10, 0, 0, 3.9, 0, 0, 1, 0, 0},{1, 0, 1, 0, 0, 3, 2, 1.6, 0, 0, 0, 2.4, 0, 2, 0},{0, 0, 2, 2.5, 2, 1, 0 , 2, 10, 1, 0, 2, 0, 0, 1}, {3, 0, 2, 5, 0, 3, 0, 1, 0, 10, 0, 3, 0, 1.2, 3},{0, 1.2, 3, 0, 0, 0, 2, 0, 5, 0, 1.2, 0, 2, 1,0},{2, 0, 10, 0, 1.2, 3, 0, 1, 0, 0, 0, 3, 0, 0, 3}, {1, 2, 2, 0, 0, 1.2, 0, 2, 2, 1, 5, 0,1,0,0},{0, 1.2, 3, 2, 0, 10, 0, 0, 0, 3, 2, 2, 0, 3, 0},{0, 0 ,2, 5, 1, 0, 1, 2, 1.2, 0, 0, 5, 0, 1, 3},{1,2,1, 0, 3, 0, 1, 0, 0, 1, 0, 3, 0, 3, 0}};
    vector<double> inputVector = {2, 5};
    vector<double> result = PageRank::multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result == expectedMatrix);

}