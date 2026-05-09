

#include "Interface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>

Interface::Interface() : firstRun(true) {
    
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Interface::clearScreen() {
#ifdef _WIN32
    system("cls");
#elif __APPLE__ || __linux__
    for (int i = 0; i < 50; i++) {
        std::cout << '\n';
    }
#endif
}

void Interface::waitForUser() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Interface::run() {
    int choice = 0;
    while (true) {
        clearScreen();
        displayMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            waitForUser();
            continue;
        }

        handleMainMenuChoice(choice);
    }
}

void Interface::displayMainMenu() {
    if (firstRun) {
        std::cout << "PROJECT DATA STRUCTURES - PRIORITY QUEUES\n"
                  << "KAROL NALEPA MICHAŁ MARSZAŁEK\n\n";
        firstRun = false;
    }
    std::cout << "Select mode:\n"
              << "Binary Heap Priority Queue   [1]\n"
              << "Unsorted List Priority Queue [2]\n"
              << "Benchmark                    [3]\n"
              << "Quit                         [4]\n"
              << "Your choice: ";
}

void Interface::handleMainMenuChoice(int choice) {
    switch (choice) {
        case 1:
            displayStructureMenu("BINARY HEAP PRIORITY QUEUE");
            break;
        case 2:
            displayStructureMenu("UNSORTED LIST PRIORITY QUEUE");
            break;
        case 3:
            displayBenchmarkMenu();
            break;
        case 4:
            clearScreen();
            std::cout << "Exiting program. Goodbye!\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForUser();
    }
}

void Interface::displayStructureMenu(const std::string& structureName) {
    int choice = 0;
    int structureType = 0;

    if (structureName == "BINARY HEAP PRIORITY QUEUE") structureType = 1;
    else if (structureName == "UNSORTED LIST PRIORITY QUEUE") structureType = 2;

    while (true) {
        clearScreen();
        std::cout << "--- " << structureName << " MENU ---\n"
                  << "Select operation:\n"
                  << "Insert element            [1]\n"
                  << "Extract Max               [2]\n"
                  << "Peek (Show Max)           [3]\n"
                  << "Modify Key                [4]\n"
                  << "Show size                 [5]\n"
                  << "Generate random structure [6]\n"
                  << "Load structure from file  [7]\n"
                  << "Clear structure           [8]\n"
                  << "Return to main menu       [9]\n"
                  << "Your choice: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            waitForUser();
            continue;
        }

        if (choice == 9) break;
        handleStructureMenuChoice(choice, structureType);
    }
}

void Interface::handleStructureMenuChoice(int choice, int structureType) {
    switch (choice) {
        case 1:
            handleInsertOperation(structureType);
            waitForUser();
            break;
        case 2:
            handleExtractMaxOperation(structureType);
            waitForUser();
            break;
        case 3:
            handlePeekOperation(structureType);
            waitForUser();
            break;
        case 4:
            handleModifyKeyOperation(structureType);
            waitForUser();
            break;
        case 5:
            handleSizeOperation(structureType);
            waitForUser();
            break;
        case 6:
            handleGenerateRandomOperation(structureType);
            waitForUser();
            break;
        case 7:
            handleLoadFromFileOperation(structureType);
            waitForUser();
            break;
        case 8:
            handleClearOperation(structureType);
            std::cout << "Structure has been cleared.\n";
            waitForUser();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForUser();
    }
}

void Interface::handleInsertOperation(int structureType) {
    clearScreen();
    int value, priority;
    std::cout << "--- INSERT ELEMENT ---\n";
    std::cout << "Enter value: ";
    std::cin >> value;
    std::cout << "Enter priority: ";
    std::cin >> priority;

    if (structureType == 1) {
        binaryHeap.insert(value, priority);
    } else {
        unsortedList.insert(value, priority);
    }
    std::cout << "Element inserted successfully.\n";
}

