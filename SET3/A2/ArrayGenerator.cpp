#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>


using namespace std;

class ArrayGenerator {
public:
    static vector<int> generateRandomArray(int size) {
        vector<int> array;
        mt19937 mt{ std::random_device{}() };
        uniform_int_distribution<int> dist(0, 6000);
        for (int i = 0; i < size; ++i) {
            array.push_back(dist(mt));
        }
        return array;
    }

    static vector<int> generateReverseArray(int size) {
        vector<int> array = generateRandomArray(10000);
        sort(array.begin(), array.end());
        reverse(array.begin(), array.end());
        return vector<int>(array.begin(), array.begin() + size);
    }

    static vector<int> generateNearlySortedArray(int size) {
        vector<int> array = generateRandomArray(10000);
        sort(array.begin(), array.end());
        int n = min(10, size - 1);
        for (int i = 0; i < n; ++i) {
            int index1 = rand() % size;
            int index2 = rand() % size;
            swap(array[index1], array[index2]);
        }
        return vector<int>(array.begin(), array.begin() + size);
    }

    static vector<vector<int>> group1() {
        vector<vector<int>> testArrays;
        for (int size = 500; size <= 10000; size += 100) {
            testArrays.push_back(generateRandomArray(size));
        }
        return testArrays;
    }
    
    static vector<vector<int>> group2() {
        vector<vector<int>> testArrays;
        for (int size = 500; size <= 10000; size += 100) {
            testArrays.push_back(generateReverseArray(size));
        }
        return testArrays;
    }
    
    static vector<vector<int>> group3() {
        vector<vector<int>> testArrays;
        for (int size = 500; size <= 10000; size += 100) {
            testArrays.push_back(generateNearlySortedArray(size));
        }
        return testArrays;
    }
};

int main() {
    //auto testArrays1 = ArrayGenerator::group1(); // Массивы, которые заполнены случайными значениями в некотором диапазоне.
    //auto testArrays2 = ArrayGenerator::group2(); // Массивы, которые отсортированы в обратном порядке по невозрастанию.
    //auto testArrays3 = ArrayGenerator::group3(); // Массивы, которые <<почти>> отсортированы. Их можно получить, 
                                                   // обменяв местами небольшое количество пар элементов в полностью отсортированном массиве.
    return 0;
}