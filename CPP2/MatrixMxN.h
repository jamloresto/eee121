#ifndef MATRIXMXN_H
#define MATRIXMXN_H

#include "Matrix.h"

class MatrixMxN : public Matrix {
public:
    // Constructor
    MatrixMxN(int m, int n);

    // Override methods
    void print() const override;
    Matrix& operator=(const Matrix& other) override;
    Matrix* operator+(const Matrix& other) const override;
    Matrix* operator-(const Matrix& other) const override;
};

#endif // MATRIXMXN_H
