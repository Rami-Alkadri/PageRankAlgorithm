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


