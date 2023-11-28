#include <catch2/catch_test_macros.hpp>
#include "PageRank.h"

TEST_CASE("CSV File Reader") {
    PageRank pr("webpages.csv", 0.85); 
    REQUIRE(pr.getNumberOfPages() == 10); 
}

TEST_CASE("Empty CSV File") {
    PageRank pr("empty.csv", 0.85);
    REQUIRE_THROWS_AS(pr.calculatePageRank(), std::runtime_error);
}

TEST_CASE("Invalid CSV File Format") {
    PageRank pr("invalid_format.csv", 0.85);
    REQUIRE_THROWS_AS(pr.calculatePageRank(), std::runtime_error); 
}

TEST_CASE("Matrix Multiplication") {
    PageRank pr("webpages.csv", 0.85);
    std::vector<double> testVector = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    std::vector<double> result = pr.multiplyMatrix(testVector); 
    std::vector<double> expected = {0.1, 0.15, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.05}; 
    REQUIRE(result == expected);
}

TEST_CASE("PageRank Calculation") {
    PageRank pr("webpages.csv", 0.85);
    pr.calculatePageRank();
    std::vector<double> ranks = pr.getPageRanks(); 
    REQUIRE(ranks.size() == 10);
}

TEST_CASE("Damping Factor Effect") {
    PageRank pr1("webpages.csv", 0.85);
    PageRank pr2("webpages.csv", 0.95);
    pr1.calculatePageRank();
    pr2.calculatePageRank();
    REQUIRE(pr1.getPageRanks() != pr2.getPageRanks());
}

TEST_CASE("Adjacency Matrix Generation") {
    PageRank pr("webpages.csv", 0.85);
    auto adjacencyMatrix = pr.getAdjacencyMatrix(); 
}