/*************************************************************************
	> File Name: 205_同构字符串未完.c
	> Author: GaoYu
	> Mail: 
	> Created Time: 2019年01月04日 星期五 14时27分46秒
 ************************************************************************/

#include<stdio.h>
int isIsomorphic(char* s, char* t) {
    int a[256] = {0}, b[256] = {0};
    int flag = 1;
    for (int i = 0; s[i] && flag; i++) {
        if (a[s[i]] == 0 && b[t[i]] == 0) {
            a[s[i]] = t[i];
            b[t[i]] = s[i];
        } else if (a[s[i]] == t[i]) flag = 0;
    }
    return flag;
}

int main () {
    char s[] = {0}, t[] = {0};
    scanf ("%s%s", s, t);
    int a = isIsomorphic(s, t);
    printf ("%d\n", a);
    return 0;
}
