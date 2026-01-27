#include <stdio.h>

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countingSort(int array[], int size, int place) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int digit = (array[i] / place) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int array[], int size) {
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);

    radixSort(array, n);
    printArray(array, n);

    return 0;
}
