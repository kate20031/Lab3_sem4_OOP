#include "../src/sort/SequentialMergeSort.h"
#include "../src/sort/ParallelMergeSort.h"
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Sorting correctness") {
    std::vector<int> data = {5, 3, 8, 1, 2, 9};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};

    SequentialMergeSort seqSorter;
    ParallelMergeSort parSorter(2);

    std::vector<int> dataSeq = data;
    std::vector<int> dataPar = data;

    seqSorter.sort(dataSeq);
    parSorter.sort(dataPar);

    REQUIRE(dataSeq == expected);
    REQUIRE(dataPar == expected);
}

TEST_CASE("Empty array") {
    std::vector<int> data = {};
    std::vector<int> expected = {};

    SequentialMergeSort seqSorter;
    ParallelMergeSort parSorter(2);

    std::vector<int> dataSeq = data;
    std::vector<int> dataPar = data;

    seqSorter.sort(dataSeq);
    parSorter.sort(dataPar);

    REQUIRE(dataSeq == expected);
    REQUIRE(dataPar == expected);
}

TEST_CASE("Single element array") {
    std::vector<int> data = {42};
    std::vector<int> expected = {42};

    SequentialMergeSort seqSorter;
    ParallelMergeSort parSorter(2);

    std::vector<int> dataSeq = data;
    std::vector<int> dataPar = data;

    seqSorter.sort(dataSeq);
    parSorter.sort(dataPar);

    REQUIRE(dataSeq == expected);
    REQUIRE(dataPar == expected);
}
