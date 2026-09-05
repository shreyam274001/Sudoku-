#include "Generator.hpp"
#include "Board.hpp"
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

using namespace std;

int Generator::getEmptyCells(Difficulty level){
    switch (level) {
        case Difficulty::Easy : return 30 + rand()%6;
        case Difficulty::Medium : return 40+rand()%6;
        case Difficulty::Hard : return 50+ rand()%6;
    }
}

bool Generator:: fill(Board& board, int row, int col){
    if(row==9)  return true;
    int nexRow= (col==8) ? row+1 :row;
    int nexCol=(col+1)%9;

    vector<int> nums(9);
    iota(nums.begin(), nums.end(), 1);
    shuffle(nums.begin(), nums.end(), mt19937{random_device{}()});

    for(int val : nums){
        if(board.isValidMove(row, col, val)){
            board.set(row, col, val);
            if(fill(board, nexRow, nexCol)) return true;
            board.set(row, col, 0);
        }
    }
    return false;
}

Board Generator::generate(Difficulty level){
    Board board;
    fill(board, 0, 0);

    int emptyCells= getEmptyCells(level);
    
    vector<pair<int, int>> cells;
    for(int r=0;r<9;r++){
        for (int c=0;c<9;c++){
            cells.emplace_back(r,c);
        }
    }

    shuffle(cells.begin(), cells.end(), mt19937(random_device{}()));
    for(int i=0; i<emptyCells;++i){
        board.set(cells[i].first,cells[i].second, 0);
    }
    return board;
}