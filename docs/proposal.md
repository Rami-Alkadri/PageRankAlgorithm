# Academic Reference

The algorithm we are proposing to implement is the Page Rank Algorithm. ([https://dsa21.techconf.org/download/DSA2021_FULL/pdfs/DSA2021-1sP33wTCujRJmnnXDjv3mG/439100a739/439100a739.pdf](https://www.cis.upenn.edu/~mkearns/teaching/NetworkedLife/pagerank.pdf)).

To assist us in understanding this algorithm, we will use academic papers as well as educational resources from well-known institutions (https://pi.math.cornell.edu/~mec/Winter2009/RalucaRemus/Lecture3/lecture3.html). We will also use other internet resources as needed.

# Algorithm Summary

When properly implemented, the SimHash Algorithm can determine the level of similarity between distinct documents. By analyzing and comparing the unique fingerprints generated for each document, we can distinguish between exact copies, partial copies, and entirely different texts. The algorithm starts by tokenizing the text, assessing the significance of each token, and then producing a compact hash representation. Only after this step can we compare the hash of the base document to the hashes of other documents. Subsequently, we generate a similarity score.

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

## 






## Test Cases
Our test cases will measure the algorithm's ability to test different similarity scores between 2 documents. There will be a test case with identical documents, one with 90% similar documents, one with 50% similar documents, and one with <10% similar documents. Additionally, our test cases will test the algorithm's ability to compare multiple documents at once, where the input will have 10 documents with the first document listed being the baseline comparator, and the other documents will be compared to the baseline.

# Data Description

The Short.txt, Short-Medium.txt, and Medium.txt files were manually written. Each of these txt files consists of the base comparator, i.e., the primary document, and other documents that will be compared against this base. The comparators, which will be measured against the base, vary in similarity to the base comparator. They range from being exactly identical, to very similar, somewhat similar, mostly different, and entirely distinct. The lengths of these text files correspond to their titles.

The Long.txt file was sourced directly from two distinct articles discussing the same game—the Bears vs. Chargers match on October 29. The first article views the game from the Bears' perspective: (https://www.chicagobears.com/news/rapid-recap-bears-fall-to-chargers-in-los-angeles-2023-week-8 ),  
while the second offers insights from the Chargers' viewpoint: (https://www.chargers.com/news/chargers-bears-grades-nfl-herbert-ekeler).

Lastly, the Really-Long.txt file comprises two randomly generated text segments. We anticipate minimal similarity between them.
