#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class PageRank {
    public:
        PageRank(const string& csvfile, double dfact);
        unordered_map<int, int> getOutlinkCounts();
        vector<vector<double>> getAdjacencyMatrix();
        vector<double> multiplyMatrixByVector(const std::vector<double>& vec);
        void calculatePageRank(int maxIterations, double tolerance);
        double getWebsiteRank(const std::string& websiteName) const;
        const vector<double>& getAllRanks() const;
    private:
        double damping_factor_;
        vector<vector<double>> adjacency_matrix_;
        unordered_map<string, int> pageIndices;
        vector<double> ranks_;
        unordered_map<int, int> outlink_count_;
        void buildAdjacencyMatrix(const string& filename);
        void normalizeRanks();
        bool isConverged(const std::vector<double>& oldRanks, double tolerance) const;
        void resetRanks(); 
};