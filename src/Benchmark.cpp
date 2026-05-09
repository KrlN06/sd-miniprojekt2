

#include "Benchmark.h"
#include <cstdlib>
#include <iostream>

#include "Timer.h"
#include "Random.h"
#include "BenchmarkSaver.h"
#include "BinaryHeapPriorityQueue.h"
#include "UnsortedListPriorityQueue.h"
#include "DynamicArray.h"
void Benchmark::run() {

    // Test all configured structure sizes
    for (int size : sizes) {

        // Repeat benchmark multiple times for stable average results
        for (int i = 0; i < 100; i++) {

            // Generate common random dataset
            DynamicArray<int> data = generateRandomData(size);
            DynamicArray<int> priorities = generateRandomData(size);

            // Create fresh empty structures----------------------------------
            BinaryHeapPriorityQueue binaryHeap;
            UnsortedListPriorityQueue unsortedList;
            
            //------------------------------------------------------------------

            // Fill all structures with identical data------------------------
            for (int j = 0; j < data.getSize(); j++) {
                binaryHeap.insert(data[j], priorities[j]);
                unsortedList.insert(data[j], priorities[j]);
            }
            //------------------------------------------------------------------

            // Run benchmark operations--------------------------------------
            
            benchmarkUnsortedList(unsortedList, data);
            benchmarkBinaryHeap(binaryHeap, data);
        }
        // Display average results for current structure size
        displayResults(size);

        // Store averages for CSV saving for binary heap
        
        heapInsertAverages.push_back(calculateAverage(heapInsertResults));
        heapExtractMaxAverages.push_back(calculateAverage(heapExtractMaxResults));
        heapPeekAverages.push_back(calculateAverage(heapPeekResults));
        heapModifyKeyAverages.push_back(calculateAverage(heapModifyKeyResults));
        heapSizeAverages.push_back(calculateAverage(heapSizeResults));

        // Store averages for CSV saving for unsorted list
        listInsertAverages.push_back(calculateAverage(listInsertResults));
        listExtractMaxAverages.push_back(calculateAverage(listExtractMaxResults));
        listPeekAverages.push_back(calculateAverage(listPeekResults));
        listModifyKeyAverages.push_back(calculateAverage(listModifyKeyResults));
        listSizeAverages.push_back(calculateAverage(listSizeResults));

        // Clear collected results before testing next size
        heapInsertResults.clear();
        heapExtractMaxResults.clear();
        heapPeekResults.clear();
        heapModifyKeyResults.clear();
        heapSizeResults.clear();

        listInsertResults.clear();
        listExtractMaxResults.clear();
        listPeekResults.clear();
        listModifyKeyResults.clear();
        listSizeResults.clear();

    } 

    // Export one CSV file per operation after all averages are ready.
    BenchmarkSaver::saveOperationResults(
        "insert.csv",
        sizes,
        heapInsertAverages,
        listInsertAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "extractMax.csv",
        sizes,
        heapExtractMaxAverages,
        listExtractMaxAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "peek.csv",
        sizes,
        heapPeekAverages,
        listPeekAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "modifyKey.csv",
        sizes,
        heapModifyKeyAverages,
        listModifyKeyAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "size.csv",
        sizes,
        heapSizeAverages,
        listSizeAverages,
        SIZE
    );
}


//========================================================================
// BINARY HEAP BENCHMARKS
//========================================================================

void Benchmark::benchmarkBinaryHeap(const BinaryHeapPriorityQueue& originalHeap, const DynamicArray<int>& data) {
    Timer timer;
    const int repetitions = 1;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement


    {
    // Insert benchmark-----------------------------------------------
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            BinaryHeapPriorityQueue heap = originalHeap;
            int value = Random::generateRandomInt(0, 99999);
            int priority = Random::generateRandomInt(0, 99999);
            timer.start();
            heap.insert(value, priority);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        heapInsertResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
    // extractMax benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            BinaryHeapPriorityQueue heap = originalHeap;
            timer.start();
            heap.extractMax();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        heapExtractMaxResults.push_back(totalTime / repetitions);
    }
    // peek benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            BinaryHeapPriorityQueue heap = originalHeap;
            timer.start();
            heap.peek();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        heapPeekResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
   // modifyKey benchmark-----------------------------------------------
{
    long long totalTime = 0;
    for (int i = 0; i < repetitions; i++) {
        BinaryHeapPriorityQueue heap = originalHeap; 
        
        
        int randomIndex = Random::generateRandomInt(0, data.getSize() - 1);
        
        int value = data[randomIndex]; 
        
        int priority = Random::generateRandomInt(0, 99999); 
        
        timer.start();
        heap.modifyKey(value, priority);
        timer.stop();
        totalTime += timer.getElapsedTime();
    }
    heapModifyKeyResults.push_back(totalTime / repetitions);
}
    
    //------------------------------------------------------------------
    // size benchmark----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            BinaryHeapPriorityQueue heap = originalHeap;
            timer.start();
            heap.size();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        heapSizeResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
    
}


