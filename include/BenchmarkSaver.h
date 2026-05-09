


#ifndef PROJEKT_1_BENCHMARKSAVER_H
#define PROJEKT_1_BENCHMARKSAVER_H
#include <string>
#include "DynamicArray.h"
#include "BinaryHeapPriorityQueue.h"
#include "UnsortedListPriorityQueue.h"
// Writes aggregated benchmark results to CSV files.
class BenchmarkSaver {
public:
    static void saveOperationResults(
        const std::string& filename,
        int sizes[],
        const DynamicArray<long long>& heapAverages,
        const DynamicArray<long long>& listAverages,
        int count
    );
};

#endif //PROJEKT_1_BENCHMARKSAVER_H
