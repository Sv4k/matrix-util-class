//
// Created by goust on 05.11.2018.
//

#include "Matrix.h"

double *Matrix::linesSum(unsigned int add, unsigned int added, double scalar) {
    double* tmp = new double[length];
    for(int i = 0; i  < length; i++) {
        tmp[i] = matrix[add][i] + matrix[added][i] * scalar;
    }
    return tmp;
}
Matrix Matrix::deleteLine(unsigned int index) {
    Matrix newMatrix(height - 1, length);
    for(int i = 0; i < height - 1; i++) {
        for(int j = 0; j < length; i++)
            newMatrix[i][j] = i < index ? matrix[i][j] : matrix[i + 1][j];
    }
    return newMatrix;
}
void Matrix::setLine(unsigned int index, double* line){
    matrix[index] = line;
}
void Matrix::swapLine(unsigned int index1, unsigned int index2) {
    double* tmp = matrix[index1];
    matrix[index1] = matrix[index2];
    matrix[index2] = tmp;
}

