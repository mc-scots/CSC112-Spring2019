#include "backtrack.h"

//constructor
Candidate::Candidate()
{
    _nextStep = nullptr;
}


bool Candidate::backtrack()
{
    //return an empty vector if we reject
    if(reject()) { return false; }
    
    //if we are solved, then this is the last step
    //in a solution chain
    if(solved()) { return true; }
    
    _nextStep = next();        //get the next candidate
    while(_nextStep != nullptr) {
        //backtrack from the next solution
        if(_nextStep->backtrack()) { return true; }
        
        //try again
        _nextStep = next();
    }
    
    return false;
}


Candidate *
Candidate::nextStep()
{
    return _nextStep;
}
