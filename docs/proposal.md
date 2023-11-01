# Academic Reference

The algorithm we are proposing to implement is the improved Sim Hash Algorithm (https://dsa21.techconf.org/download/DSA2021_FULL/pdfs/DSA2021-1sP33wTCujRJmnnXDjv3mG/439100a739/439100a739.pdf).

To assist us in understanding this algorithm, we will also watch helpful videos demonstrating examples of this algorithm in action, including the video ( https://www.youtube.com/watch?v=gnraT4N43qo ). We will also use other internet resources as needed.

# Algorithm Summary

When properly implemented, the SimHash Algorithm can determine the level of similarity between distinct documents. By analyzing and comparing the unique fingerprints generated for each document, we can distinguish between exact copies, partial copies, and entirely different texts. The algorithm starts by tokenizing the text, assessing the significance of each token, and then producing a compact hash representation. Only after this step can we compare the hash of the base document to the hashes of other documents. Subsequently, we generate a similarity score.

# Function I/O

## Function: convertTXTtoDocuments
## Description: This function will convert a TXT file into a vector of strings, where each string represents a document.
### Input: A TXT file where each row represents a document.
 - infile (std::string): The absolute path to the TXT file where each row represents a document.
### Output: A vector of strings, where each string represents a document.
 - std::vector<std::string>: A vector of strings, where each string represents a document.
## Function: computeSimHash
## Description: This function will compute the SimHash fingerprint for a given document.
### Input: A string which represents a document.
 - document (std::string): A string which represents a document.
### Output: A SimHash fingerprint of the document.
 - std::bitset<32>: A SimHash fingerprint of the document.

## Function Name: measureSimilarity
## Description: This function will measure the similarity between two SimHash fingerprints.
### Input: Two SimHash fingerprints of 2 documents.
 - fingerprint1 (std::bitset<32>): SimHash fingerprint of the first document.
 - fingerprint2 (std::bitset<32>): SimHash fingerprint of the second document.
### Output: A similarity score between the two fingerprints (ranging between 0 - 100 %)
 - double: A similarity score between the two fingerprints, ranging between 0 to 100%

## Test Cases
Our test cases will measure the algorithm's ability to test different similarity scores between 2 documents. There will be a test case with identical documents, one with 90% similar documents, one with 50% similar documents, and one with <10% similar documents. Additionally, our test cases will test the algorithm's ability to compare multiple documents at once, where the input will have 10 documents with the first document listed being the baseline comparator, and the other documents will be compared to the baseline.