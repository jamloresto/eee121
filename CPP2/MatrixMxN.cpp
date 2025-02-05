#include "MatrixMxN.h"

// Constructor
MatrixMxN::MatrixMxN(int m, int n) : Matrix(m, n) {}

// Override the print method
void MatrixMxN::print() const {
    std::cout << "Printing MxN Matrix:" << std::endl;
    Matrix::print();  // Call the base class print method if needed
}

// Override the assignment operator
Matrix& MatrixMxN::operator=(const Matrix& other) {
    if (this != &other) {
        Matrix::operator=(other);  // Call base class assignment operator
    }
    return *this;
}

// Override the addition operator
Matrix* MatrixMxN::operator+(const Matrix& other) const {
    // Assuming same size and type as MatrixMxN
    Matrix* result = new MatrixMxN(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            result->setValue(i, j, getValue(i, j) + other.getValue(i, j));
        }
    }
    return result;
}

// Override the subtraction operator
Matrix* MatrixMxN::operator-(const Matrix& other) const {
    Matrix* result = new MatrixMxN(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            result->setValue(i, j, getValue(i, j) - other.getValue(i, j));
        }
    }
    return result;
}
