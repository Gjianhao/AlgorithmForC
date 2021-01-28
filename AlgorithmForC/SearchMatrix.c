//
//  SearchMatrix.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#include "SearchMatrix.h"

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    // 使用对角线搜索
    int r = 0, c = *matrixColSize - 1;
    while (r <matrixSize && c >= 0) {
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            c--;
        } else {
            r++;
        }
    }
    return false;
}
