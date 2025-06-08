#pragma once
#include "ISorter.h"

/**
 * @brief Клас, що реалізує послідовний алгоритм сортування злиттям.
 *
 * Наслідує інтерфейс ISorter.
 * Виконує класичне сортування злиттям без паралелізації.
 */
class SequentialMergeSort : public ISorter {
public:
    /**
     * @brief Запуск сортування.
     *
     * Сортує вектор цілих чисел за допомогою послідовного алгоритму злиття.
     * @param data Вектор цілих чисел для сортування.
     */
    void sort(std::vector<int>& data) override;

private:
    /**
     * @brief Рекурсивна функція сортування злиттям.
     *
     * Розбиває масив на підмасиви та сортує їх.
     * @param data Вектор для сортування.
     * @param left Ліва межа підмасиву.
     * @param right Права межа підмасиву.
     */
    void mergeSort(std::vector<int>& data, int left, int right);

    /**
     * @brief Об’єднання двох відсортованих підмасивів у один.
     *
     * @param data Вектор з підмасивами для об'єднання.
     * @param left Ліва межа першого підмасиву.
     * @param mid Межа між двома підмасивами.
     * @param right Права межа другого підмасиву.
     */
    void merge(std::vector<int>& data, int left, int mid, int right);
};
