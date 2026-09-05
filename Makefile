CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = sudoku
SOURCES = main.cpp Board.cpp Generator.cpp Solver.cpp
HEADERS = Board.hpp Generator.hpp Solver.hpp

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
