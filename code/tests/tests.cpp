#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "PageRank.h"
#include <iostream>
#include <filesystem>

using namespace std;

void roundVectorValues(std::vector<double>& vec, int decimalPlaces) {
    double scale = std::pow(10.0, decimalPlaces);
    for (auto& val : vec) {
        val = std::round(val * scale) / scale;
    }
}

TEST_CASE("Small Matrix Vector Multiplication") {
    //identity matrix

    vector<double> expectedMatrix = {0.5, 0.5};
    vector<vector<double>> inputMatrix = {{1, 0}, {0, 1}}; // {1,0} row 0, {0,1} row 1
    vector<double> inputVector = {0.5, 0.5};
    vector<double> result = multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result == expectedMatrix);

  //normal
    vector<double> expectedMatrix2 = {10.5, 10};
    vector<vector<double>> inputMatrix2 = {{4, 0.5}, {0, 2}};
    vector<double> inputVector2 = {2, 5};
    vector<double> result2 = multiplyMatrixByVector(inputMatrix2, inputVector2);
    REQUIRE(result2 == expectedMatrix2);

//   //invalid multiplication, size issues...
    vector<vector<double>> invalid_sized_matrix = {{0.5, 0.5, 0.5, 0.5}, {1}};
    REQUIRE_THROWS_AS(multiplyMatrixByVector(invalid_sized_matrix, inputVector), invalid_argument);

}

TEST_CASE("Medium Matrix Vector Multiplication") {
    //identity matrix 5x5
    vector<double> expectedMatrix = {0.5, 0.5, 0.5, 0.5, 0.5};
    vector<vector<double>> inputMatrix = {{1, 0, 0, 0, 0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}}; 
    vector<double> inputVector = {0.5, 0.5, 0.5, 0.5, 0.5};
    vector<double> result = multiplyMatrixByVector(inputMatrix, inputVector);
    REQUIRE(result == expectedMatrix);

  //normal
    vector<double> expectedMatrix2 = {37.45, 19.4, 35.55, 27.7, 36.9};
    vector<vector<double>> inputMatrix2 = {{3,2,6,7,1}, {1,0.5,2,4,2.5}, {2,9,1,1,6}, {3,4,1.5,4,3.5}, {1,2,7,2,4}};
    vector<double> inputVector2 = {0.4, 2, 3, 1.75, 2};
    vector<double> result2 = multiplyMatrixByVector(inputMatrix2, inputVector2);
    REQUIRE(result2 == expectedMatrix2);

  //invalid multiplication, size issues...
    vector<vector<double>>invalid_sized_matrix = {{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},}; // 5x5
    vector<double> bad_input1 = {1}; // 1x1
    vector<double> bad_input2 = {1,1,1,1}; // 4x1 matrix

    REQUIRE_THROWS_AS(multiplyMatrixByVector(invalid_sized_matrix, bad_input1), invalid_argument);
    REQUIRE_THROWS_AS(multiplyMatrixByVector(invalid_sized_matrix, bad_input2), invalid_argument);
}
TEST_CASE("Large Matrix Vector Multiplication") {
  
    vector<double> expectedMatrix = {101.3, 90.65, 57.9, 73.8, 75.4, 41.18, 42.2, 54, 95.62, 28.6, 65.02, 30.52, 63, 84.4, 54.3};
    vector<vector<double>> inputMatrix = 
                                    {{3,0,3,0,2,0,0,3,0,3,0,10,3,0,0},
                                    {2,4,0,1,0,0,0,0,1,3.6,2,0,0,9.3,2},
                                    {1,5,0,0,0,0,7.2,3,0,0,0,2,0,0,3},
                                    {0,4,0,1,3,5,5,0,1,0,5,5,1,0,0},
                                    {5,5, 1, 2, 0, 2, 0, 5, 0, 0, 10, 0, 0, 2, 1},
                                    {0, 2, 0, 0, 1, 5, 10, 0, 0, 3.9, 0, 0, 1, 0, 0},
                                    {1, 0, 1, 0, 0, 3, 2, 1.6, 0, 0, 0, 2.4, 0, 2, 0},
                                    {0, 0, 2, 2.5, 2, 1, 0 , 2, 10, 1, 0, 2, 0, 0, 1}, 
                                    {3, 0, 2, 5, 0, 3, 0, 1, 0, 10, 0, 3, 0, 1.2, 3},
                                    {0, 1.2, 3, 0, 0, 0, 2, 0, 5, 0, 1.2, 0, 2, 1,0},
                                    {2, 0, 10, 0, 1.2, 3, 0, 1, 0, 0, 0, 3, 0, 0, 3}, 
                                    {1, 2, 2, 0, 0, 1.2, 0, 2, 2, 1, 5, 0,1,0,0},
                                    {0, 1.2, 3, 2, 0, 10, 0, 0, 0, 3, 2, 2, 0, 3, 0},
                                    {0, 0 ,2, 5, 1, 0, 1, 2, 1.2, 0, 0, 5, 0, 1, 3},
                                    {1,2,1, 0, 3, 0, 1, 0, 0, 1, 0, 3, 0, 3, 0}};
    vector<double> inputVector = {2, 0.5, 1.5, 3, 3.1, 1.1, 2, 3, 1, 2.2, 2, 6, 3, 6.1, 6};
    vector<double> result = multiplyMatrixByVector(inputMatrix, inputVector);
    roundVectorValues(result, 2);
    REQUIRE(result == expectedMatrix);

}

