#include <iostream>
#include <sstream>
#include <string>
#include "Matrix.h"

using namespace std;

int main() {
    string inputString;
    string command, matrixName, arg1, arg2, arg3;
    int inputrow = 0, inputcol = 0;

    while (true) {
        cout << "> ";
        getline(cin, inputString);
        stringstream ss(inputString);

        ss >> command;

        if (command == "EXIT") {
            break;
        }

        if (command == "INIT") {
            ss >> matrixName >> inputrow >> inputcol;
            Matrix mat(inputrow, inputcol);
            // mat.init();  // Only if 'init' is defined in Matrix class
            Matrix::addMatrix(matrixName, mat);
            cout << inputrow << "x" << inputcol << " MATRIX" << endl;
        }
        else if (command == "PRINT") {
            ss >> matrixName;
            try {
                Matrix::getMatrix(matrixName).print();
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (command == "GET") {
            ss >> matrixName >> arg1 >> arg2;
            try {
                int row = stoi(arg1) - 1;
                int col = stoi(arg2) - 1;
                cout << "MATRIX[" << row+1 << "][" << col+1 << "] = "
                     << Matrix::getMatrix(matrixName).get(row, col) << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (command == "SET") {
            ss >> matrixName >> arg1 >> arg2 >> arg3;
            try {
                int row = stoi(arg1) - 1;
                int col = stoi(arg2) - 1;
                int value = stoi(arg3);
                Matrix::getMatrix(matrixName).set(row, col, value);
                cout << "MATRIX[" << row+1 << "][" << col+1 << "] = " << value << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (command == "TRANSPOSE") {
            ss >> matrixName;
            try {
                Matrix::getMatrix(matrixName).transpose();
                cout << "TRANSPOSED MATRIX" << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (command == "SWAP_ROWS") {
            ss >> matrixName >> arg1 >> arg2;
            try {
                int row1 = stoi(arg1) - 1;
                int row2 = stoi(arg2) - 1;
                Matrix::getMatrix(matrixName).swapRows(row1, row2);
                cout << "SWAPPED ROWS " << row1+1 << " AND " << row2+1 << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (command == "SWAP_COLS") {
            ss >> matrixName >> arg1 >> arg2;
            try {
                int col1 = stoi(arg1) - 1;
                int col2 = stoi(arg2) - 1;
                Matrix::getMatrix(matrixName).swapCols(col1, col2);
                cout << "SWAPPED COLUMNS " << col1+1 << " AND " << col2+1 << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else {
            cout << "UNSUPPORTED COMMAND" << endl;
        }
    }

    return 0;
}
