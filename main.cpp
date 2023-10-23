#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;


void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& size, const std::string& fileName);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;

    std::cout << "Bisshoy Bhattacharjee" << std::endl;
    std::cout << "Matrix Problem Solver" << std::endl;

    readMatrixFromFile(matrix1, size, "matrix_input.txt");

    readMatrixFromFile(matrix2, size, "matrix_input.txt");


    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, size);

    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& size, const std::string& fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        exit(1);
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
