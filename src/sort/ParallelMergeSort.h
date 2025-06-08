#pragma once
#include "ISorter.h"
#include <thread>

/**
 * @brief Клас, що реалізує паралельний алгоритм сортування злиттям.
 *
 * Виконує сортування з використанням мультипоточності, розбиваючи задачу на підзадачі,
 * які виконуються паралельно до досягнення максимальної глибини розбиття.
 * Наслідує інтерфейс ISorter.
 */
class ParallelMergeSort : public ISorter {
public:
    /**
     * @brief Конструктор з параметром максимального рівня паралелізму.
     *
     * @param maxDepth Максимальна глибина рекурсії, на якій застосовується паралельність.
     * Якщо глибина більша за це значення, сортування відбувається послідовно.
     */
    explicit ParallelMergeSort(size_t maxDepth = 2) : maxDepth(maxDepth) {}

    /**
     * @brief Запуск сортування.
     *
     * Виконує паралельний merge sort над вектором даних.
     * @param data Вектор цілих чисел, який потрібно відсортувати.
     */
    void sort(std::vector<int>& data) override {
        mergeSort(data, 0, data.size() - 1, 0);
    }

private:
    size_t maxDepth; ///< Максимальна глибина рекурсії для паралельного виконання.

    /**
     * @brief Рекурсивна функція сортування злиттям з підтримкою паралелізму.
     *
     * @param data Вектор, що сортується.
     * @param left Ліва межа підмасиву.
     * @param right Права межа підмасиву.
     * @param depth Поточна глибина рекурсії.
     */
    void mergeSort(std::vector<int>& data, int left, int right, size_t depth);

    /**
     * @brief Об'єднання двох відсортованих підмасивів у один.
     *
     * @param data Вектор, що містить підмасиви.
     * @param left Ліва межа першого підмасиву.
     * @param mid Межа між двома підмасивами.
     * @param right Права межа другого підмасиву.
     */
    void merge(std::vector<int>& data, int left, int mid, int right);
};
