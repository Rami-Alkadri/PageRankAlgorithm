CXX = g++  # or clang++ if you prefer
CXXFLAGS = -std=c++17 -Wall -Icode/src 

# Source files
SRCS = code/src/PageRank.cpp code/tests/tests.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = tests

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean