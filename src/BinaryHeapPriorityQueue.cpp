//
// Created by Karol Nalepa on 05/05/2026.
//

#include "../include/BinaryHeapPriorityQueue.h"

#include <filesystem>
#include <algorithm>
#include <stdexcept>

int BinaryHeapPriorityQueue::parent(int i) const {
    return (i-1)/2;
}
int BinaryHeapPriorityQueue::left(int i) const {
    return (i*2)+1;
}
int BinaryHeapPriorityQueue::right(int i) const {
    return (i*2)+2;
}

void BinaryHeapPriorityQueue::siftUp(int i) {

    while (i > 0) {
        int p = parent(i);
        if (data[p].priority < data[i].priority) {
            std::swap(data[p], data[i]);
            i = p;
        }
        else {
            break;
        }
    }
}

void BinaryHeapPriorityQueue::insert(int value, int priority) {

    Node newNode;
    newNode.priority = priority;
    newNode.value = value;
    data.push_back(newNode);
    siftUp(data.getSize()-1);

}

void BinaryHeapPriorityQueue::siftDown(int i) {

    while (left(i) < data.getSize()) {

        int maxChild = left(i);

        if (right(i) < data.getSize() && data[right(i)].priority > data[left(i)].priority) {
            maxChild = right(i);
        }

        if (data[i].priority < data[maxChild].priority) {
            std::swap(data[i], data[maxChild]);
            i = maxChild;
        }

        else {
            break;
        }
    }
}

int BinaryHeapPriorityQueue::findIndex(int value) const {
    for (int i = 0; i < data.getSize(); i++) {
        if (data[i].value == value) {
            return i;
        }
    }
    return -1;
}


Node BinaryHeapPriorityQueue::extractMax() {

    if (data.getSize() == 0) {
        throw std::runtime_error("Empty Heap");
    }

    Node max = data[0];
    std::swap(data[0], data[data.getSize()-1]);
    data.pop_back();
    if (data.getSize() > 0) {
        siftDown(0);
    }
    return max;
}

Node BinaryHeapPriorityQueue::peek() const {
    if (data.getSize() == 0) {
        throw std::runtime_error("Empty Heap");
    }

    return data[0];
}

void BinaryHeapPriorityQueue::modifyKey(int value, int priority) {

    if (data.getSize() == 0) {
        throw std::runtime_error("Empty Heap");
    }
    
    int index = findIndex(value);

    if (index == -1) {
        throw std::runtime_error("Index not found");
    }

    int oldPriority = data[index].priority;
    data[index].priority = priority;

    if (oldPriority < priority) {
        siftUp(index);
    }
    else if (oldPriority > priority) {
        siftDown(index);
    }
}

void BinaryHeapPriorityQueue::decreaseKey(int value, int priority) {

    int index = findIndex(value);
    if (index == -1) {
        throw std::runtime_error("Index not found");
    }

    int oldPriority = data[index].priority;

    if (priority >= oldPriority) {
        throw std::runtime_error("decreaseKey: new priority is not smaller");
    }

    int old = data[index].priority;
    data[index].priority = priority;
    siftDown(index);
}


void BinaryHeapPriorityQueue::increaseKey(int value, int priority) {

    int index = findIndex(value);
    if (index == -1) {
        throw std::runtime_error("Index not found");
    }

    int oldPriority = data[index].priority;

    if (priority <= oldPriority) {
        throw std::runtime_error("increaseKey: new priority is not greater");
    }

    int old = data[index].priority;
    data[index].priority = priority;
    siftUp(index);
}


int BinaryHeapPriorityQueue::size() const {
    return data.getSize();
}

bool BinaryHeapPriorityQueue::isEmpty() const {
    return data.isEmpty();
}
