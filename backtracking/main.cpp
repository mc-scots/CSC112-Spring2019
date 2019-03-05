#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "sudoku.h"
#include "termmanip.h"

using namespace std;

Sudoku *loadPuzzle(int level, int num);

int main()
{
    Sudoku *s;
    Sudoku *ptr;
    int level;
    int num;
    char animate;
    
    //get the puzzle
    cout << "Level (1-5)? ";
    cin >> level;
    cout << "Puzzle (1-10000)? ";
    cin >> num;
    s = loadPuzzle(level, num);
    
    //inquire about animation
    cout << "Animate (y/n)? ";
    cin >> animate;
    cout << (animate =='y') << endl;
    s->animate(animate=='y');
    
    
    //display the puzzle
    cout << clearScreen;
    s->display();
    cin.ignore(1024, '\n');
    cout << "Press Enter to Solve";
    cin.get();

    //solve the puzzle
    cout << clearScreen << cursorOff;
    cout.flush();
    s->backtrack();
    cout << cursorOn;
    cout.flush();
    
    
    //find the solution and print it
    for(ptr = s; ptr->nextStep(); ptr = (Sudoku*)ptr->nextStep());
    ptr->display();
    
    delete s;
    return 0;
}


Sudoku *
loadPuzzle(int level, int num)
{
    vector<int> v(81);
    ostringstream os;
    ifstream file;
    

    //build the file name and open the file
    os << "puzzles/" << level << ".txt";
    file.open(os.str());

    //skip down to the specified puzzles
    level--;
    while(--num) {
        file.ignore(82, '\n');
    }
    
    //read the puzzle in
    for(int i=0; i<81; i++) {
        v[i] = file.get() - '0';
    }
    file.close();
    
    return new Sudoku(v);
}
