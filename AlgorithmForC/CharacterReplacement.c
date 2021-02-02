//
//  CharacterReplacement.c
//  AlgorithmForC
//
//  Created by gjh on 2021/2/2.
//

#include "CharacterReplacement.h"
/// 424. 替换后的最长重复字符
int characterReplacement(char * s, int k){
    // 声明存放字母出现频数的数组
    int freq[26];
    memset(freq, 0, sizeof(freq));
    
    // 双指针
    int left = 0, right = 0;
    int len = (int)strlen(s);
    int maxFreqNum = 0;
    
    while (right < len) {
        // 将出现的字母的频数累计
        freq[s[right] - 'A']++;
        // 累计出现次数最多的频数
        maxFreqNum = fmax(maxFreqNum, freq[s[right] - 'A']);
        
        if (right - left + 1 > maxFreqNum + k) {
            freq[s[left++] - 'A']--;
        }
        right++;
    }
    
    // 窗口的大小
    return right - left;
}
