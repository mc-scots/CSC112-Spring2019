#include "matrix.h"

using namespace std;

// Constructors and destructor
Matrix::Matrix(int _rows, int _cols) : _rows(_rows), _cols(_cols), 
	_element(_rows, vector<double>(_cols, 0))
{
	/* nothing to do */
}
	
Matrix::Matrix(const Matrix &other):_rows(other.rows()), 
	_cols(other.cols()),
	_element(rows(), vector<double>(cols(), 0))
{
	for(int i=0; i<rows(); i++) {
		for(int j=0; j<cols(); j++) {
			element(i,j) = other.element(i, j);
		}
	}
}

	
//return a reference to a specific element
double & 
Matrix::element(int i, int j)
{
	return _element[i][j];
}

double 
Matrix::element(int i, int j) const
{
	return _element[i][j];
}
    
//return the number of rows
int 
Matrix::rows() const
{
	return _rows;
}
    
//return the number of columns
int 
Matrix::cols() const
{
	return _cols;
}
    
//add a matrix to this one and return the result
Matrix 
Matrix::add(const Matrix &other) const
{
	Matrix result(rows(), cols());
	
	//add the matrices
	for(int i=0; i<rows(); i++) {
		for(int j=0; j<cols(); j++) {
			result.element(i,j) = element(i,j) + other.element(i,j);
		}
	}
	
	return result;
}
    

//subtract a matrix from this one and return the result
Matrix 
Matrix::sub(const Matrix &other) const
{	
	Matrix result(rows(), cols());
	
	//add the matrices
	for(int i=0; i<rows(); i++) {
		for(int j=0; j<cols(); j++) {
			result.element(i,j) = element(i,j) - other.element(i,j);
		}
	}
	
	return result;
}
    
 //multiply this matrix by another one and return the result
 Matrix 
 Matrix::mul(const Matrix &other) const
 {
	 Matrix result(rows(), other.cols());
	 
	 for(int i=0; i<result.rows(); i++) {
		 for(int j=0; j<result.cols(); j++) {
			 result.element(i,j) = 0.0;
			 for(int k=0; k<cols(); k++) {
				 result.element(i,j) += element(i,k) * other.element(k,j);
			 }
		 }
	 }
	 
	 return result;
 }

//an assignment operator
Matrix & 
Matrix::operator=(const Matrix &other)
{
	//redimension
	_rows = other.rows();
	_cols = other.cols();
	
	//copy over our vector
	_element.clear();
	for(int i=0; i<_rows; i++) {
		_element.push_back(vector<double>(_cols, 0));
		for(int j=0; j<_cols; j++) {
			_element[i][j] = other.element(i,j);
		}
	}
	
	return *this;
}
	
//Addition operation
Matrix 
Matrix::operator+(const Matrix &other) const
{
	return add(other);
}
	
//Subtraction operation
Matrix 
Matrix::operator-(const Matrix &other) const
{
	return sub(other);
}
	
//Multiplication operation
Matrix 
Matrix::operator*(const Matrix &other) const
{
	return mul(other);
}


//insertion operator
std::ostream & 
operator<<(std::ostream &os, const Matrix &m)
{
	for(int i=0; i<m.rows(); i++) {
		for(int j=0; j<m.cols(); j++) {
			os << m.element(i,j) << '\t';
		}
		os << endl;
	}
	
	return os;
}

//extraction operator
std::istream & 
operator>>(std::istream &is, Matrix &m)
{
	for(int i=0; i<m.rows(); i++) {
		for(int j=0; j<m.cols(); j++) {
			is >> m.element(i, j);
		}
	}
	
	return is;
}
