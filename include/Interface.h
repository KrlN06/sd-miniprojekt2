

#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include "BinaryHeapPriorityQueue.h"
#include "UnsortedListPriorityQueue.h"
#include "Benchmark.h"

class Interface {
public:
    Interface();
    void run();

private:
    
    BinaryHeapPriorityQueue binaryHeap;
    UnsortedListPriorityQueue unsortedList;
    
    
    bool firstRun;

    void displayMainMenu();
    void handleMainMenuChoice(int choice);
    
    void displayStructureMenu(const std::string& structureName);
    void handleStructureMenuChoice(int choice, int structureType);
    
   
    void handleInsertOperation(int structureType);
    void handleExtractMaxOperation(int structureType);
    void handlePeekOperation(int structureType);
    void handleModifyKeyOperation(int structureType);
    void handleSizeOperation(int structureType);
    
    void handleGenerateRandomOperation(int structureType);
    void handleLoadFromFileOperation(int structureType);
    void handleClearOperation(int structureType);
    
    void displayBenchmarkMenu();
    void handleBenchmarkMenuChoice(int choice);
    void runFullBenchmark();
    
    void clearScreen();
    void waitForUser();
};

#endif // INTERFACE_H