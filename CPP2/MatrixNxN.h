#ifndef MATRIXNXN_H
#define MATRIXNXN_H

#include "Matrix.h"

class MatrixNxN : public Matrix {
public:
    // Constructor
    MatrixNxN(int r, int c);

    // Override methods
    void print() const override;
    Matrix& operator=(const Matrix& other) override;
    Matrix* operator+(const Matrix& other) const override;
    Matrix* operator-(const Matrix& other) const override;
};

#endif // MATRIXNXN_H
