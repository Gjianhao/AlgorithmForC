//
//  QuickSort.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#include "QuickSort.h"


// 912.排序数组     最快的排序:必须掌握  快速排序
void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
// 划分区域
int partition(int arr[], int leftBound, int rightBound) {
    int pivot = rightBound; // 枢纽元
    // 左边指针
    int left = leftBound;
    for (int i = leftBound; i <= rightBound; i++) {
        if (arr[i] < arr[pivot]) {
            if (left != i) swap(arr, i, left);
            left++;
        }
    }
    swap(arr, left, pivot);
    return left;
}

void quickSort(int arr[], int leftBound, int rightBound) {
    if (leftBound > rightBound) return;
    int pivot = partition(arr, leftBound, rightBound);
    // 递归
    quickSort(arr, leftBound, pivot - 1);
    quickSort(arr, pivot + 1, rightBound);
}

int* sortArray(int* nums, int numsSize){
    quickSort(nums, 0, numsSize - 1);
    return nums;
}
