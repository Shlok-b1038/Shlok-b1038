#include <stdio.h>

void mergeSort(int size, int *list);
void merge(int leftSize, int *left, int rightSize, int *right, int *pArray);

int main() {
    int array[] = {8, 2, 5, 3, 4, 7, 6, 1};

    mergeSort(8, array);
    // merge();
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    };
    printf("\n");

    return 0;
};

void mergeSort(int size, int *list) {
    if (size <= 1) return;

    int left = size/2;
    int right = size - left;

    int leftArray[left];
    int rightArray[right];

    for (int i = 0; i < size; i++) {
        if (i < left) leftArray[i] = list[i];
        else rightArray[i - left] = list[i];
    };

    mergeSort(left, leftArray);
    mergeSort(right, rightArray);
    merge(left, leftArray, right, rightArray, list);
};

void merge(int leftSize, int *left, int rightSize, int *right, int *list) {
    int leftCounter = 0;
    int rightCounter = 0;
    int counter = 0;
    while (leftCounter < leftSize && rightCounter < rightSize) {
        if (left[leftCounter] < right[rightCounter]) {
            list[counter] = left[leftCounter];
            leftCounter++;
            counter++;
        }
        else if (left[leftCounter] > right[rightCounter]) {
            list[counter] = right[rightCounter];
            rightCounter++;
            counter++;
        };
    };
    while (leftCounter < leftSize) {
        list[counter] = left[leftCounter];
        leftCounter++;
        counter++;
    };
    while (rightCounter < rightSize) {
        list[counter] = right[rightCounter];
        rightCounter++;
        counter++;
    };
};
