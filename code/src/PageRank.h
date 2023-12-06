#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<double> multiplyMatrixByVector(const vector<vector<double>>& adjacency_matrix, const vector<double>& vec);

class PageRank {
    public:
        PageRank(const string& csvfile, double dfact);
        unordered_map<int, int> getOutlinkCounts();
        vector<vector<double>> getAdjacencyMatrix();
        void calculatePageRank(int maxIterations, double tolerance);
        const vector<double>& getAllRanks() const;
        int getWebsiteIndex(std::string website);
        int getWebsiteRank(const string& websiteName) const;
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