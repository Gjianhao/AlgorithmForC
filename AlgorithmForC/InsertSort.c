//
//  InsertSort.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#include "InsertSort.h"

#pragma mark - 插入排序

/// 912. 排序数组     插入排序: 稳定排序,在接近有序的情况下,表现优异
int* insertSort(int *nums, int numsSize) {
    // 内层 for 循环是倒序循环
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j > 0; j--) {
            if (nums[j] < nums[j - 1]) {
                int tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            } else {
                break;
            }
        }
    }
    return nums;
}
