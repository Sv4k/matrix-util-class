//
// Created by goust on 30.10.2018.
//

#include "gausian.h"
#include "Matrix.h"

Matrix gauss(Matrix A, Matrix b) {
    Matrix B = A.extend(b);
    for (int i = 0; i < B.getHeight() - 1; i++) {
        //check if B[i][i] != 0
        if (B[i][i] == 0) {
            for (int j = i + 1; j < B.getHeight(); j++) {
                if (B[j][i]) {
                    B.swapLine(i, j);
                }
            }
        }
        for (int j = i + 1; j < B.getHeight(); j++ ) {
            B.setLine(j, B.linesSum(j, i, -1 * (B[j][i]/B[i][i])));
        }
    }
    Matrix X(1, B.getHeight(), 0);
    for(int j = X.getLength() - 1; j >= 0; j--){
        for(int i = j + 1; i < B.getLength() - 1; i++) {
            X[0][j] -= B[j][i] * X[0][i];
        }
        X[0][j] += B[j][B.getLength() - 1];
        X[0][j] /= B[j][j];
    }
    return X;
}
