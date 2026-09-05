// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

class Board {
public:
    static constexpr int SIZE = 9;
    using Grid = std::array<std::array<int, SIZE>, SIZE>;

    Board();
    
    bool isValidMove(int row, int col, int val) const;
    bool isInRow(int row, int val) const;
    bool isInCol(int col, int val) const;
    bool isInBox(int startRow, int startCol, int val) const;
    
    int get(int row, int col) const;
    void set(int row, int col, int val);
    
    const Grid& getGrid() const;
    void printBoard(const Board& board);
    
private:
    Grid grid{};
};

#endif