TEST_CASE("Test Constructor on 3 Webpages File") { 
   PageRank p = PageRank("./data/pages.csv", .8);
   REQUIRE(p.getAdjacencyMatrix().size() == 3);
   REQUIRE(p.getAdjacencyMatrix().at(0).size() == 3);
   std::vector<std::vector<double>> adj = {{0,.5,1}, {1,.5,0}, {0,0,0}};
   REQUIRE(p.getAdjacencyMatrix() == adj);
}

TEST_CASE("Test Constructor on 4 Webpages File") {   
   PageRank p = PageRank("./data/4WebPages.csv", .8);
   REQUIRE(p.getAdjacencyMatrix().size() == 4);
   REQUIRE(p.getAdjacencyMatrix().at(0).size() == 4);
   std::vector<std::vector<double>> adj = {
//source   A    B   C    D 
          {0  , .5,  .333,  1}, // to A
          {.5  , 0 ,  .333,  0}, // to B
          {.5  , .5, 0  ,  0}, // to C
          {0  ,0  , .333,  0}}; // to D
   std::vector<std::vector<double>> result = p.getAdjacencyMatrix();
   for (auto& inner : result) {
      roundVectorValues(inner, 3);
   }
   REQUIRE(result == adj);
}

TEST_CASE("Test Constructor on 10 Webpages File") { 
  PageRank p = PageRank("./data/10WebPages.csv", .8);
  vector<vector<double>> normalizedAdjacencyMatrix = {

    //    Ama  Goo  Link  Net  Pint Red  Twit Wiki  YT  Zoom
    /*A*/ {0, .167, 0, .5, 0, 0, .25, 0, .5, .333}, // from Page1
    /*G*/ {.25, 0, 0, 0, .5, .5, 0, .333, 0, .333}, // from Page2
    /*L*/ {0, .167, 0, 0, .5, 0, 0, 0, .5, 0}, // from Page3
    /*N*/ {0, 0, 0, 0, 0, 0, .25, .333, 0, 0}, // from Page4
    /*P*/ {0, .167, .5, 0, 0, 0, .25, 0, 0, 0}, // from Page5
    /*R*/ {.25, .167, 0, 0, 0, 0, .25, 0, 0, .333}, // from Page6
    /*T*/ {.25, .167, 0, .5, 0, .5, 0, 0, 0, 0}, // from Page7
    /*W*/ {0, .167, 0, 0, 0, 0, 0, 0, 0, 0}, // from Page8
    /*Y*/ {.25, 0, .5, 0, 0, 0, 0, .333, 0, 0}, // from Page9
    /*Z*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // from Page10
};
  std::vector<std::vector<double>> result = p.getAdjacencyMatrix();
  for (auto& inner : result) {
      roundVectorValues(inner, 3);
  }
  REQUIRE(result == normalizedAdjacencyMatrix);
}

TEST_CASE("Page Rank Calculation 2x2") {
    // this is the matrix we are working with just for ease of understanding
    vector<vector<double>> normalizedAdjacencyMatrix = {
//source   A    B 
          {0  , 0}, // to A
          {1  , 0}, // to B
    };
    // Reasonably, B should have the larger Page Rank
      PageRank PR2("./data/2WebPages.csv",0.85);
      PR2.calculatePageRank(100, 0.001);
      std::vector<double> final_ranks = PR2.getAllRanks();

      vector<double> expectedPageRankVect = {0.351, 0.649};
      roundVectorValues(final_ranks, 3);
      REQUIRE(final_ranks == expectedPageRankVect);
      REQUIRE(PR2.getWebsiteRank("A") == 2);
      REQUIRE(PR2.getWebsiteRank("B") == 1);
}

TEST_CASE("Page Rank Calculation 4x4") {
    // this is the matrix we are working with just for ease of understanding
    vector<vector<double>> normalizedAdjacencyMatrix = {
//source   A    B   C    D 
          {0  , .5 ,  .33,  1}, // to A
          {.5  , 0 ,  .33,  0}, // to B
          {.5  ,.5  ,0  ,  0}, // to C
          {0  ,0  , .33 ,  0}}; // to D

      
  //from just looking at it, we can see A is the destination of 3 links, so we can maybe guess it will have the largest pagerank
  //D is the destination of only one link, so it may have the smallest pagerank.
  
      PageRank PR("./data/4WebPages.csv",0.85);
      PR.calculatePageRank(100, 0.001);
      std::vector<double> final_ranks = PR.getAllRanks();

      vector<double> expectedPageRankVect = {0.332, 0.260, 0.289, 0.119};
      roundVectorValues(final_ranks, 3);
      REQUIRE(final_ranks == expectedPageRankVect);
      REQUIRE(PR.getWebsiteRank("A") == 1);
      REQUIRE(PR.getWebsiteRank("B") == 3);
      REQUIRE(PR.getWebsiteRank("C") == 2);
      REQUIRE(PR.getWebsiteRank("D") == 4);
}

TEST_CASE("Page Rank Calculation 10x10") {
    // this is the matrix we are working with just for ease of understanding
  /* vector<vector<double>> AdjacencyMatrix = {
      [0,1,0,1,0,0,1,0,1,1], to Amazon
      [1,0,0,0,1,1,0,1,0,1], to Google
      [0,1,0,0,1,0,0,0,1,0], to Linkedin
      [0,0,0,0,0,0,1,1,0,0], to NetFlix
      [0,1,1,0,0,0,1,0,0,0], to Pinterest
      [1,1,0,0,0,0,1,0,0,1], to Reddit
      [1,1,0,1,0,1,0,0,0,0], to Twitter
      [0,1,0,0,0,0,0,0,0,0], to Wiki
      [1,0,1,0,0,0,0,1,0,0], to Youtube
      [0,0,0,0,0,0,0,0,0,0] to Zoom
    } */
      PageRank PR("./data/10WebPages.csv",0.85);
      PR.calculatePageRank(100, 0.001);
      std::vector<double> final_ranks = PR.getAllRanks();

      vector<double> expectedPageRankVect = {0.140, 0.153, 0.137, 0.053, 0.123, 0.098, 0.131, 0.037, 0.113, 0.015};
      roundVectorValues(final_ranks, 3);
      REQUIRE(final_ranks == expectedPageRankVect);
      REQUIRE(PR.getWebsiteRank("Google") == 1);
      REQUIRE(PR.getWebsiteRank("Amazon") == 2);
      REQUIRE(PR.getWebsiteRank("Wikipedia") == 9);
}

