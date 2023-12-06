#include "PageRank.h"
#include <numeric>
#include <cmath> 
#include <stdexcept>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<double> multiplyMatrixByVector(const vector<vector<double>>& adjacency_matrix, const vector<double>& vec) {
    if (adjacency_matrix.empty() || adjacency_matrix[0].size() != vec.size()) {
        throw invalid_argument("Matrix and vector dimensions do not match.");
    }

    vector<double> result(adjacency_matrix.size(), 0.0);

    for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
        for (size_t j = 0; j < vec.size(); ++j) {
            result[i] += adjacency_matrix[i][j] * vec[j];
        }
    }
    return result;
}

void PageRank::buildAdjacencyMatrix(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file: " + filename);
    }

    string line, source, destination;

    // Skip the header line
    getline(file, line);

    // First pass: identify all unique pages
    set<string> pages;
    while (getline(file, line)) {
        istringstream iss(line);
        if (getline(iss, source, ',') && getline(iss, destination)) {
            pages.insert(source);
            pages.insert(destination);
        }
    }

    // Initialize page indices and adjacency matrix
    int pageIndex = 0;
    for (const auto& page : pages) {
        pageIndices[page] = pageIndex++;
    }
    adjacency_matrix_ = vector<vector<double>>(pageIndex, vector<double>(pageIndex, 0.0));

    // Reset file read position to beginning
    file.clear();
    file.seekg(0);
    getline(file, line); // Skip header again

    // Second pass: build the adjacency matrix
    while (getline(file, line)) {
        istringstream iss(line);
        if (getline(iss, source, ',') && getline(iss, destination)) {
            int sourceIndex = pageIndices[source];
            int destinationIndex = pageIndices[destination];
            adjacency_matrix_[destinationIndex][sourceIndex] = 1.0;
            outlink_count_[sourceIndex]++;
        }
    }

    // Normalize the matrix
    for (auto &row : adjacency_matrix_) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (outlink_count_[i] > 0) {
                row[i] /= outlink_count_[i];
            }
        }
    }
}

PageRank::PageRank(const string& csvfile, double dfact) : damping_factor_(dfact) {
    buildAdjacencyMatrix(csvfile);
    ranks_.assign(adjacency_matrix_.size(), 1.0 / adjacency_matrix_.size());
}

vector<vector<double>>  PageRank::getAdjacencyMatrix() {
    return adjacency_matrix_;
}

unordered_map<int, int> PageRank::getOutlinkCounts() {
    return outlink_count_;
}

void PageRank::calculatePageRank(int maxIterations, double tolerance) { // to test
    vector<double> newRanks(ranks_.size(), 1.0 / ranks_.size());

    for (int iter = 0; iter < maxIterations; ++iter) {
        fill(newRanks.begin(), newRanks.end(), (1.0 - damping_factor_) / ranks_.size());

        vector<double> rankContributions = multiplyMatrixByVector(adjacency_matrix_, ranks_);

        for (size_t i = 0; i < newRanks.size(); ++i) {
            newRanks[i] += damping_factor_ * rankContributions[i];
        }
        if (isConverged(newRanks, tolerance)) {
            break;
        }
        ranks_ = newRanks;
    }

    normalizeRanks();
}

const std::vector<double>& PageRank::getAllRanks() const {
    return ranks_;
}

void PageRank::normalizeRanks() {
    double sum = accumulate(ranks_.begin(), ranks_.end(), 0.0);
    for (auto& rank : ranks_) {
        rank /= sum;
    }
}

bool PageRank::isConverged(const vector<double>& oldRanks, double tolerance) const {
    double delta = 0.0;
    for (size_t i = 0; i < ranks_.size(); ++i) {
        delta += fabs(ranks_[i] - oldRanks[i]);
    }
    return delta < tolerance;
}

void PageRank::resetRanks() {
    fill(ranks_.begin(), ranks_.end(), 1.0 / ranks_.size());
}

int PageRank::getWebsiteRank(const string& websiteName) const {
    // Create a vector of pairs (website name, rank)
    vector<pair<string, double>> websiteRanks;
    for (const auto& pair : pageIndices) {
        websiteRanks.emplace_back(pair.first, ranks_[pair.second]);
    }

    // Sort the vector in descending order of rank
    sort(websiteRanks.begin(), websiteRanks.end(), 
         [](const pair<string, double>& a, const pair<string, double>& b) {
             return a.second > b.second;
         });

    // Find the rank position of the specified website
    for (int i = 0; i < websiteRanks.size(); ++i) {
        if (websiteRanks[i].first == websiteName) {
            return i + 1; // Rank position (1-based index)
        }
    }

    throw invalid_argument("Website name not found in PageRank data.");
}