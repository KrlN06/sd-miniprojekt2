//
// Created by Karol Nalepa on 04/05/2026.
//

#ifndef PROJEKT_2_UNSORTEDLISTPRIORITYQUEUE_H
#define PROJEKT_2_UNSORTEDLISTPRIORITYQUEUE_H

#include "DynamicArray.h"

struct Node {
        int value;
        int priority;
};

class UnsortedListPriorityQueue {
private:
        DynamicArray<Node> data;
        int findIndex(int value) const;

public:
        UnsortedListPriorityQueue() = default;
        ~UnsortedListPriorityQueue() = default;
        void insert(int value, int priority);

        Node extractMax();
        Node peek() const;

        void modifyKey(int value, int priority);
        void decreaseKey(int value, int priority);
        void increaseKey(int value, int priority);

        int size() const;
        bool isEmpty() const;
};

#endif