#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "Board.hpp"

class Generator {
public:
    enum class Difficulty { Easy, Medium, Hard };
    
    Board generate(Difficulty level = Difficulty::Medium);
    
private:
    bool fill(Board& board, int row, int col);
    int getEmptyCells(Difficulty level);
};

#endif
