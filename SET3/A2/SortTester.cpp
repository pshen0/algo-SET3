#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <sstream>


using namespace std;
 

/* Класс содержит реализацию MergeSort и HybridSort, а так же функции, которые измеряют 
время исполнения сортировок: testMergeSort и testHybridSort. */

class SortTester {
public:
    
    static void insertionSort(vector<int>& array, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            int key = array[i];
            int j = i - 1;
            while (j >= left && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
     
    static void merge(vector<int>& array, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
     
        vector<int> leftArray(leftSize);
        vector<int> rightArray(rightSize);
     
        for (int i = 0; i < leftSize; ++i) {
            leftArray[i] = array[left + i];
        }
        for (int i = 0; i < rightSize; ++i) {
            rightArray[i] = array[mid + 1 + i];
        }
     
        int i = 0, j = 0, k = left;
     
        while (i < leftSize && j < rightSize) {
            if (leftArray[i] <= rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }
     
        while (i < leftSize) {
            array[k] = leftArray[i];
            i++;
            k++;
        }
     
        while (j < rightSize) {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }
     
    static void hybridSort(vector<int>& array, int left, int right) {
        if (right - left + 1 <= 15) {
            insertionSort(array, left, right);
        } else {
            int mid = left + (right - left) / 2;
            hybridSort(array, left, mid);
            hybridSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
    
    static void mergeSort(vector<int>& array, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
    
    static int64_t testMergeSort(vector<int>& array) {
        auto start = chrono::high_resolution_clock::now();
        mergeSort(array, 0, array.size() - 1);
        auto elapsed = chrono::high_resolution_clock::now() - start;
        int64_t msec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
        return msec;
    }

    static int64_t testHybridSort(vector<int>& array) {
        auto start = chrono::high_resolution_clock::now();
        hybridSort(array, 0, array.size() - 1);
        auto elapsed = chrono::high_resolution_clock::now() - start;
        int64_t msec = chrono::duration_cast<chrono::microseconds>(elapsed).count();
        return msec;
    }
};