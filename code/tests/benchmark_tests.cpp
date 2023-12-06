#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "PageRank.h"
#include <vector>

using namespace std;


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
      PageRank::calculatePageRank(100, 0.001);
      const std::vector<double>& final_ranks = PageRank::getAllRanks();

      vector<double> expectedPageRankVect = {0.33, 0.26, 0.29, 0.12};

      REQUIRE(final_ranks == expectedPageRankVect);

}


TEST_CASE("Page Rank Calculation 3x3 No ") {
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
      PageRank::calculatePageRank(100, 0.001);
      const std::vector<double>& final_ranks = PageRank::getAllRanks();

      vector<double> expectedPageRankVect = {0.33, 0.26, 0.29, 0.12};

      REQUIRE(final_ranks == expectedPageRankVect);


}