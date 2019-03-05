#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "termmanip.h"
#include "sudoku.h"

using namespace std;

static void printSeparator();
static bool isValid(vector<int> &puzzle);
static bool checkRow(vector<int> &puzzle, int y);
static bool checkCol(vector<int> &puzzle, int x);
static bool checkSquare(vector<int> &puzzle, int grid);


Sudoku::Sudoku(std::vector<int> &puzzle, bool _animate) : puzzle(puzzle), changeable(81)
{
    //mark all the degrees of freedom
    for(int i=0; i<81; i++) {
        changeable[i] = puzzle[i] == 0;
    }
    
    //initialize whether we are animating or not
    this->_animate = _animate;
} 


Sudoku::~Sudoku()
{
    //delete the next step (if there is one)
    if(nextStep() != nullptr) {
        delete (Sudoku*) nextStep();
    }
}


//returns true if this candidate is invalid or otherwise unworkable.
bool 
Sudoku::reject()
{
    //it really shouldn't be possible to get here with an invalid
    //puzzle, but better safe than sorry!
    return not isValid(puzzle);
}
    

//returns true if this candidate is a solved puzzle
bool 
Sudoku::solved()
{
    //if it is invalid, it isn't solved
    if(reject()) {
        return false;
    }
    
    //if there is any freedom left in the puzzle, it is not solvable!
    for(int i=0; i<81; i++) {
        if(changeable[i]) {
            return false;
        }
    }
    
    //valid and no degrees of freedom?  HUZZAH!
    return true;
}
    

//returns the next extension of this candidate solution 
//(nullptr if there is none)
Candidate *
Sudoku::next() 
{
    //destroy our last next (if there is one)
    if(nextStep() != nullptr) {
        delete (Sudoku*) nextStep();
    }

    //increment the first changeable field
    for(int i=0; i<81; i++) {
        if(changeable[i]) {
            do {
                puzzle[i]++;
            
                //if there are no more positions for this one, return null
                if(puzzle[i] > 9) {
                    return nullptr;
                }
            } while(not isValid(puzzle));
            
            //we found a valid puzzle!
            if(animate()) {
                display();
                usleep(50000);
            }
            return new Sudoku(puzzle, _animate);
        }
    }
    
    //if we reach here, there is nothing else to do but return null
    return nullptr;
}



void 
Sudoku::display()
{
    cout << cursorPosition(1,1);

    //print the grid
    for(int i=0; i<81; i++) {
        if(i%9==0) {
            if(i!=0) {
                //the first row needs no termination
                cout << " |"  << endl;
            }
        
            if((i/9)%3==0) {
                printSeparator();
            }
        }
        
        //handle the printing of column separators
        if((i%9)%3 == 0) {
            cout << " |";
        }
        
        //print the number or space
        if(puzzle[i] == 0) {
            cout << setw(2) << ' ';
        } else {
            cout << setw(2) << puzzle[i];
        }
    }
    cout << " |" << endl;
    printSeparator();
}



//get/set the animate flag
void 
Sudoku::animate(bool _animate)
{
    this->_animate = _animate;
}


bool 
Sudoku::animate()
{
    return _animate;
}


static void 
printSeparator()
{
    cout << " +" 
         << setfill('-')
         << setw(8) << '+' << setw(8) << '+' << setw(8) << '+'
         << setfill(' ') << endl;
}



static bool 
isValid(vector<int> &puzzle)
{
    //check all the things
    for(int i=0; i<9; i++) {
        if(not checkRow(puzzle, i)) {
            return false;
        }
        
        if(not checkCol(puzzle, i)) {
            return false;
        }
        
        if(not checkSquare(puzzle, i)) {
            return false;
        }
    }
    
    //we passed all the checks!  No rejection for us!
    return true;
}


static bool 
checkRow(vector<int> &puzzle, int y)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = y * 9;
    
    for(int col=0; col<9; col++, i++) {
        if(puzzle[i]!=0) {
            if(present[puzzle[i]-1]) {
                //There can be only one!
                return false;
            } else {
                //I am the one!
                present[puzzle[i]-1] = true;
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}


static bool 
checkCol(vector<int> &puzzle, int x)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = x;
    
    for(int row=0; row<9; row++, i+=9) {
        if(puzzle[i]!=0) {
            if(present[puzzle[i]-1]) {
                //There can be only one!
                return false;
            } else {
                //I am the one!
                present[puzzle[i]-1] = true;
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}


static bool 
checkSquare(vector<int> &puzzle, int grid)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = 27*(grid/3) + 3*(grid%3);
    
    for(int row=0; row<3; row++, i+=6) {
        for(int col=0; col<3; col++, i++){
            if(puzzle[i]!=0) {
                if(present[puzzle[i]-1]) {
                    //There can be only one!
                    return false;
                } else {
                    //I am the one!
                    present[puzzle[i]-1] = true;
                }
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}
