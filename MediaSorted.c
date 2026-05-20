#include <stdio.h>
#include <limits.h>


double findMedianSortedArrays(int* nums1, int n, int* nums2, int m) {

    if (n > m) {
        return findMedianSortedArrays(nums2, m, nums1, n);
    }

    int imin = 0, imax = n;
    int halfLen = (m + n + 1) / 2;

    while (imin <= imax) {

        int i = (imin + imax) / 2;
        int j = halfLen - i;

        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == n) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == m) ? INT_MAX : nums2[j];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {

            if ((m + n) % 2 == 0) {
                int leftMax = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
                int rightMin = (minRight1 < minRight2) ? minRight1 : minRight2;
                return (leftMax + rightMin) / 2.0;
            } else {
                int leftMax = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
                return leftMax;
            }

        } else if (maxLeft1 > minRight2) {
            imax = i - 1;
        } else {
            imin = i + 1;
        }
    }

    return 0.0;
}


int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    
    int n = sizeof(nums1) / sizeof(nums1[0]);
    int m = sizeof(nums2) / sizeof(nums2[0]);
    
    double median = findMedianSortedArrays(nums1, n, nums2, m);
    printf("Median is: %f\n", median);  // expected 2.0
    
    // another test
    int nums3[] = {1, 2};
    int nums4[] = {3, 4, 5};
    
    n = sizeof(nums3) / sizeof(nums3[0]);
    m = sizeof(nums4) / sizeof(nums4[0]);
    
    median = findMedianSortedArrays(nums3, n, nums4, m);
    printf("Median is: %f\n", median);  // expected output 3
    
    return 0;
}