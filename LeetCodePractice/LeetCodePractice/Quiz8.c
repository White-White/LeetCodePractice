/*
 合并两个有序数组
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 */


#include <stdio.h>

//解法1
int insert(int num, int* toArray, int arrayLength) {
    
    int indexToInsert = arrayLength;
    
    for (int k = 0; k < arrayLength; k++) {
        if (num <= *(toArray+k)) {
            indexToInsert = k;
            break;
        }
    }
    
    //向后移动
    for (int j = arrayLength; j > indexToInsert; j--) {
        *(toArray+j) = *(toArray+j-1);
    }
    
    *(toArray+indexToInsert) = num;
    
    return indexToInsert;
}

void merge(int* nums1, int m, int* nums2, int n) {
    
    int startIndex = 0;
    int lengthNums1 = m;
    
    for (int k = 0; k < n; k++) {
        startIndex += insert(*(nums2+k), nums1+startIndex, lengthNums1 - startIndex);
        lengthNums1 += 1;
    }
}

//解法2 因为num1的空间可以保证 所以可以将两个数组从num1 m+n-1的位置开始从大到小合并

void merge2(int* nums1, int m, int* nums2, int n) {
    
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    
    while (k >= 0) {
        if (i < 0) {
            nums1[k] = nums2[j];
            j--;
        } else if (j < 0) {
            nums1[k] = nums1[i];
            i--;
        } else {
            int numFrom1 =nums1[i];
            int numFrom2 =nums2[j];
            
            if (numFrom1 > numFrom2) {
                nums1[k] = numFrom1;
                i--;
            } else {
                nums1[k] = numFrom2;
                j--;
            }
        }
        k--;
    }
}



















