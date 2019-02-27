//
// Created by XqzmeLoL on 02.10.2018.
//

#pragma once

class Matrix {
    double **matrix;
    unsigned int length;
    unsigned int height;


public:
    Matrix (unsigned int height, unsigned int length);
    Matrix (unsigned int height, unsigned int length, double value);
    Matrix (const Matrix &other);
    ~Matrix();



    int getLength ();
    int getHeight();
    double getMaxElem();

    Matrix inverse();
    void fill();
    void print();
    Matrix extend (const Matrix &b);
    Matrix upperDiag(Matrix* L);
    Matrix upperDiag(int* signOfDet);
    double det();
    Matrix trans();
    void set(unsigned int lineCoef, unsigned int colCoef, double value);


    double* linesSum(unsigned int add, unsigned int added, double scalar);
    Matrix deleteLine(unsigned int index);
    void swapLine(unsigned int index1, unsigned int index2);
    void setLine(unsigned int index, double* line);

    void swapColumn(unsigned int index1, unsigned int index2);
    double* getColumn(unsigned int index);
    Matrix deleteColumn(unsigned int index);
    double* columnsSum(unsigned int add, unsigned int added, double scalar);
    void setColumn(unsigned int index, double* column);


private:
    Matrix sum (const Matrix &other, bool isSignPositive);
    Matrix composition (const Matrix &other);





public:
    Matrix operator= (const Matrix &other);
//get [index] line of matrix
    double* operator[] (unsigned int index);
//check if 2 matrices are equals
    bool operator== (const Matrix &other);
    bool operator!= (const Matrix &other);
//sum of 2 matrices
    Matrix operator+ (const Matrix &other);
    Matrix operator+= (const Matrix &other);
    Matrix operator- (const Matrix &other);
    Matrix operator-= (const Matrix &other);
//composition of 2 matrices
    Matrix operator* (const Matrix &other);
    Matrix operator*= (const Matrix &other);
    Matrix operator* (double scalar);
    Matrix operator*= (double scalar);
    Matrix operator^ (int i);
};

