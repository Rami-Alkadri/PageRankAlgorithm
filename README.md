# alkadri2_aqneibi2
CS 225 Extra Credit Project for Fall Semester 2023

# Github Organization
## Code
Source code: Location of the PageRank.h, PageRank.cpp and main.cpp files is found at ('/code/src/')
Test code: Location of tests.cpp is found at ('/code/tests')

## Data
Datasets: Location of datasets we used is found at ('/data')

## Deliverables
Documents: Our proposal and written final report can be found at ('/docs')
Video: Our final video can be found at ('/docs')

# Running Instructions
## To run our tests (tests.cpp): 
1. Enter the root directory of the project.
2. Run 'make' in the terminal.
3. Run the executable code in the terminal with './tests'. If you would like to run a specific test case put the name of the test case in quotes after ./tests. Example(./tests "test 1").
4. To create a new executable, run 'make clean' then repeat steps 1 - 3.

## To run main (main.cpp): 
1. Enter the root directory of the project.
2. Run 'make' in the terminal.
3. Run the executable code in the terminal with '
4. To create a new executable, run 'make clean' then repeat steps 1 - 3.

## Input Data
The input data must be a CSV file with the following format:
source,data
pageA,pageB

To construct a PageRank, simply input the name of the CSV file as a string in the constructor. 

## Output Location
There is no output location for our methods. To see the output of methods like 'getWebsiteRank' and 'getAllRanks', use cout statements.