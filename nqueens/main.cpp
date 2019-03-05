// driver for the nqueens problem
#include <iostream>
#include "nqueens.h"

using namespace std;

int main()
{
    N_Queens *nq;
    int n;

    //get the n value
    cout << "N=";
    cin >> n;

    //make and run the puzzle
    nq = new N_Queens(n);
    if(nq->backtrack())
    {
        cout << "Solved" << endl;
    } else {
        cout << "No possible Solution" << endl;
    }

    return 0;
}
