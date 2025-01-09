#include <iostream>

void merge(int arrA[], int arrB[], int sizeA, int sizeB) {
    int end = sizeA + sizeB - 1;
    int pointerA = sizeA - 1;
    int pointerB = sizeB - 1;

    for (int i = end; i >= 0; i--) {
        if (pointerB < 0) {
            break;
        }
        if (pointerA >= 0 && arrA[pointerA] > arrB[pointerB]) {
            arrA[i] = arrA[pointerA];
            pointerA--;
        } else {
            arrA[i] = arrB[pointerB];
            pointerB--;
        }
    }
}

void runTest(int arrA[], int arrB[], int sizeA, int sizeB, const char* testName) {
    merge(arrA, arrB, sizeA, sizeB);
    
    std::cout << testName << ": ";
    for (int i = 0; i < sizeA + sizeB; i++) {
        std::cout << arrA[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arrA1[10] = {1, 3, 5, 7, 9};
    int arrB1[] = {2, 4, 6, 8, 10};
    runTest(arrA1, arrB1, 5, 5, "Test 1 (Alternating numbers)");

    int arrA2[8] = {1, 2, 3, 4};
    int arrB2[] = {5, 6, 7, 8};
    runTest(arrA2, arrB2, 4, 4, "Test 2 (Already sorted)");

    int arrA3[7] = {5, 10, 15};
    int arrB3[] = {1, 2, 3, 4};
    runTest(arrA3, arrB3, 3, 4, "Test 3 (Second array smaller)");

    int arrA4[6] = {1};
    int arrB4[] = {2, 3, 4, 5, 6};
    runTest(arrA4, arrB4, 1, 5, "Test 4 (First array with one element)");

    return 0;
}
