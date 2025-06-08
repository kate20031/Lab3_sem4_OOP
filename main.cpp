#include "src/sort/SequentialMergeSort.h"
#include "src/sort/ParallelMergeSort.h"
#include "src/utils/Timer.h"
#include <iostream>
#include <random>

int main() {
    std::vector<int> data(1'000'000);
    std::mt19937 rng(42);
    std::uniform_int_distribution<> dist(0, 1'000'000);

    for (auto& x : data) {
        x = dist(rng);
    }

    SequentialMergeSort seqSorter;
    ParallelMergeSort parSorter(4);

    auto dataCopy = data;

    Timer timer;
    seqSorter.sort(data);
    double seqTime = timer.elapsed();

    timer.reset();
    parSorter.sort(dataCopy);
    double parTime = timer.elapsed();

    std::cout << "Sequential time: " << seqTime << " ms\n";
    std::cout << "Parallel time: " << parTime << " ms\n";

    return 0;
}
