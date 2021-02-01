//
//  FairCandySwap.c
//  AlgorithmForC
//
//  Created by gjh on 2021/2/1.
//

#include "FairCandySwap.h"

// 数组求和
int sumArr(int* arr, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
/// 888.公平的糖果交换
/// 思路:  A和 B 分别需要交出的糖果为 x, y
///  所以 A - x + y = B + x - y
///   x - y = (A - B) / 2
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    // 先对两个数组进行求和
    int sumA = sumArr(A, ASize);
    int sumB = sumArr(B, BSize);
    // 两个数组的差值
    int diff = (sumA - sumB) / 2;
    // 定义返回值
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    // 对两个数组进行排序
    qsort(A, ASize, sizeof(int), comp);
    qsort(B, BSize, sizeof(int), comp);
    // 双指针
    int i = 0, j = 0;
    while (i < ASize && j < BSize) {
        if (A[i] - B[j] == diff) {
            result[0] = A[i];
            result[1] = B[j];
            return result;
        } else if (A[i] - B[j] > diff) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}
