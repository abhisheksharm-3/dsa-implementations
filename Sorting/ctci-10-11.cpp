#include <iostream>
using namespace std;
void peaksAndValleys(int arr[], int size) {
    for (int i = 1; i < size; i += 2) {
        int maxIndex = i;
        if (i - 1 >= 0 && arr[i - 1] > arr[maxIndex]) {
            maxIndex = i - 1;
        }
        if (i + 1 < size && arr[i + 1] > arr[maxIndex]) {
            maxIndex = i + 1;
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {5, 3, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    peaksAndValleys(arr, size);
    
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}