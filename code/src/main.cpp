#include <iostream>
#include <vector>
#include <chrono>
#include "PageRank.h" 

int main() {
    std::vector<std::string> datasets = {"./data/pages.csv",
                                        "./data/10WebPages.csv",
                                        "./data/MediumAmountWebPages.csv", 
                                         "./data/LargeAmountWebPages.csv", 
                                         "./data/ExtraLargeAmountWebPages.csv"};
    double damping_factor = 0.85;
    int maxIterations = 100;
    double tolerance = 0.001;

    for (const auto& dataset : datasets) {
        PageRank PR(dataset, damping_factor);

        auto start = std::chrono::high_resolution_clock::now();
        PR.calculatePageRank(maxIterations, tolerance);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::vector<double> final_ranks = PR.getAllRanks();
        std::cout << "Dataset: " << dataset << " - Size: " << final_ranks.size() 
                  << " - Time taken: " << elapsed.count() << " seconds" << std::endl;
    }

    return 0;
}