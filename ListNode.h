//
// Created by user on 30.11.2025.
//

#ifndef LISTNODE_H
#define LISTNODE_H

#include "PCB.h"

class ListNode {
public:
    PCB data;
    ListNode* next;

    ListNode(const PCB& pcb, ListNode* nextNode = nullptr) : data(pcb), next(nextNode) {}
};
#endif //LISTNODE_H
