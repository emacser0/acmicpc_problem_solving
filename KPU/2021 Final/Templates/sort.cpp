#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <functional>

int swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int left, int right, int* arr) {
    int pivot = arr[left];
    int less = left;
    int more = right + 1;

    if (left < right) {
        do {
            do
                less++;
            while (less <= right && arr[less] < pivot);

            do
                more--;
            while (more >= left && arr[more] > pivot);

            if (less < more)
                swap(&arr[less], &arr[more]);

        } while (less < more);
        swap(&arr[left], &arr[more]);

        quickSort(left, more - 1, arr);
        quickSort(more + 1, right, arr);
    }

}

int mergeTempArray[999999];

void merge(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    int L = left;
    int R = mid + 1;

    int k = left;

    while (L <= mid && R <= right)
    {
        mergeTempArray[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
    }        

    if (L > mid)
    {
        for (int i = R; i <= right; i++)
        {
            mergeTempArray[k++] = arr[i];
        }
    }        
    else
    {
        for (int i = L; i <= mid; i++)
        {
            mergeTempArray[k++] = arr[i];
        }        
    }     

    for (int i = left; i <= right; i++)
    {
        arr[i] = mergeTempArray[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left == right)
    {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, right);
}

void selectionSort(int arr[], int size) {
    int minIndex;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[i], &arr[minIndex]);
    }
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = size - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}