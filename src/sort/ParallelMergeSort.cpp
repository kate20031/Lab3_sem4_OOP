#include "ParallelMergeSort.h"

/**
 * @brief Паралельна версія merge sort.
 *
 * Рекурсивно сортує підмасиви за допомогою алгоритму Merge Sort.
 * При досягненні заданої глибини рекурсії використовує потоки для паралельної обробки підмасивів.
 *
 * @param data Масив для сортування.
 * @param left Лівий індекс підмасиву.
 * @param right Правий індекс підмасиву.
 * @param depth Поточна глибина рекурсії (для обмеження кількості потоків).
 */
void ParallelMergeSort::mergeSort(std::vector<int>& data, int left, int right, size_t depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        if (depth < maxDepth) {
            std::thread leftThread(&ParallelMergeSort::mergeSort, this, std::ref(data), left, mid, depth + 1);
            std::thread rightThread(&ParallelMergeSort::mergeSort, this, std::ref(data), mid + 1, right, depth + 1);

            leftThread.join();
            rightThread.join();
        } else {
            mergeSort(data, left, mid, depth + 1);
            mergeSort(data, mid + 1, right, depth + 1);
        }

        merge(data, left, mid, right);
    }
}

/**
 * @brief Зливає два відсортовані підмасиви в один.
 *
 * Використовується під час виконання алгоритму merge sort для об'єднання результатів рекурсивних викликів.
 *
 * @param data Масив, що сортується.
 * @param left Лівий індекс першого підмасиву.
 * @param mid Середній індекс (остання позиція лівого підмасиву).
 * @param right Правий індекс другого підмасиву.
 */
void ParallelMergeSort::merge(std::vector<int>& data, int left, int mid, int right) {
    std::vector<int> leftVec(data.begin() + left, data.begin() + mid + 1);
    std::vector<int> rightVec(data.begin() + mid + 1, data.begin() + right + 1);

    size_t i = 0, j = 0;
    int k = left;

    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            data[k++] = leftVec[i++];
        } else {
            data[k++] = rightVec[j++];
        }
    }

    while (i < leftVec.size()) {
        data[k++] = leftVec[i++];
    }

    while (j < rightVec.size()) {
        data[k++] = rightVec[j++];
    }
}
