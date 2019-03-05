#include <algorithm>
#include "nqueens.h"

//helper functions
static bool attack_row(std::vector<std::vector<bool>> &board, int i, int j);
static bool attack_col(std::vector<std::vector<bool>> &board, int i, int j);
static bool attack_diagonal(std::vector<std::vector<bool>> &board, int i, int j);

//Constructor
N_Queens::N_Queens(int n) : board(n, std::vector<bool>(n, false))
{
    this->n = n;
    this->row = 0;
    this->col = 0;
    this->count = 0;
}


N_Queens::N_Queens(const N_Queens &other) : N_Queens(other.n)
{
    //copy the board from the other
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        board[i][j] = other.board[i][j];
      }
    }

    this->count = other.count;
}

//returns true if this candidate is invalid or otherwise unworkable.
bool 
N_Queens::reject()
{
    //check each queen
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]) {
                if(attack_row(board, i, j) or
                   attack_col(board, i, j) or
                   attack_diagonal(board, i, j)) {
                   return true;
                }
            }
        }
    }

    return false;
}
    
//returns true if this candidate is a solved puzzle
bool 
N_Queens::solved()
{
    //if we don't reject and we have n queens, we are done!
    return not reject() and count == n;
}
    
//returns the next extension of this candidate solution 
//(nullptr if there is none)
Candidate *
N_Queens::next()
{
   N_Queens *next_step = new N_Queens(*this); 

   //look for the next blank slot
   for(; row<n; row++) {
       for(; col<n; col++) {
           //place a queen here, if it is available
           if(board[row][col] == false) {
               next_step->board[row][col] = true;
               next_step->count++;
               col++;  //get ready for the next column
               return next_step; 
           }
       }

       //reset the column
       col = 0;
   }

   //no space available
   return nullptr;
}


static bool 
attack_row(std::vector<std::vector<bool>> &board, int i, int j)
{
    for(int col = 0; col < board.size(); col++) {
        //skip ourself
        if(col == j) continue;

        //if we find another queen, return true
        if(board[i][col]) {
            return true;
        }
    }

    //all clear!
    return false;
}


static bool 
attack_col(std::vector<std::vector<bool>> &board, int i, int j)
{
    for(int row = 0; row < board.size(); row++) {
        //skip ourself
        if(row == i) continue;

        //if we find another queen, return true
        if(board[row][j]) {
            return true;
        }
    }

    //all clear!
    return false;
}


static bool 
attack_diagonal(std::vector<std::vector<bool>> &board, int i, int j)
{
    //check the four weays we could go
    for(int row=i-1; row>=0; row--) {
        //j-1 side
        for(int col=j-1; col>=0; col--) {
            if(board[row][col]) return true;
        }
        //j+1 side
        for(int col=j+1; col<board.size(); col++) {
            if(board[row][col]) return true;
        }
    }
    for(int row=i+1; row<board.size(); row++) {
        //j-1 side
        for(int col=j-1; col>=0; col--) {
            if(board[row][col]) return true;
        }
        //j+1 side
        for(int col=j+1; col<board.size(); col++) {
            if(board[row][col]) return true;
        }
    }

    //all clear
    return false;
}
