//
//  LongestPalindrome.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/31.
//

#include "LongestPalindrome.h"


/// 5. 最长回文子串
/// @param s 字符串
char * longestPalindrome(char * s) {
    // 长度为 0, 或者为 1
    if (strlen(s) == 0 || strlen(s) == 1) {
        return s;
    }
    // 起始位置和回文串的长度
    int start = 0, len = 0;
    int left, right, count;
    for (int i = 0; s[i] != '\0'; i += count) {
        count = 1;
        // 初始化左右指针
        left = i - 1;
        right = i + 1;
        // 处理重复字符串
        while (s[right] != '\0' && s[i] == s[right]) {
            // 右指针右移, 数量加一
            right++;
            count++;
        }
        // 判断左指针和右指针对应的值是否相等,相等的话就继续向两边扩散
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            left--;
            right++;
        }
        // 两边扩散结束, 开始计算回文字符串的长度和内容, 长度大于之前的长度就替换之前的长度
        if (right - left - 1 > len) {
            // 因为当前 left 所指的位置是 left != right 的,所以有效的位置就是 left + 1
            start = left + 1;
            len = right - left - 1;
        }
        // 这样就进行了一遍找回文串的操作,再进行下一次, 最后得到的就是 len 最长的的那个回文串
    }
    // 在原字符串上进行截取
    s[start + len] = '\0';
    return s + start;
}
