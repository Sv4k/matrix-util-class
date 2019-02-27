//
// Created by goust on 05.11.2018.
//

#include "Matrix.h"
#include "Exception.h"

double* Matrix::getColumn(unsigned int index) {
    if(index >= length)
        throw new Exception("You try to get nonexistent column");
    double* column = new double[height];
    for(int i = 0; i < height; i++)
        column[i] = matrix[i][index];
    return column;
}
Matrix Matrix::deleteColumn(unsigned int index) {
    if(index >= length)
        throw new Exception("You try to delete a nonexistent column");
    Matrix newMatrix(height, length - 1);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < length - 1; j++)
            newMatrix[i][j] = j < index ? matrix[i][j] : matrix[i][j + 1];
    }
    return newMatrix;
}
void Matrix::setColumn(unsigned int index, double *column) {
    if(index >= length)
        throw new Exception("You try to set nonexistent column");
    if(!column)
        throw new Exception("You try to set indefinite column");
    for(int i = 0; i < height; i++){
        matrix[i][index] = column[i];
    }
}
void Matrix::swapColumn(unsigned int index1, unsigned int index2) {
    if(index1 >= length)
        throw new Exception ("Illegal index1");
    if(index2 >= length)
        throw new Exception ("Illegal index2");
    for(int i = 0; i < height; i++) {
        double tmp;
        tmp = matrix[i][index1];
        matrix[i][index1] = matrix[i][index2];
        matrix[i][index2] = tmp;
    }
}
double *Matrix::columnsSum(unsigned int add, unsigned int added, double scalar) {
    if(add >= length)
        throw new Exception("Illegal index of column you wanna add to");
    if(added >= length)
        throw new Exception("Illegal index of added column");
    double* sum = new double[height];
    for(int i = 0; i < height; i++) {
        sum[i] = matrix[i][add] + matrix[i][added] * scalar;
    }
    return sum;
}
