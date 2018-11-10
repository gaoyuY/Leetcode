/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月09日 星期五 23时38分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search (int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
    //确保nums1Size < nums2Size
    if (nums1Size > nums2Size) return binary_search (nums2, nums2Size, nums1, nums1Size, k);
    if (nums1Size == 0) return nums2[k - 1];
    if(k == 1) return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    //递归过程
    int i = nums1Size < k / 2 ? nums1Size : k / 2;
    int j = nums2Size < k / 2 ? nums2Size : k / 2;
    if (nums1[i - 1] > nums2[j - 1])  return binary_search (nums1, nums1Size, nums2 + j, nums2Size - j, k - j);
    
    else return binary_search (nums1 + i, nums1Size - i, nums2, nums2Size, k - i);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //为总长度的一半
    int l = (nums1Size + nums2Size + 1) / 2;
    int r = (nums1Size + nums2Size + 2) / 2;
    return (binary_search (nums1, nums1Size, nums2, nums2Size, l) + binary_search(nums1, nums1Size,nums2,nums2Size, r)) / 2.0;
}


int main () {
    int n, m;
    int nums1[100], nums2[100];
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &nums1[i]);
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &nums2[i]);
    }
    double z = findMedianSortedArrays(nums1, n, nums2, m);
    printf ("%.1lf\n", z);
}
