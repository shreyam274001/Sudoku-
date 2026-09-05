#include "Board.hpp"
#include "Generator.hpp"
#include "Solver.hpp"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n╔════════════════════════════════════╗\n";
    cout << "║      SUDOKU GAME & SOLVER         ║\n";
    cout << "╚════════════════════════════════════╝\n";
    cout << "1. Generate New Puzzle\n";
    cout << "2. Solve Current Puzzle\n";
    cout << "3. Display Board\n";
    cout << "4. Exit\n";
    cout << "────────────────────────────────────\n";
    cout << "Choose option: ";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    Board board;
    Generator generator;
    Solver solver;
    bool running = true;
    
    cout << "🎯 Welcome to Sudoku Game & Solver!\n";
    cout << "Generating initial puzzle...\n";
    board = generator.generate(Generator::Difficulty::Medium);
    
    while (running) {
        board.printBoard(board);
        displayMenu();
        
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nSelect Difficulty:\n";
                cout << "1. Easy\n";
                cout << "2. Medium\n";
                cout << "3. Hard\n";
                cout << "Choice: ";
                
                int diff;
                cin >> diff;
                
                Generator::Difficulty level;
                switch (diff) {
                    case 1: level = Generator::Difficulty::Easy; break;
                    case 2: level = Generator::Difficulty::Medium; break;
                    case 3: level = Generator::Difficulty::Hard; break;
                    default: 
                        cout << "Invalid choice. Using Medium.\n";
                        level = Generator::Difficulty::Medium;
                }
                
                board = generator.generate(level);
                cout << "✅ New puzzle generated!\n";
                break;
            }
            
            case 2: {
                cout << "\nSolving puzzle...\n";
                Board solvedBoard = board;
                if (solver.solve(solvedBoard)) {
                    cout << "✅ Puzzle solved!\n";
                    cout << "\nSolved Board:\n";
                    solvedBoard.printBoard(solvedBoard);
                } else {
                    cout << "❌ No solution exists for this puzzle.\n";
                }
                break;
            }
            
            case 3:
                board.printBoard(board);
                break;
                
            case 4:
                cout << "👋 Goodbye!\n";
                running = false;
                break;
                
            default:
                cout << "❌ Invalid option. Try again.\n";
        }
        
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            clearScreen();
        }
    }
    
    return 0;
}
