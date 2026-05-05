//
// Created by Karol Nalepa on 04/05/2026.
//

#include "../include/UnsortedListPriorityQueue.h"
#include "../include/DynamicArray.h"
#include <stdexcept>

void UnsortedListPriorityQueue::insert(int value, int priority) {
    Node newNode;
    newNode.value = value;
    newNode.priority = priority;
    data.push_back(newNode);
}



Node UnsortedListPriorityQueue::extractMax() {
    if (data.isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    int maxIndex = 0;

    for (int i = 1; i < data.getSize(); i++) {
        if (data[i].priority > data[maxIndex].priority) {
            maxIndex = i;

        }
    }

    Node maxNode = data[maxIndex];
    data.removeSwap(maxIndex);
    return maxNode;

}

Node UnsortedListPriorityQueue::peek() const {
    if (data.isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    int maxIndex = 0;

    for (int i = 1; i < data.getSize(); i++) {
        if (data[i].priority > data[maxIndex].priority) {
            maxIndex = i;

        }
    }
    return data[maxIndex];
}

int UnsortedListPriorityQueue::findIndex(int value) const {
    for (int i = 0; i < data.getSize(); i++) {
        if (data[i].value == value) {
            return i;
        }
    }
    return -1;
}


void UnsortedListPriorityQueue::modifyKey(int value, int priority) {
    int index = findIndex(value);

    if (index == -1) {
        throw std::runtime_error("Element not found");
    }

    data[index].priority = priority;
}

void UnsortedListPriorityQueue::decreaseKey(int value, int priority) {
    int index = findIndex(value);

    if (index == -1) {
        throw std::runtime_error("Element not found");
    }

    if (priority >= data[index].priority) {
        throw std::runtime_error("decreaseKey: new priority is not smaller");
    }

    data[index].priority = priority;
}

void UnsortedListPriorityQueue::increaseKey(int value, int priority) {

    int index = findIndex(value);

    if (index == -1) {
        throw std::runtime_error("Element not found");
    }

    if (priority <= data[index].priority) {
        throw std::runtime_error("increaseKey: new priority is not greater");
    }

    data[index].priority = priority;

}


int UnsortedListPriorityQueue::size() const {
    return data.getSize();
}

bool UnsortedListPriorityQueue::isEmpty() const {
    return data.isEmpty();
}
