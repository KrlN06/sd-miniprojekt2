
#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H
#include "DynamicArray.h"
#include "BinaryHeapPriorityQueue.h"
#include "UnsortedListPriorityQueue.h"

// Stores raw timings and per-size averages for the full benchmark suite.
class Benchmark {
public:
    // Runs all benchmarks for all structures
    void run();
    const static int SIZE = 50;

private:
    // The same size schedule is reused for every measured operation.
    int sizes[SIZE] = {
        5000, 8000, 10000, 12000, 14000,
        16000, 18000, 20000, 24000, 28000,
        32000, 36000, 40000, 44000, 48000,
        52000, 56000, 60000, 64000, 68000,
        72000, 76000, 80000, 84000, 88000,
        92000, 96000, 100000, 104000, 108000,
        112000, 116000, 120000, 124000, 128000,
        132000, 136000, 140000, 144000, 148000,
        152000, 156000, 160000, 165000, 170000,
        175000, 180000, 185000, 190000, 200000
    };

    // Dynamic Array results
    DynamicArray<long long> heapInsertResults;
    DynamicArray<long long> heapExtractMaxResults;
    DynamicArray<long long> heapPeekResults;
    DynamicArray<long long> heapModifyKeyResults;
    DynamicArray<long long> heapSizeResults;

    // Tablice docelowe ze średnimi (zapisywane do plików CSV na samym końcu)
    DynamicArray<long long> heapInsertAverages;
    DynamicArray<long long> heapExtractMaxAverages;
    DynamicArray<long long> heapPeekAverages;
    DynamicArray<long long> heapModifyKeyAverages;
    DynamicArray<long long> heapSizeAverages;


   
    
    // Tablice pomocnicze do zbierania wyników dla obecnego rozmiaru (czyszczone co pętlę)
    DynamicArray<long long> listInsertResults;
    DynamicArray<long long> listExtractMaxResults;
    DynamicArray<long long> listPeekResults;
    DynamicArray<long long> listModifyKeyResults;
    DynamicArray<long long> listSizeResults;

    // Tablice docelowe ze średnimi (zapisywane do plików CSV na samym końcu)
    DynamicArray<long long> listInsertAverages;
    DynamicArray<long long> listExtractMaxAverages;
    DynamicArray<long long> listPeekAverages;
    DynamicArray<long long> listModifyKeyAverages;
    DynamicArray<long long> listSizeAverages;  
    // Runs benchmark for dynamic array
    

    // Runs benchmark for unsorted list
    void benchmarkUnsortedList(const UnsortedListPriorityQueue& originalList,
                               const DynamicArray<int>& data);

    // Runs benchmark for binary heap
    void benchmarkBinaryHeap(const BinaryHeapPriorityQueue& originalList,
                              const DynamicArray<int>& data);

    // Generates random data of given size
    DynamicArray<int> generateRandomData(int size);

    // Calculates average from collected results
    long long calculateAverage(const DynamicArray<long long>& results);

    // Displays results on screen
    void displayResults(int size);
};
#endif //PROJEKT_1_BENCHMARK_H
