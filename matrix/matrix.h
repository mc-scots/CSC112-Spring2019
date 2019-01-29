#include <vector>
#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H

//A small matrix class for doing basic arithmetic with matrices
class Matrix
{
public:
	// Constructors and destructor
	Matrix(int _rows, int _cols);
	Matrix(const Matrix &other);
	virtual ~Matrix() { /* do nothing */ }
	
	//return a reference to a specific element
    virtual double & element(int i, int j);
    
    //return a read only version of the a specific element
    virtual double element(int i, int j) const;
    
    //return the number of rows
    virtual int rows() const;
    
    //return the number of columns
    virtual int cols() const;
    
    //add a matrix to this one and return the result
    virtual Matrix add(const Matrix &other) const;
    
    //subtract a matrix from this one and return the result
    virtual Matrix sub(const Matrix &other) const;
    
    //multiply this matrix by another one and return the result
    virtual Matrix mul(const Matrix &other) const;

	//an assignment operator
	virtual Matrix & operator=(const Matrix &other);
	
	//Addition operation
	virtual Matrix operator+(const Matrix &other) const;
	
	//Subtraction operation
	virtual Matrix operator-(const Matrix &other) const;
	
	//Multiplication operation
	virtual Matrix operator*(const Matrix &other) const;
	
private:
	int _rows;	//number of rows
	int _cols;  //number of columns
	std::vector<std::vector<double>> _element; //elements
};

//insertion operator
std::ostream & operator<<(std::ostream &os, const Matrix &m);

//extraction operator
std::istream & operator>>(std::istream &is, Matrix &m);
#endif 
