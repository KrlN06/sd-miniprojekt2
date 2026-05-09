//
// Created by Karol Nalepa on 05/05/2026.
//

#ifndef PROJEKT_2_BINARYHEAPPRIORITYQUEUE_H
#define PROJEKT_2_BINARYHEAPPRIORITYQUEUE_H

#include "DynamicArray.h"
#include "Node.h"
class BinaryHeapPriorityQueue {

private:
    DynamicArray<Node> data;

    int parent(int i) const;
    int left(int i) const;
    int right(int i) const;

    void siftUp(int i);
    void siftDown(int i);

    int findIndex(int value) const;

public:
    BinaryHeapPriorityQueue() = default;
    ~BinaryHeapPriorityQueue() = default;

    void insert(int value, int priority);
    Node extractMax();
    Node peek() const;

    void modifyKey(int value, int priority);
    void decreaseKey(int value, int priority);
    void increaseKey(int value, int priority);

    int size() const;
    bool isEmpty() const;
};

#endif //PROJEKT_2_BINARYHEAPPRIORITYQUEUE_H