//========================================================================
// UNSORTED LIST BENCHMARKS
//========================================================================

void Benchmark::benchmarkUnsortedList(const UnsortedListPriorityQueue& originalList, const DynamicArray<int> &data) {
    Timer timer;
    const int repetitions = 1;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    {
    // Insert benchmark-----------------------------------------------
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            UnsortedListPriorityQueue list = originalList;
            int value = Random::generateRandomInt(0, 99999);
            int priority = Random::generateRandomInt(0, 99999);
            timer.start();
            list.insert(value, priority);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        listInsertResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
    // extractMax benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            UnsortedListPriorityQueue list = originalList;
            timer.start();
            list.extractMax();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        listExtractMaxResults.push_back(totalTime / repetitions);
    }
    // peek benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            UnsortedListPriorityQueue list = originalList;
            timer.start();
            list.peek();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        listPeekResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
    // modifyKey benchmark-----------------------------------------------
    {
    long long totalTime = 0;
    for (int i = 0; i < repetitions; i++) {
        UnsortedListPriorityQueue list = originalList; 
        
        
        int randomIndex = Random::generateRandomInt(0, data.getSize() - 1);
        
        int value = data[randomIndex]; 
        
        int priority = Random::generateRandomInt(0, 99999); 
        
        timer.start();
        list.modifyKey(value, priority);
        timer.stop();
        totalTime += timer.getElapsedTime();
    }
    listModifyKeyResults.push_back(totalTime / repetitions);
}
    //------------------------------------------------------------------
    //------------------------------------------------------------------
    // size benchmark----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            UnsortedListPriorityQueue list = originalList;
            timer.start();
            list.size();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        listSizeResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
}






DynamicArray<int> Benchmark::generateRandomData(int size) {
    DynamicArray<int> data;

    // Fill the structure with random integer values
    for (int i = 0; i < size; i++) {
        data.push_back(Random::generateRandomInt(0, 99999));
    }

    return data;
}


long long Benchmark::calculateAverage(const DynamicArray<long long>& results) {
    // Sum all measured execution times stored in the results structure.
    // Then divide the total time by the number of measurements to get the average.

    if (results.isEmpty()) {
        return 0;
    }

    // Sum all measured times
    long long sum = 0;

    for (int i = 0; i < results.getSize(); i++) {
        sum += results[i];
    }

    // Return average execution time
    return sum / results.getSize();
}


void Benchmark::displayResults(int size) {
    // Display average benchmark results for current size
    std::cout << "Size: " << size << std::endl;
    // Binary Heap results----------------------------------------
    std::cout << "\nBinary Heap" << std::endl;
    std::cout << "Insert: " << calculateAverage(heapInsertResults) << " ns" << std::endl;
    std::cout << "Extract Max: " << calculateAverage(heapExtractMaxResults) << " ns" << std::endl;
    std::cout << "Peek: " << calculateAverage(heapPeekResults) << " ns" << std::endl;
    std::cout << "Modify Key: " << calculateAverage(heapModifyKeyResults) << " ns" << std::endl;
    std::cout << "Return size: " << calculateAverage(heapSizeResults) << " ns" << std::endl;

    // Unsorted List results----------------------------------------
    std::cout << "\nUnsorted List" << std::endl;
    std::cout << "Insert: " << calculateAverage(listInsertResults) << " ns" << std::endl;
    std::cout << "Extract Max: " << calculateAverage(listExtractMaxResults) << " ns" << std::endl;
    std::cout << "Peek: " << calculateAverage(listPeekResults) << " ns" << std::endl;
    std::cout << "Modify Key: " << calculateAverage(listModifyKeyResults) << " ns" << std::endl;
    std::cout << "Return size: " << calculateAverage(listSizeResults) << " ns" << std::endl;
    
}
