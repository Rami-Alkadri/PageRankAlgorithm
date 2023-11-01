# alkadri2_aqneibi2
CS 225 Extra Credit Project for Fall Semester 2023

# Academic Reference

The algorithm we are proposing to implement is the improved Sim Hash Algorithm (https://dsa21.techconf.org/download/DSA2021_FULL/pdfs/DSA2021-1sP33wTCujRJmnnXDjv3mG/439100a739/439100a739.pdf).

To assist us in understanding this algorithm, we will also watch helpful videos demonstrating examples of this algorithm in action, including the video ( https://www.youtube.com/watch?v=gnraT4N43qo ). We will also use other internet resources as needed.

# Algorithm Summary

When properly implemented, the SimHash Algorithm can determine the level of similarity between distinct documents. By analyzing and comparing the unique fingerprints generated for each document, we can distinguish between exact copies, partial copies, and entirely different texts. The algorithm starts by tokenizing the text, assessing the significance of each token, and then producing a compact hash representation. Only after this step can we compare the hash of the base document to the hashes of other documents. Subsequently, we generate a similarity score.

# Function I/O

## Function: convertTXTtoDocuments
Input: A TXT file where each row represents a document.
Output: A vector of strings, where each string represents a document.

## Function: computeSimHash
Input: A string which represents a document.
Output: A SimHash fingerprint of the document.

## Function Name: measureSimilarity
Input: Two SimHash fingerprints of 2 documents.
Output: A similarity score between the two fingerprints (ranging between 0 - 100 %)

## Test Cases

Our test cases will measure the algorithm's ability to test different similarity scores between 2 documents. There will be a test case with identical documents, one with 90% similar documents, one with 50% similar documents, and one with <10% similar documents. Additionally, our test cases will test the algorithm's ability to compare multiple documents at once, where the input will have 10 documents with the first document listed being the baseline comparator, and the other documents will be compared to the baseline.
