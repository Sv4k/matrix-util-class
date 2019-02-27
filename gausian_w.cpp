//
// Created by goust on 31.10.2018.
//

#include "gausian_w.h"
#include "Matrix.h"

Matrix gauss_w (Matrix A, Matrix b) {
    Matrix B = A.extend(b);
    for (int i = 0; i < B.getHeight() - 1; i++) {
        for (int j = i + 1; j < B.getHeight(); j++) {
            if (B[j][i] > B[i][i]) {
                B.swapLine(i, j);
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
