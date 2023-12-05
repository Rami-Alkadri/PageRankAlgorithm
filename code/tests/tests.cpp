#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// bool compareMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
//     if (matrix1.size() != matrix2.size()) return false;
//     for (size_t i = 0; i < matrix1.size(); ++i) {
//         if (matrix1[i].size() != matrix2[i].size()) return false;
//         for (size_t j = 0; j < matrix1[i].size(); ++j) {
//             if (matrix1[i][j] != matrix2[i][j]) return false;
//         }
//     }
//     return true;
// }

// bool compareLinkCounts(const unordered_map<int, int>& counts1, const unordered_map<int, int>& counts2) {
//     if (counts1.size() != counts2.size()) return false;
//     for (const auto& pair : counts1) {
//         auto it = counts2.find(pair.first);
//         if (it == counts2.end() || it->second != pair.second) return false;
//     }
//     return true;
// }

// TEST_CASE("2 Web Pages Adjacency Matrix") {
//     PageRank pr("../../data/2WebPages.csv", 0.85);
//     vector<vector<double>> expectedMatrix = {{0, 1}, {0, 0}};
//     REQUIRE(compareMatrices(pr.getAdjacencyMatrix(), expectedMatrix));
// }

// TEST_CASE("4 Web Pages Link Counts") {
//     PageRank pr("../../data/4WebPages.csv", 0.85);
//     unordered_map<int, int> expectedCounts = {{0, 2}, {1, 1}, {2, 1}, {3, 1}};
//     REQUIRE(compareLinkCounts(pr.getOutlinkCounts(), expectedCounts));
// }

// TEST_CASE("10 Web Pages Adjacency Matrix and Link Counts") {
//     PageRank pr("../../data/10WebPages.csv", 0.85);
//     // Define the expected adjacency matrix and link counts for the 10 web pages
//     vector<vector<double>> expectedMatrix = {/* Fill in the expected matrix */};
//     unordered_map<int, int> expectedCounts = {/* Fill in the expected link counts */};
//     REQUIRE(compareMatrices(pr.getAdjacencyMatrix(), expectedMatrix));
//     REQUIRE(compareLinkCounts(pr.getOutlinkCounts(), expectedCounts));
// }
// TEST_CASE("Empty CSV File") {
//     REQUIRE_THROWS_AS(PageRank("empty.csv", 0.85), std::runtime_error);
// }

// TEST_CASE("Invalid CSV File Format") {
//     REQUIRE_THROWS_AS(PageRank("invalid_format.csv", 0.85), std::runtime_error); 
// }

// TEST_CASE("Matrix Multiplication") {
//     PageRank pr("webpages.csv", 0.85);
//     std::vector<double> testVector = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
//     std::vector<double> result = pr.multiplyMatrix(testVector); 
//     std::vector<double> expected = {0.1, 0.15, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.05}; 
//     REQUIRE(result == expected);
// }

// TEST_CASE("PageRank Calculation") {
//     PageRank pr("webpages.csv", 0.85);
//     pr.calculatePageRank();
//     std::vector<double> ranks = pr.getPageRanks(); 
//     REQUIRE(ranks.size() == 10);
// }

// TEST_CASE("Damping Factor Effect") {
//     PageRank pr1("webpages.csv", 0.85);
//     PageRank pr2("webpages.csv", 0.95);
//     pr1.calculatePageRank();
//     pr2.calculatePageRank();
//     REQUIRE(pr1.getPageRanks() != pr2.getPageRanks());
// }

// TEST_CASE("Adjacency Matrix Generation") {
//     PageRank pr("webpages.csv", 0.85);
//     auto adjacencyMatrix = pr.getAdjacencyMatrix(); 
//     REQUIRE(adjacencyMatrix.size() == 10);
// }