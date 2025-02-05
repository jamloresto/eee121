#include "Matrix.h"

std::unordered_map<std::string, Matrix> Matrix::matrixCollection;

Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<int>(cols, 0)); // Initialize with zeros
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

const std::vector<std::vector<int>>& Matrix::getData() const {
    return data;
}

int Matrix::get(int r, int c) const {
    return data[r][c];
}

void Matrix::set(int r, int c, int value) {
    data[r][c] = value;
}

void Matrix::initializeMatrix(int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = value;
        }
    }
}

void Matrix::transpose() {
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = data[i][j];
        }
    }
    data = transposed;
    std::swap(rows, cols);
}

void Matrix::swapRows(int row1, int row2) {
    std::swap(data[row1], data[row2]);
}

void Matrix::swapCols(int col1, int col2) {
    for (int i = 0; i < rows; ++i) {
        std::swap(data[i][col1], data[i][col2]);
    }
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    return (rows == other.rows && cols == other.cols && data == other.data);
}

Matrix* Matrix::operator+(const Matrix& other) const {
    // Assuming same dimensions for simplicity
    Matrix* result = new Matrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->set(i, j, data[i][j] + other.get(i, j));
        }
    }
    return result;
}

Matrix* Matrix::operator-(const Matrix& other) const {
    // Assuming same dimensions for simplicity
    Matrix* result = new Matrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result->set(i, j, data[i][j] - other.get(i, j));
        }
    }
    return result;
}

void Matrix::addMatrix(const std::string& name, const Matrix& matrix) {
    matrixCollection[name] = matrix;
}

Matrix& Matrix::getMatrix(const std::string& name) {
    return matrixCollection.at(name);
}

// Implement the getValue method
int Matrix::getValue(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[r][c];
}

// Implement the setValue method
void Matrix::setValue(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    data[r][c] = value;
}