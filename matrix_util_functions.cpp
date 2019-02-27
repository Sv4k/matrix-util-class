//
// Created by goust on 05.11.2018.
//

#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <fstream>

Matrix Matrix::extend(const Matrix &other) {
    Matrix extended(height, length + other.length);
    for (int i = 0; i < extended.height; i++) {
        for (int j = 0; j < extended.length; j++) {
            extended.matrix[i][j] = j < length ? matrix[i][j] : other.matrix[i][j - length];
        }
    }
    return extended;
}
Matrix Matrix::trans() {
    Matrix tr(length, height);
    for(int i = 0; i < length; i++)
        for(int j = 0; j < height; j++)
            tr[i][j] = matrix[j][i];
    return tr;
}
void Matrix::print() {
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            printf("%.8f   ", matrix[i][j]);
        }
        std::cout << "\n";
    }
}
void Matrix::fill() {
    for(int i = 0; i < height; i++) {
        for(int j = 0 ; j < length; j++) {
            std :: cin >> matrix[i][j];
            //matrix[i][j] = exp(-abs(i-j));
        }
    }
}

double Matrix::getMaxElem() {
    double max = matrix[0][0];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            if(matrix[i][j] > max)
                max = matrix[i][j];
    return max;
}

void Matrix::set(unsigned int lineCoef, unsigned int colCoef, double value) {
    matrix[lineCoef][colCoef] = value;
}


