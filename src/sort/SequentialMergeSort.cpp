#include "SequentialMergeSort.h"

/**
 * @brief Сортує вхідний масив за допомогою алгоритму Merge Sort.
 *
 * Це послідовна (непаралельна) реалізація алгоритму.
 *
 * @param data Масив для сортування.
 */
void SequentialMergeSort::sort(std::vector<int>& data) {
    mergeSort(data, 0, data.size() - 1);
}

/**
 * @brief Рекурсивний алгоритм Merge Sort.
 *
 * Рекурсивно розбиває масив на підмасиви, сортує їх та об'єднує.
 *
 * @param data Масив для сортування.
 * @param left Лівий індекс підмасиву.
 * @param right Правий індекс підмасиву.
 */
void SequentialMergeSort::mergeSort(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

/**
 * @brief Зливає два відсортовані підмасиви в один.
 *
 * @param data Масив, що сортується.
 * @param left Лівий індекс першого підмасиву.
 * @param mid Середній індекс (остання позиція лівого підмасиву).
 * @param right Правий індекс другого підмасиву.
 */
void SequentialMergeSort::merge(std::vector<int>& data, int left, int mid, int right) {
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
