/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月08日 星期四 18时51分16秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
//第一种方法
int lengthOfLongestSubstring(char* s) {
    int pos[256], len = 0;
    memset(pos, -1, sizeof(pos));
    for (int i = 0; s[i]; i++) {
        len += 1;
        if (i - pos[s[i]] < len) len = i - pos[s[i]];
        pos[s[i]] = i;
        if (len > ans) ans = len;
    }
    return ans;
}
*/

//第二种方法　：　二分查找
int check (char *s, int len) {
    if (len == 0) return 1;
    int nums[256] = {0};//每一种字符出现的次数
    int cnt = 0;//不同元素的数量
    for (int i = 0; s[i]; i++) {
        nums[s[i]] += 1;
        cnt += (nums[s[i]] == 1);
        if (i >= len) {
            nums[s[i - len]]--;
            cnt -= (nums[s[i - len]] == 0); //一个字符从窗口内部消失 
        }
        if (cnt == len) return 1;
    }
    return 0;
}
 
int lengthOfLongestSubstring(char* s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}


//测试的主函数
int main () {
    char s[100] = "abcabcdabc";
    int m = lengthOfLongestSubstring(s);
    printf ("%d\n", m);
}
