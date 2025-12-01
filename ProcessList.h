//
// Created by user on 30.11.2025.
//

#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"

class ProcessList {
private:
    ListNode* head;
public:
    ProcessList();
    ~ProcessList();

    bool insert(const PCB& newPCB);
    bool remove(int pid);
    void printList() const;
};

#endif //PROCESSLIST_H
