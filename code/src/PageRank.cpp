#include "PageRank.h"
#include <numeric>
#include <cmath> 
#include <stdexcept>

using namespace std;

void PageRank::buildAdjacencyMatrix(const string& filename) {
    ifstream file(filename);
    string line, source, destination;
    int pageIndex = 0;

    while (std::getline(file, line)) {
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

std::vector<double> PageRank::multiplyMatrixByVector(const std::vector<double>& vec) {
    if (adjacencymatrix.empty() || adjacencymatrix[0].size() != vec.size()) {
        throw std::invalid_argument("Matrix and vector dimensions do not match.");
    }

    std::vector<double> result(adjacencymatrix.size(), 0.0);

    for (size_t i = 0; i < adjacencymatrix.size(); ++i) {
        for (size_t j = 0; j < vec.size(); ++j) {
            result[i] += adjacencymatrix[i][j] * vec[j];
        }
    }
    return result;
}

void PageRank::calculatePageRank(int maxIterations, double tolerance) {
    std::vector<double> newRanks(ranks.size(), 1.0 / ranks.size());

    for (int iter = 0; iter < maxIterations; ++iter) {
        std::fill(newRanks.begin(), newRanks.end(), (1.0 - dampingfactor) / ranks_.size());

        for (size_t i = 0; i < adjacencymatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencymatrix[i].size(); ++j) {
                if (adjacencymatrix[i][j] != 0) {
                    newRanks[i] += dampingfactor * adjacencymatrix[i][j] * ranks_[j];
                }
            }
        }
        double delta = 0.0;
        for (sizet i = 0; i < ranks.size(); ++i) {
            delta += std::fabs(newRanks[i] - ranks[i]);
        }

        ranks = newRanks;

        if (delta < tolerance) {
            break;
        }
    }
}


