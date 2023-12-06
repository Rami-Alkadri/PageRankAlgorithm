# Academic Reference

The algorithm we are proposing to implement is the Page Rank Algorithm. ([https://dsa21.techconf.org/download/DSA2021_FULL/pdfs/DSA2021-1sP33wTCujRJmnnXDjv3mG/439100a739/439100a739.pdf](https://www.cis.upenn.edu/~mkearns/teaching/NetworkedLife/pagerank.pdf)).

To assist us in understanding this algorithm, we will use academic papers as well as educational resources from well-known institutions (https://pi.math.cornell.edu/~mec/Winter2009/RalucaRemus/Lecture3/lecture3.html). We will also use other internet resources as needed.

# Algorithm Summary

When properly implemented, the PageRank Algorithm receives a csv of links in the format of "source, target", correctly processes it into an adjacency matrix where columns are source, and rows are the target links. We will also construct a map that maps links (string) to the index they reside in within the adjacency matrix for ease of access. The purpose of our algorithm is to be able to rank the importance of web pages. We are not yet sure how we will output pageRank. This important algorithm is used frquently in search engines.

# Function I/O

## Following all reside within PageRank Class: 

## Function: matrixMultiplier
## Description: This function multiplies a matrix and a vector, and returns the product. Before doing so, it checks if the two provided matrices can mathematically be multiplied.
### Inputs: Two Matrices A and B.
- vector<vector<<std::vector<double>>>& A: The first matrix, a reference so as to not make another copy.
- vector<vector<<std::vector<double>>>& B: Vector.
### Output: The product of the two matrices if possible, a warning if not.
- vector<double>: Product vector.

## Constructor: pageRank
## Description: This constructor initializes the adjacency matrix of the pageRank class from the given csv. A[i][j] will be 1 if there is an edge going from link j to link i, and 0 otherwise. It also initializes the pageRankValues 1-d vector with temporary values. Also populates outlink count which helps with normalization of the adjancency matrix.
## Input: csvFile containing lines of the format "source, target", damping factor (typically 0.85).
## Output: None, void.


# Function: calculatePageRank
## Description: This function retriveves the normalized adjacency matrix and multiplies it repeatedly with a ranks vector. The ranks vector is updated with each iteration. After convergence is observed (or maximumIterations is reached), we break, and are left with the final ranks vector.
## Input: maxIterations-> number of times you want to multiply the normalized adjacency matrix by the 1d page rank (ranks) vector. We use a max of a 100, just to make sure that we observe convergence. Tolerance->used to check whether convergence has occured.
## Output: None, populates ranks vector (normalizes it too).

# Function: getWebsiteRank
## Input: string websiteName.
## Output: Integer, that labels the position of the website among the Dataset according to importance calculated by the PageRank.
## Description: First steps, creates a pairing of website name and normalized rank, puts it in a vector. Orders its in descrending order, and then it returns the appropriate position according to the string in question.



## Test Cases
Our test cases will measure the algorithm's ability to rank different links/codes/strings according to its relative importance using a PageRank algorithm approach. We test our aglorithm with a plethora of different datasets. Our test cases revolve around checking the success of our matrix multiplication function, PageRank constructor and PageRank calculator. Our test cases for matrix multiplication multiply vectors of different sizes (both valid and invalid) against appropriate matrices. These are tested with the use of online matrix multiplication calculators. Our PageRank Constructor test cases make sure that we store a correct and normalized adjacency matrix populated by csvs of varying sizes. Lastly our PageRank Calculator depends on the success of the constructor tests, and goes beyond that, by making sure the PageRank vector is calculated correctly. Also, within these test cases, we also test the functionality to label links/codes/strings with their respective position (regarding importance) in their datasets. Our PageRank calculator is tested using Python, the code is a little different, and there is also the manual aspect of writing down the adjacency matrix from sight.

# Data Description

Our data varies in size. It features csvs written in the format of "source, destination". Source is where a link of originates, and destination is that link points to. The 2,4,10 WebPages csvs were written manually, while the Huge and Large Amount Web Pages were found online. Instead of links, we used airport codes (for plane travel).