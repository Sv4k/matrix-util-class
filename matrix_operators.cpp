//
// Created by goust on 05.11.2018.
//

#include "Matrix.h"
#include "Exception.h"

double *Matrix::operator[] (unsigned int index) {
    if(index >= height)
        throw new Exception("You try to get nonexistent line");
    return matrix[index];
}
bool Matrix::operator== (const Matrix &other) {
    if(length == other.length && height == other.height) {
        for(int i = 0; i < height; i++) {
            for(int j = 0 ; j < length; j++)
                if(!matrix[i][j] == other.matrix[i][j]) {
                    return false;
                }
        }
        return true;
    }
    return false;
}
bool Matrix::operator!= (const Matrix &other) {
    if(length == other.length && height == other.height) {
        for(int i = 0; i < height; i++) {
            for(int j = 0 ; j < length; j++)
                if(!matrix[i][j] == other.matrix[i][j]) {
                    return true;
                }
        }
        return false;
    }
    return true;
}
//sum can throw exception
Matrix Matrix::operator-(const Matrix &other) {
    return sum(other, false);
}
//sum can throw exception
Matrix Matrix::operator+(const Matrix &other) {
    return sum(other, false);
}
Matrix Matrix::operator+=(const Matrix &other) {
    *this = *this + other;
    return *this;
}
//composition can throw exception
Matrix Matrix::operator*(const Matrix &other) {
    return composition(other);
}
Matrix Matrix::operator*(double scalar) {
    Matrix result(length, height);
    for(int i = 0; i < height; i++)
        for(int j = 0 ; j < length; j++)
            result.matrix[i][j] = matrix[i][j] * scalar;
}
Matrix Matrix::operator^(int power) {
    Matrix pow(height, length, 0);
    for(int i = 0; i < height; i++) {
        pow[i][i] = 1;
    }
    if(!power) {
        return pow;
    }
    Matrix inst = power < 0 ? inverse() : *this;
    for(int i = 0; i < power; i++) {
        pow *= inst;
    }
}
Matrix Matrix::operator-=(const Matrix &other) {
    *this = *this - other;
    return *this;
}
Matrix Matrix::operator*=(const Matrix &other) {
    *this = *this * other;
    return *this;
}
Matrix Matrix::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}
Matrix Matrix::operator=(const Matrix &other) {
    for(int i = 0; i < height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    length = other.length;
    height = other.height;
    Matrix returnable = other;
    return returnable;
}
