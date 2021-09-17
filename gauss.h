//
// Created by TuanAnh on 9/14/2021.
//

#ifndef GAUSSC2_GAUSS_H
#define GAUSSC2_GAUSS_H

// Hàm kiểm tra hai hàng bất kì có bằng bội của nhau hay không
void checkAn(int n) {
    bool c;
    m = n;
    float temp, check;
    int t = 1;
    for (int i = 1; i <= n; ++i) {
        if (isZero(i)) continue;
        for (int j = i + 1; j <= n; ++j) {
            c = false;
            if (j == i) continue;
            if (j != i) {
                temp = A[j][1] / A[i][1];
            }
            for (int k = 1; k <= n; ++k) {
                check = A[j][k] - temp * A[i][k];
                if (check != 0) {
                    c = false;
                    continue;
                };
                if (check == 0) {
                    c = true;
                }
            }
            if (c == true) {
                for (int k = 1; k <= n; ++k) {
                    AS[t][k] = A[j][k];
                    A[j][k] = 0;
                    AS[t][n+1] = A[j][n+1] - temp * A[i][n+1];
                    //printf("AS = %f\n",AS[t][n+1]);
                }
               // printf("A = %f - temp = %f- A=%f - t = %d - n =%d\n",A[i][n+1],temp,A[j][n+1],t,n);
                t ++;
                m = m - 1;
            }
            if (c == false){

            }
        }
    }
    t = 1;
    for (int i = 1; i <= n; ++i) {
        if (isZero(i) == false){
            for (int j = 1; j <= n + 1; ++j) {
                AT[t][j] = A[i][j];
            }
            t++;
        }
    }
}

// Hàm biến đổi ma trận bổ sung ban đầu về ma trận bậc thang sử dụng thuật toán khử Gauss
void khuGauss(int m) {
    fprintf(fou, "XU LI MA TRAN BAN DAU BANG PHUONG PHAP KHU GAUSS\n");
    float t;
    for (int i = 1; i <= m; i++) {
        for (int k = i + 1; k <= n; k++) {
            t = A[k][i] / A[i][i];
            for (int j = 1; j <= n+1; j++) {
                A[k][j] = A[k][j] - t * A[i][j];
            }
        }
    }
}

// Hàm giải hệ phương trình sau khi đã đưa ma trận bổ sung về ma trận bậc thang
void giaiHeGauss(int n) {
    X[n] = A[n][n + 1] / A[n][n];
    for (int i = n - 1; i >= 1; i--) {
        X[i] = A[i][n + 1];
        for (int j = i + 1; j <= n; j++) {
            X[i] = X[i] - A[i][j] * X[j];
        }
        X[i] = X[i] / A[i][i];
    }
}

#endif //GAUSSC2_GAUSS_H
