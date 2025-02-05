#include "MatrixNxN.h"

// Constructor
MatrixNxN::MatrixNxN(int r, int c) : Matrix(r, c) {}

// Override the print method
void MatrixNxN::print() const {
    std::cout << "Printing NxN Matrix:" << std::endl;
    Matrix::print();  // Call the base class print method if desired
}

// Override the assignment operator
Matrix& MatrixNxN::operator=(const Matrix& other) {
    if (this != &other) {
        Matrix::operator=(other);  // Call base class assignment operator
    }
    return *this;
}

// Override the addition operator
Matrix* MatrixNxN::operator+(const Matrix& other) const {
    // Assuming same size and type as MatrixNxN
    Matrix* result = new MatrixNxN(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            result->setValue(i, j, getValue(i, j) + other.getValue(i, j));
        }
    }
    return result;
}

// Override the subtraction operator
Matrix* MatrixNxN::operator-(const Matrix& other) const {
    Matrix* result = new MatrixNxN(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            result->setValue(i, j, getValue(i, j) - other.getValue(i, j));
        }
    }
    return result;
}
