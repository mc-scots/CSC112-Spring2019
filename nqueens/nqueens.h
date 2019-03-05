// Solve the n-queens problem using Object Oriented Backtracking
#ifndef NQUEENS_H
#define NQUEENS_H
#include <vector>
#include "backtrack.h"

class N_Queens : public Candidate
{
public:
    //Constructor
    N_Queens(int n);
    N_Queens(const N_Queens &other);

    //returns true if this candidate is invalid or otherwise unworkable.
    virtual bool reject();
    
    //returns true if this candidate is a solved puzzle
    virtual bool solved();
    
    //returns the next extension of this candidate solution 
    //(nullptr if there is none)
    virtual Candidate *next();

private:   

    //the board (true if a queen is on a square) 
    std::vector<std::vector<bool>> board;
    int count;  //number of already placed queens
    int row;    //the last row we tried
    int col;    //the last column we tried
    int n;      //our n
};

#endif
