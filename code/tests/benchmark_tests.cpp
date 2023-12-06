#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "PageRank.h"
#include <vector>

using namespace std;


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
      const std::vector<double>& final_ranks = PR.getAllRanks();

      vector<double> expectedPageRankVect = {0.14, 0.153, 0.137, 0.053, 0.123, 0.098, 0.131, 0.037, 0.113, 0.015};

      REQUIRE(final_ranks == expectedPageRankVect);

}



