#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> data;

    // Static map to hold matrices by name
    static std::unordered_map<std::string, Matrix> matrixCollection;

public:
    // Constructors
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);

    // Destructor (if needed)
    virtual ~Matrix() {}

    // Accessor methods
    int getRows() const;
    int getCols() const;
    const std::vector<std::vector<int>>& getData() const;
    int get(int r, int c) const;

    // Mutator methods
    void setValue(int r, int c, int value);
    void set(int r, int c, int value);
    int getValue(int r, int c) const;

    // Matrix initialization method
    void initializeMatrix(int value = 0);

    // Transpose matrix
    void transpose();

    // Swap rows and columns
    void swapRows(int row1, int row2);
    void swapCols(int col1, int col2);

    // Virtual print method
    virtual void print() const;

    // Operator overloads
    virtual Matrix& operator=(const Matrix& other);
    virtual bool operator==(const Matrix& other) const;
    virtual Matrix* operator+(const Matrix& other) const;
    virtual Matrix* operator-(const Matrix& other) const;

    // Static methods to manage the collection of matrices
    static void addMatrix(const std::string& name, const Matrix& matrix);
    static Matrix& getMatrix(const std::string& name);
};

#endif // MATRIX_H