void Interface::handleExtractMaxOperation(int structureType) {
    clearScreen();
    std::cout << "--- EXTRACT MAX ---\n";
    try {
        if (structureType == 1) {
            auto maxNode = binaryHeap.extractMax();
            std::cout << "Extracted Max -> Value: " << maxNode.value << ", Priority: " << maxNode.priority << "\n";
        } else {
            auto maxNode = unsortedList.extractMax();
            std::cout << "Extracted Max -> Value: " << maxNode.value << ", Priority: " << maxNode.priority << "\n";
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Interface::handlePeekOperation(int structureType) {
    clearScreen();
    std::cout << "--- PEEK MAX ---\n";
    try {
        if (structureType == 1) {
            auto maxNode = binaryHeap.peek();
            std::cout << "Current Max -> Value: " << maxNode.value << ", Priority: " << maxNode.priority << "\n";
        } else {
            auto maxNode = unsortedList.peek();
            std::cout << "Current Max -> Value: " << maxNode.value << ", Priority: " << maxNode.priority << "\n";
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Interface::handleModifyKeyOperation(int structureType) {
    clearScreen();
    int value, newPriority;
    std::cout << "--- MODIFY KEY ---\n";
    std::cout << "Enter the value of the element to modify: ";
    std::cin >> value;
    std::cout << "Enter the new priority: ";
    std::cin >> newPriority;

    try {
        if (structureType == 1) {
            binaryHeap.modifyKey(value, newPriority);
        } else {
            unsortedList.modifyKey(value, newPriority);
        }
        std::cout << "Key modified successfully.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Interface::handleSizeOperation(int structureType) {
    clearScreen();
    std::cout << "--- STRUCTURE SIZE ---\n";
    int size = (structureType == 1) ? binaryHeap.size() : unsortedList.size();
    std::cout << "Current size: " << size << "\n";
}

void Interface::handleGenerateRandomOperation(int structureType) {
    clearScreen();
    int count;
    std::cout << "--- GENERATE RANDOM STRUCTURE ---\n";
    std::cout << "Enter the number of elements to generate: ";
    std::cin >> count;

    handleClearOperation(structureType);

    for (int i = 0; i < count; i++) {
        int randomVal = rand() % 10000;
        int randomPriority = rand() % 10000;
        if (structureType == 1) binaryHeap.insert(randomVal, randomPriority);
        else unsortedList.insert(randomVal, randomPriority);
    }
    std::cout << "Generated " << count << " random elements (with random priorities).\n";
}

void Interface::handleLoadFromFileOperation(int structureType) {
    clearScreen();
    std::string filename;
    std::cout << "--- LOAD FROM FILE ---\n";
    std::cout << "Enter text file name: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file.\n";
        return;
    }

    handleClearOperation(structureType);

    int val, priority;
    int count = 0;
    
    while (file >> val >> priority) {
        if (structureType == 1) binaryHeap.insert(val, priority);
        else unsortedList.insert(val, priority);
        count++;
    }

    file.close();
    std::cout << "Successfully loaded " << count << " elements from file.\n";
}

void Interface::handleClearOperation(int structureType) {
    
    if (structureType == 1) {
        while (!binaryHeap.isEmpty()) {
            binaryHeap.extractMax();
        }
    } else {
        while (!unsortedList.isEmpty()) {
            unsortedList.extractMax();
        }
    }
}

void Interface::displayBenchmarkMenu() {
    int choice = 0;
    while (true) {
        clearScreen();
        std::cout << "--- BENCHMARK MENU ---\n"
                  << "Select benchmark option:\n"
                  << "Run full benchmark  [1]\n"
                  << "Return to main menu [2]\n"
                  << "Your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            waitForUser();
            continue;
        }

        if (choice == 1) {
            clearScreen();
            runFullBenchmark();
            waitForUser();
        } else if (choice == 2) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
            waitForUser();
        }
    }
}

void Interface::runFullBenchmark() {
    std::cout << "Starting automatic benchmark...\n";
    Benchmark benchmark;
    benchmark.run();
    std::cout << "\nBenchmark finished!\n";
}