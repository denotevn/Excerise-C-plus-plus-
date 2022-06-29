/**
 * NQueens.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "NQueens.hpp"

using namespace std;

NQueens::NQueens(int nQueens)
{
    nQueens_ = nQueens;
    solnCount_ = 0;
    board_ = new int[nQueens];
    lastSoln_ = new int[nQueens];
}

// use printAllSOlns to optionally print all solution boards
void NQueens::computeSolns(bool printAllSolns)
{
    solveNQ(0,printAllSolns);
    if (!printAllSolns)
    {
        board_ = lastSoln_; // go back to the solution
        printBoard(); // only print the last solution
    }
    cout << solnCount_ << " solutions found" << endl; 
}

// use recursion and backtracking to find solutions
void NQueens::solveNQ(int row, bool printAllSolns)
{
    // all queens have been placed, so return true
    if (row >= nQueens_)
    {
        solnCount_++;
        memcpy(lastSoln_, board_, nQueens_ * sizeof(int));
        if (printAllSolns)
        {
            printBoard();
        }
        return;
    }

    // test column and try placing a queen in each row
    for (int i = 0; i < nQueens_; i++)
    {
        // check if queen can be placed on board_[i][col]
        if (isSafe(row, i))
        {
            // put the queen here
            board_[row] = i;
            // recursively call function for the next row
            solveNQ(row + 1, printAllSolns);
        }
    }
}

bool NQueens::isSafe(int row, int col)
{	
    for (int i = 0; i < row; i++)
    {
        // Check this column
        if (board_[i] == col) return false;
        
        // Check upper-left diagonal direction
        if (board_[i] == col - (row - i)) return false;
        
        // Check upper-right diagonal direction
        if (board_[row - 1 - i] == col + i + 1) return false;
    }
    
    // Queen is safe in this position
    return true;
}

void NQueens::printBoard()
{
    int row, col = 0;

    cout << endl;
    
    // display array values
    for (row = 0; row < nQueens_; row++)
    {
        cout << board_[row];
    }
    cout << endl;

    // display pretty board
    for (int dash = 0; dash < nQueens_ * 4 + 1; dash++)
    {
        cout << "-";
    }
    cout << endl;
    for (row = 0; row < nQueens_; row++)
    {
        cout << "|";
        for ( col = 0; col < nQueens_; col++) 
        {
            if (board_[row] == col)
            {
                cout << " Q |";
            }
            else
            {
                cout << "   |";
            } 
        }
        cout << endl;
        for (int dash = 0; dash < nQueens_ * 4 + 1; dash++)
        {
            cout << "-";
        }
        cout << endl;
    }
}