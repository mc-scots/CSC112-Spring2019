#ifndef SUDOKU_H
#define SUDOKU_H
#include <vector>
#include "backtrack.h"

class Sudoku : public Candidate
{
public:
    Sudoku(std::vector<int> &puzzle, bool _animate = false);
    ~Sudoku();
    
    //returns true if this candidate is invalid or otherwise unworkable.
    virtual bool reject();
    
    //returns true if this candidate is a solved puzzle
    virtual bool solved();
    
    //returns the next extension of this candidate solution 
    //(nullptr if there is none)
    virtual Candidate *next();
    
    //display the puzzle
    virtual void display();
    
    
    //get/set the animate flag
    virtual void animate(bool _animate);
    virtual bool animate();
private:
    std::vector<int> puzzle;
    std::vector<bool> changeable;
    bool _animate;
};
#endif
