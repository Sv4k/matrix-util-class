#include <iostream>
#include "Matrix.h"
#include "gausian.h"
#include "gausian_w.h"
#include "Zeydel.h"
#include "MMN.h"

using namespace std;

int main() {
    Matrix A(4, 4);
    A.fill();
    Matrix b(4, 1);
    b.fill();
    /*Matrix* L = new Matrix(5, 5);
    cout << "\n";
    Matrix U = A.upperDiag(L);
    U.print();
    cout << "\n";
    L->print();
    cout << "\n";
    (*L*U).print();
     */
    mmn(A, b, 0.001).print();
}