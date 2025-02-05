# WEEK 2

## Requirements

- A C++ compiler (e.g., `g++` or `clang++`)
- Basic understanding of C++ and object-oriented programming

## Files Overview

- `Matrix.h` – Header file defining the `Matrix` class and its methods.
- `Matrix.cpp` – Implementation of the `Matrix` class.
- `MatrixMxN.h` – Header file for an extension of the `Matrix` class to support MxN matrices.
- `MatrixMxN.cpp` – Implementation of the `MatrixMxN` class.
- `MatrixNxN.h` – Header file for an extension of the `Matrix` class to support NxN matrices.
- `MatrixNxN.cpp` – Implementation of the `MatrixNxN` class.
- `matrix-lab.cpp` – Main file containing the user interface and logic to interact with the matrices.

## Compilation

### Step 1: Compile the object files

To compile the C++ files into object files, run the following commands:

```bash
g++ -c Matrix.cpp -o Matrix.o
g++ -c MatrixMxN.cpp -o MatrixMxN.o
g++ -c MatrixNxN.cpp -o MatrixNxN.o
g++ -c matrix-lab.cpp -o matrix-lab.o
```

This will generate the following object files:

- Matrix.o
- MatrixMxN.o
- MatrixNxN.o
- matrix-lab.o

### Step 2: Link the object files into an executable

After successfully compiling the object files, link them together into an executable file:

```bash
g++ matrix-lab.o Matrix.o MatrixMxN.o MatrixNxN.o -o matrix-lab
```

This command will generate an executable named matrix-lab (on Windows, it will be matrix-lab.exe).

## Running the Program

Once the program is compiled, you can run the executable:

### On Linux/Mac:
```bash
./matrix-lab
```

### On Windows:
```bash
matrix-lab.exe
```