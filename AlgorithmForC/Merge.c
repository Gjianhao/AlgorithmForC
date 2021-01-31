//
//  Merge.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/31.
//

#include "Merge.h"


/// 88. 合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    // 使用倒序
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0) {
        nums1[k--] = (i < 0 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
    }
}
