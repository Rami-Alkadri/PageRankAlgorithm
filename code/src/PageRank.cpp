#include "PageRank.h"
#include <numeric>
#include <cmath> 
#include <stdexcept>

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
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    string line, source, destination;
    int pageIndex = 0;

    while (getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> source >> destination)) {
            continue; 
        }   

        if (pageIndices.find(source) == pageIndices.end()) {
            pageIndices[source] = pageIndex;
            pageIndex++;
            //Do we add vector at end once size is known?
            adjacency_matrix_.push_back(std::vector<double>(pageIndex, 0.0));
        }

        if (pageIndices.find(destination) == pageIndices.end()) {
            pageIndices[destination] = pageIndex;
            pageIndex++;
            for (auto &row : adjacency_matrix_) {
                row.push_back(0.0);
            }
            adjacency_matrix_.push_back(std::vector<double>(pageIndex, 0.0));
        }

        int sourceIndex = pageIndices[source];
        int destinationIndex = pageIndices[destination];

        adjacency_matrix_[sourceIndex][destinationIndex] = 1.0;
        outlink_count_[sourceIndex]++;
    }

    for (auto &row : adjacency_matrix_) {
        int index = &row - &adjacency_matrix_[0];
        if (outlink_count_[index] > 0) {
            for (auto &val : row) {
                val /= outlink_count_[index];
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

        for (size_t i = 0; i < adjacency_matrix_.size(); ++i) {
            for (size_t j = 0; j < adjacency_matrix_[i].size(); ++j) {
                if (adjacency_matrix_[i][j] != 0) {
                    newRanks[i] += damping_factor_ * adjacency_matrix_[i][j] * ranks_[j];
                }
            }
        }
        // double delta = 0.0;
        // for (size_t i = 0; i < ranks_.size(); ++i) {
        //     delta += fabs(newRanks[i] - ranks_[i]);
        // }

        if (isConverged(newRanks, tolerance)) {
            break;
        }

        ranks_ = newRanks;
    }
    normalizeRanks();
}

double PageRank::getWebsiteRank(const string& websiteName) const { // to test
    auto it = pageIndices.find(websiteName);
    if (it != pageIndices.end()) {
        return ranks_[it->second];
    } else {
        throw invalid_argument("Website name not found in PageRank data.");
    }
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