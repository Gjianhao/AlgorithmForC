//
//  LongestCommonPrefix.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/30.
//

#include "LongestCommonPrefix.h"


/// 14. 最长公共前缀
/// @param strs strs
/// @param strsSize strsSize
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    // 拿出第一个字符串,做循环, 第一个字符串的第一个字符开始
    for (int j = 0; j < strlen(*strs); j++) {
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}
