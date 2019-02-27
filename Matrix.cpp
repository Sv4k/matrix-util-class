//
// Created by XqzmeLoL on 02.10.2018.
//

#include "Matrix.h"
#include "Exception.h"
#include "gausian.h"

Matrix::Matrix(unsigned int height, unsigned int length) : length(length), height(height) {
    matrix = new double*[height];
    for(int i = 0; i < height; i++)
        matrix[i] = new double[length];
}
Matrix::Matrix(unsigned int height, unsigned int length, double value) :length(length), height(height) {
    matrix = new double*[height];
    for(int i = 0; i < height; i++)
        matrix[i] = new double[length];
    for(int i = 0 ; i < height; i++) {
        for(int j = 0; j < length; j++)
            matrix[i][j] = value;
    }
}
Matrix::~Matrix() {
    for(int i = 0 ; i < height; i++)
        delete[] matrix[i];
    delete matrix;
}
Matrix::Matrix(const Matrix &other) {
    length = other.length;
    height = other.height;
    matrix = new double*[height];
    for(int i = 0; i < height; i++)
        matrix[i] = new double[length];
    for(int i = 0; i < height; i++) {
        for(int j = 0 ; j < length; j++)
            matrix[i][j] = other.matrix[i][j];
    }
}
int Matrix::getLength() {
    return length;
}
int Matrix::getHeight() {
    return height;
}


Matrix Matrix::sum(const Matrix &other, bool isSignPositive) {
    if(length != other.length || height != other.height)
        throw new Exception("Sizes of these matrices are different. Impossible to summarise");
    Matrix result(height, length);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < length; j++)
            result.matrix[i][j] = matrix[i][j] + (isSignPositive ? 1 : -1) * other.matrix[i][j];
    }
    return result;
}
Matrix Matrix::composition(const Matrix &other) {
    if(length != other.height)
        throw new Exception ("Illegal sizes. Impossible to composite");
        Matrix result(height, other.length, 0);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < other.length; j++)
                for (int k = 0; k < length; k++) {
                    result.matrix[i][j] +=
                            matrix[i][k] * other.matrix[k][j];
                }
        return result;
}


Matrix Matrix::upperDiag(int* signOfDet) {
    Matrix upperDiag = *this;
    int pow = 0;
    for (int i = 0; i < upperDiag.getHeight() - 1; i++) {
        if (upperDiag[i][i] == 0) {
            for (int j = i + 1; j < upperDiag.getHeight(); j++) {
                if (upperDiag[j][i]) {
                    upperDiag.swapLine(i, j);
                    pow++;
                }
            }
        }
        for (int j = i + 1; j < upperDiag.getHeight(); j++ ) {
            upperDiag.setLine(j, upperDiag.linesSum(j, i, -1 * (upperDiag[j][i]/upperDiag[i][i])));
        }
    }
    *signOfDet = pow % 2 ? -1 : 1;
    return upperDiag;
}
Matrix Matrix::upperDiag(Matrix* L) {
    Matrix upperDiag = *this;
    //Matrix E (height, length, 0);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            L->set(i, j, (i == j) ? 1 : 0);
    for (int i = 0; i < upperDiag.getHeight() - 1; i++) {
        if (! upperDiag[i][i]) {
            for (int j = i + 1; j < upperDiag.getHeight(); j++ ) {
                if (upperDiag[j][i]) {
                    upperDiag.swapLine(i , j);
                }
            }
        }

        for (int j = i + 1; j < upperDiag.getHeight(); j++ ) {
                double value = (upperDiag[j][i] / upperDiag[i][i]);
                upperDiag.setLine(j, upperDiag.linesSum(j, i, -1 * value));
                L->set(j, i, value);
        }
    }
    return upperDiag;
}
double Matrix::det() {
    int signOfDet = 1;
    Matrix forDet = this->upperDiag(&signOfDet);
    double det = 1;
    for(int i = 0; i < height; i++) {
        det *= forDet[i][i];
    }
    return det * signOfDet;
}
Matrix Matrix::inverse() {
    /*Matrix inv(height, length);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < length; j++) {
            inv[i][j] = deleteLine(i).deleteColumn(j).det();
        }
    }
    inv[0][1] *= -1;
    inv[height -1][height - 2] *= -1;
    for(int i = 1; i < height-1; i++) {
        inv[i][i - 1] *= -1;
        inv[i][i + 1] *= -1;
    }
    inv = inv.trans();
    return inv *= 1 / det();*/
    Matrix inv (height,length);
    Matrix b (height, 1, 0);
    for(int i = 0; i < length; i++) {
        b[i][0] = 1;
        inv.setColumn(i, gauss(*this, b)[0]);
        b[i][0] = 0;
    }
    return inv;
}













