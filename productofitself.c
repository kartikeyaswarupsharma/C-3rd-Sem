#include <stdio.h>

void productExceptSelf(int* nums, int numsSize, int* result) {
    // Initialize the result array to store the products to the left of each index
    result[0] = 1;

    // Calculate the products to the left of each index and store in the result array
    int leftProduct = 1;
    for (int i = 1; i < numsSize; ++i) {
        result[i] = leftProduct * nums[i - 1];
        leftProduct *= nums[i - 1];
    }

    // Calculate the products to the right of each index and update the result array
    int rightProduct = 1;
    for (int i = numsSize - 2; i >= 0; --i) {
        result[i] *= rightProduct * nums[i + 1];
        rightProduct *= nums[i + 1];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result[numsSize];
    productExceptSelf(nums, numsSize, result);

    // Print the result array
    printf("[");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d", result[i]);
        if (i < numsSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
