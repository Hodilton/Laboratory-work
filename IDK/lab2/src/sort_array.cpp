#include <iostream>
#include <thread>

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;

    int anchor = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= anchor) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    int anchorIndex = i + 1;

    quickSort(arr, start, anchorIndex - 1);
    quickSort(arr, anchorIndex + 1, end);
}

void printArray(int arr[], int size, const std::string& message) {
    std::cout << message;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 10;
    int array[size] = {5, 34, 57, 86, 3, 87, 43, 25, 11, 14};

    printArray(array, size, "Source array: ");

    const int mid = size / 2;

    std::thread thread1(quickSort, array, 0, mid - 1);
    std::thread thread2(quickSort, array, mid, size - 1);

    thread1.join();
    thread2.join();

    printArray(array, size, "Result array: ");

    return 0;
}