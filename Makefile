CXX = g++  # or clang++ if you prefer
CXXFLAGS = -std=c++17 -Wall -Icode/src 

# Source files
SRCS = code/src/PageRank.cpp code/tests/tests.cpp
MAIN_SRC = code/src/main.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

# Executable names
TEST_EXEC = tests
MAIN_EXEC = main

all: $(TEST_EXEC) $(MAIN_EXEC)

$(TEST_EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_EXEC): $(OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ) $(filter-out code/tests/tests.o, $(OBJS))

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN_OBJ) $(TEST_EXEC) $(MAIN_EXEC)

.PHONY: all clean