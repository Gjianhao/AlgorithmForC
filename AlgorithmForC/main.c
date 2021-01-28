//
//  main.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

#pragma mark - 快速排序
/// 两值交换
//void swap(int arr[], int a, int b) {
//    int tmp = arr[a];
//    arr[a] = arr[b];
//    arr[b] = tmp;
//}
//
//// 划分,分隔  并且返回新的枢纽元
//int partition(int arr[], int leftBound, int rightBound) {
//    int pivot = rightBound; // 枢纽元
//    // 左边指针
//    int left = leftBound;
//    for (int i = leftBound; i <= rightBound; i++) {
//        if (arr[i] < arr[pivot]) {
//            if (left != i) swap(arr, i, left);
//            left++;
//        }
//    }
//    swap(arr, left, pivot);
//    return left;
//}
//// 传入左右两个边界索引
//void quickSort(int arr[], int leftBound, int rightBound) {
//    if (leftBound >= rightBound) {
//        return;
//    }
//    // 划分, 得到新枢纽元的位置
//    int mid = partition(arr, leftBound, rightBound);
//    // 对两个分区再进行递归
//    quickSort(arr, leftBound, mid - 1);
//    quickSort(arr, mid + 1, rightBound);
//}


#pragma mark - 归并排序

//void mergeSort(int *nums, int left, int right, int *tmp);
//void insertionSort(int *nums, int left, int right);
//void mergeOfTwoSortedArray(int *nums, int left, int mid, int right, int *tmp);
//// 列表大小小于或等于该大小,将优先于使用插入排序,而不使用归并
//static const int INSERTION_SORT_THRESHOLD = 7;
//
//int *sortArray(int *nums) {
//    int length = (int) sizeof(nums) / sizeof(*nums);
//    int tmp[length];
//    mergeSort(nums, 0, length - 1, tmp);
//    return nums;
//}
//
///// 对数组 nums 的子区间[left, right]使用插入排序
///// @param nums 给定数组
///// @param left 左边界 能取到
///// @param right 右边界 能取到
//void insertionSort(int *nums, int left, int right) {
//    for (int i = left + 1; i <= right; i++) {
//        int tmp = nums[i];
//        int j = i;
//        while (j > left && nums[j - 1] > tmp) {
//            nums[j] = nums[j - 1];
//            j--;
//        }
//        nums[j] = tmp;
//    }
//}
//
///// 合并两个有序数组: 先把值复制到临时数组,再合并回去
///// @param nums nums description
///// @param left left description
///// @param mid [left, mid],[mid + 1 ,right]有序
///// @param right right description
///// @param tmp 全局使用的临时数组
//void mergeOfTwoSortedArray(int *nums, int left, int mid, int right, int *tmp) {
//
//}
//// 归并排序
//void mergeSort(int *nums, int left, int right, int *tmp) {
//    // 小区间使用插入排序
//    if (right - left <= INSERTION_SORT_THRESHOLD) {
//        insertionSort(nums, left, right);
//        return;
//    }
//    int mid = left + (right - left) / 2;
//
//    mergeSort(nums, left, mid, tmp);
//    mergeSort(nums, mid + 1, right, tmp);
//    // 如果数组的这个子区间本身有序,无需合并
//    if (nums[mid] <= nums[mid + 1]) {
//        return;
//    }
//
//}

#pragma mark - 归并排序 迭代
int min(int x, int y) {
    return x < y ? x : y;
}
int* sortArray2(int* nums, int numsSize, int* returnSize){
//    * returnSize = numsSize;
    int* a = nums;
    int* b = (int*) malloc(numsSize * sizeof(int));
    int seg, start;
    for (seg = 1; seg < numsSize; seg += seg) {
        for (start = 0; start < numsSize; start += seg + seg) {
            int low = start, mid = min(start + seg, numsSize), high = min(start + seg + seg, numsSize);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != nums) {
        int i;
        for (i = 0; i < numsSize; i++)
            b[i] = a[i];
        b = a;
    }
    // free(b);
    return a;
}

#pragma mark - 主函数
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 , 100};
    int len = (int) sizeof(arr) / sizeof(*arr);
    sortArray(arr, len);
//    insertSort(arr, len);
//    sortArray(arr, len, NULL);
//    quickSort(arr, 0, len - 1);
//    int a[] = {0,4,5,0,3,6};
//    bool is = containsDuplicate(a, 6);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("Hello, World!\n");
    return 0;
}

