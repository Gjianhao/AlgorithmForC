//
//  MergeSort.c
//  AlgorithmForC
//
//  Created by gjh on 2021/2/1.
//

#include "MergeSort.h"

// 912.排序数组     必须掌握  归并排序
void merge(int* arr, int leftPtr, int rightPtr, int rightBound) {
    // 中间值
    int mid = rightPtr - 1;
    int* temp = (int*)malloc(sizeof(int) * (rightBound - leftPtr + 1));
    
    // 定义三个指针
    int i = leftPtr, j = rightPtr, k = 0;
    
    while (i <= mid && j <= rightBound) {
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    // 处理 i 或者 j 提前结束
    while (i <= mid) temp[k++] = arr[i++];   // i 还有值
    while (j <= rightBound) temp[k++] = arr[j++];   // j 还有值
    
    // 将 temp 赋值给 arr
    for (int m = 0; m < (rightBound - leftPtr + 1); m++) {
        arr[leftPtr + m] = temp[m];
    }
}
void sort(int* arr, int left, int right) {
    if (left == right) return;
    // 分成两半
    int mid = left + ((right - left) >> 1);
    // 左边排序
    sort(arr, left, mid);
    // 右边排序
    sort(arr, mid + 1, right);
    merge(arr, left, mid + 1, right);
}
