#include <stdio.h>

int removeDuplicates(int* array, int numsSize) {
        // Using the 2 pointer method in order to solve the question.
    int slow = 0; // slower pointer that points in the current position
    for (int i = 0; i < numsSize; i++) {
        if (array[slow] != array[i]) {
            slow++;
            array[slow] = array[i]; // here i acts as the faster pointer comparing slower pointer and the faster one.
        };
    };

    return slow + 1; // The no. of times slow has been incremented + the first number in the array;

}

int main() {
    int array[15] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    int duplicates = removeDuplicates(array, 15);

    for (int i = 0; i < duplicates; i++) {
        printf("%d ", array[i]);
    };
    
    return 0;
};
