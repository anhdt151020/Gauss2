//
// Created by TuanAnh on 9/14/2021.
//

#ifndef GAUSSC2_MATRIX_H
#define GAUSSC2_MATRIX_H

float A[10][10], AS[10][10],AT[10][10], X[10], B[10], Y[10]; // Khởi tạo ma trận hệ số, ma trận nghiệm, ma trận giá trị B ban đầu, Y ban đầu phục vụ Cholesky
int n, m; // Số ẩn của hệ phương trình
FILE *fin,*fou;

bool isZero(int t){
    bool check = false;
    for (int i = 1; i <= n; ++i) {
        if (A[t][i] != 0) check = false;
        if (A[t][i] == 0) check = true;
    }
    return check;
}
void doiChoHaiHang(int a, int b){
    for (int i = 1; i <= n; ++i) {
        Y[i] = A[a][i];
        A[a][i] = A[b][i];
        A[b][i] = Y[i];
    }
}

void inMaTranHeSo(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.5f ", A[i][j]);
        }
        printf("\n");
    }
}

void inNghiem(){
    for (int i = 1; i <=n; ++i) {
        printf("X[%d] = %.20f \n",i,X[i]);
        fprintf(fou,"X[%d] = %.20f \n",i,X[i]);

    }
}

void inMaTranBoSung(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%lf \t", A[i][j]);
            fprintf(fou,"%lf \t", A[i][j]);
        }
        printf("\n");
        fprintf(fou,"\n");

    }
}

void bienAThanhMatranBoSung(){
    for (int i = 1; i <= n; i++) {
        A[i][n+1] = B[i];
    }
}
#endif //GAUSSC2_MATRIX_H
