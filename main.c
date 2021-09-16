#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>
// ================================ KHÔNG XÓA CÁC IMPORT TRÊN DÒNG NÀY=====================================
#include "matrix.h"
#include "gauss.h"

void main() {
    fou = fopen("outputc2.txt","w");
    fin = fopen("C:\\Users\\TuanAnh\\CLionProjects\\GaussC2\\input.txt","r");
    fscanf(fin,"%d\n",&n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fscanf(fin,"%f\n",&A[i][j]) ;
        }
    }
    for (int i = 1; i <= n; ++i) {
        fscanf(fin,"%f\n",&B[i]);
    }
    fprintf(fou,"MA TRAN HE SO BAN DAU\n");
    bienAThanhMatranBoSung();
    inMaTranBoSung();
    fprintf(fou,"-=====================================================- \n");
    checkAn(n);
    printf("=============\n");

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n +1; ++j) {
            A[i][j] = AT[i][j];
        }
    }
    khuGauss(m);
    int t = 1;
    for (int i = 1; i <= n; ++i) {
        A[i][n+1] = AS[t][n+1];
        t++;
    }
    bienAThanhMatranBoSung();
    inMaTranBoSung();
    if (m == n){
        giaiHeGauss(n);
        inNghiem();
    }
    if (m < n){
        for (int i = 1; i <=n ; ++i) {
            if ((isZero(i)) && (A[i][n+1] != 0)){
                printf("He PT vo nghiem\n");
                fprintf(fou,"He PT vo nghiem\n");
                exit(0);
            }
        }
        printf("He PT co vo so nghiem");
        fprintf(fou,"He PT co vo so nghiem");
    }
    fclose(fin);
    fclose(fou);
}