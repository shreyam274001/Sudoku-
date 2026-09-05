#include "Board.hpp"
#include <iostream>
#include <string>

Board :: Board() : grid {} {}

bool Board::isValidMove(int row, int col, int val)const{
    return !isInRow(row, val) && !isInCol(col, val) && !isInBox(row - row%3, col -col%3, val);
}


bool Board::isInRow(int row, int val) const{
    for(int col=0; col<SIZE; col++){
        if(grid[row][col]==val) return true;
    }
    return false;
}

bool Board::isInCol(int col,int val)const{
    for(int row=0; row<SIZE;row++){
        if(grid[row][col]==val) return true;
    }
    return false;
}

bool Board::isInBox(int startrow,int startCol, int val)const{
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            if(grid[startrow+r][startCol+c]==val)   return true;
        }
    }
    return false;
}

int Board::get(int row, int col)const{
    return grid[row][col];
}

void Board::set(int row, int col, int val){
    grid[row][col]=val;
}

const Board::Grid& Board::getGrid() const{
    return grid;
}

void Board:: printBoard(const Board &board){
    const auto& grid=board.getGrid();
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            cout<<(grid[r][c] ? to_string(grid[r][c]) : ".") <<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
}