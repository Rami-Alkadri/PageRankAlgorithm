# Academic Reference

The algorithm we are proposing to implement is the Page Rank Algorithm. ([https://dsa21.techconf.org/download/DSA2021_FULL/pdfs/DSA2021-1sP33wTCujRJmnnXDjv3mG/439100a739/439100a739.pdf](https://www.cis.upenn.edu/~mkearns/teaching/NetworkedLife/pagerank.pdf)).

To assist us in understanding this algorithm, we will use academic papers as well as educational resources from well-known institutions (https://pi.math.cornell.edu/~mec/Winter2009/RalucaRemus/Lecture3/lecture3.html). We will also use other internet resources as needed.

# Algorithm Summary

When properly implemented, the PageRank Algorithm receives a csv of links in the format of "source, target", correctly processes it into an adjacency matrix where columns are source, and rows are the target links. We will also construct a map that maps links (string) to the index they reside in within the adjacency matrix for ease of access. The purpose of our algorithm is to be able to rank the importance of web pages. We are not yet sure how we will output pageRank. This important algorithm is used frquently in search engines.

# Function I/O

## Following all reside within PageRank Class: 

## Function: matrixMultiplier
## Description: This function multiplies two matrices, and returns the product. Before doing so, it checks if the two provided matrices can mathematically be multiplied.
### Inputs: Two Matrices A and B.
- std::vector<std::vector<int>>& A: The first matrix, a reference so as to not make another copy.
- std::vector<std::vector<int>>& B: The second matrix.
### Output: The product of the two matrices if possible, a warning if not.
- std::vector<std::vector<int>>: Product matrix.

## Constructor: pageRank
## Description: This constructor initializes the adjacency matrix of the pageRank class from the given csv. A[i][j] will be 1 if there is an edge going from link i to link j, and 0 otherwise. It also initializes the pageRankValues 1-d vector with temporary values. 
## Input: csvFile containing lines of the format "source, target".
## Output: None.


## Function: 







## Test Cases
Our test cases will measure the algorithm's ability to test different similarity scores between 2 documents. There will be a test case with identical documents, one with 90% similar documents, one with 50% similar documents, and one with <10% similar documents. Additionally, our test cases will test the algorithm's ability to compare multiple documents at once, where the input will have 10 documents with the first document listed being the baseline comparator, and the other documents will be compared to the baseline.

# Data Description

Our data varies in size. It features csvs written in the format of "source, destination". Source is where a link of originates, and destination is that link points to. The 2,4,10 WebPages csvs were written manually, while the Huge and Large Amount Web Pages were found online. Instead of links, we used airport codes (for plane travel).