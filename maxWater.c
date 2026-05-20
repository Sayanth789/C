#include <stdio.h>

int maxArea(int *height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;

        if (area > max) {
            max = area;
        }

        // move pointer of smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int max_area = maxArea(height, heightSize);

    printf("max area is: %d\n", max_area);

    return 0;
}