/*************************************************************************
	> File Name: 242_有效的字母异位词.c
	> Author: GaoYu
	> Mail: 
	> Created Time: 2019年01月04日 星期五 14时57分58秒
 ************************************************************************/

#include<stdio.h>
#define BASE 125
bool isAnagram(char* s, char* t) {
    int code_s[BASE] = {0};
    for (int i = 0; s[i]; i++) {
        code_s[s[i]] += 1;
    }
    int code_t[BASE] = {0};
    for (int i = 0; t[i]; i++) {
        code_t[t[i]] += 1;
    }
    for (int i = 97; i < BASE; i++) {
        if (code_s[i] != code_t[i]) return false;
    }
    return true;
}

