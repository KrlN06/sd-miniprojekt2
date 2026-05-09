
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

#include "BenchmarkSaver.h"

void BenchmarkSaver::saveOperationResults(
    const std::string& filename,
    int sizes[],
    const DynamicArray<long long>& heapAverages,
    const DynamicArray<long long>& listAverages,
    int count
) {
    // Keep benchmark exports in a dedicated folder.
    std::filesystem::create_directory("results");
    std::ofstream file("results/" + filename);

    if (!file.is_open()) {
        std::cout << "Cannot open file: results/" << filename << std::endl;
        return;
    }

    file << "Size,BinaryHeap,UnsortedList\n";

    for (int i = 0; i < count; i++) {
        file << sizes[i] << ","
             << heapAverages[i] << ","
             << listAverages[i] << "\n";
    }

    file.close();

    std::cout << "Results saved to results/" << filename << std::endl;
}
