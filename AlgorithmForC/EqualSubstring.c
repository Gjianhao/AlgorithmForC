//
//  EqualSubstring.c
//  AlgorithmForC
//
//  Created by gjh on 2021/2/5.
//

#include "EqualSubstring.h"


/// 1208. 尽可能使字符串相等
/// @param s 给你两个长度相同的字符串，s 和 t。
/// @param t 将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。
/// @param maxCost 用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。
int equalSubstring(char * s, char * t, int maxCost){
    int len = (int)strlen(s);
    // 总开销
    int cost = 0, maxLen = 0;
    
    for (int i = 0; i < len; i++) {
        cost += abs(s[i] - t[i]);
        if (cost <= maxCost) {
            maxLen++;
        } else {
            cost -= abs(s[i - maxLen] - t[i - maxLen]);
        }
    }
    return maxLen;
}
