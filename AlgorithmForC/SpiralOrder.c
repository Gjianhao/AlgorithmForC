//
//  SpiralOrder.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/30.
//

#include "SpiralOrder.h"
/**
 * 54. 螺旋矩阵
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }// 列数
    int colSize = *matrixColSize;
    // 返回数组的长度
    *returnSize = matrixSize * colSize;
    
    // 定义返回值
    int* result = (int*)malloc(sizeof(int) * *returnSize);
    int top = 0, left = 0, right = colSize - 1, bottom = matrixSize - 1;
    int first = 0;
    while (first < *returnSize) {
        for (int i = left; first < *returnSize && i <= right; i++) {
            result[first++] = matrix[top][i];
        }
        top++;
        for (int i = top; first < *returnSize && i <= bottom; i++) {
            result[first++] = matrix[i][right];
        }
        right--;
        for (int i = right; first < *returnSize && i >= left; i--) {
            result[first++] = matrix[bottom][i];
        }
        bottom--;
        for (int i = bottom; first < *returnSize && i >= top; i--) {
            result[first++] = matrix[i][left];
        }
        left++;
    }
    return result;
}
