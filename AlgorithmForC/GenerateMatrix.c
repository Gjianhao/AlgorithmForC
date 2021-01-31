//
//  GenerateMatrix.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/30.
//

#include "GenerateMatrix.h"

/**
 * 59. 螺旋矩阵 II
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // 返回数组的行数 为 n
    * returnSize = n;
    // 返回数组的列数
    * returnColumnSizes = (int*)malloc(sizeof(int) * n);
    // 返回数组
    int** result = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    // 定义上下左右边界
    int top = 0, right = n - 1, bottom = n - 1, left = 0;
    // 起始数, 和结束数
    int cur = 1, end = n * n;
    while (cur <= end) {
        // 从左到右,从上到下开始排列
        for (int i = left; i <= right; i++) {
            result[top][i] = cur++;
        }
        // 内缩
        top++;
        // 右侧, 从上到下
        for (int i = top; i <= bottom; i++) {
            result[i][right] = cur++;
        }
        right--;
        // 底部, 从右到左
        for (int i = right; i >= left; i--) {
            result[bottom][i] = cur++;
        }
        bottom--;
        // 左边 ,从下到上
        for (int i = bottom; i >= top; i--) {
            result[i][left] = cur++;
        }
        left++;
    }
    return result;
}
