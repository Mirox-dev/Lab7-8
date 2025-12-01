//
// Created by user on 30.11.2025.
//

#include "ProcessList.h"

using namespace std;

ProcessList::ProcessList() : head(nullptr) {}

ProcessList::~ProcessList() {
    ListNode* temp = head;
    while (temp != nullptr) {
        ListNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}

bool ProcessList::insert(const PCB &newPCB) {
    if (!head) {
        head = new ListNode(newPCB);
        return true;
    }
    if (newPCB.processID < head->data.processID) {
        auto* newNode = new ListNode(newPCB);
        newNode->next = head;
        head = newNode;
        return true;
    }

    ListNode* temp = head;
    while (temp->next && temp->next->data.processID < newPCB.processID) {
        temp = temp->next;
    }
    if (temp->data.processID == newPCB.processID) {
        return false;
    }
    auto* newNode = new ListNode(newPCB);
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}
bool ProcessList::remove(const int pid) {
    if (!head) {
        return false;
    }
    ListNode* temp = head;
    if (head->data.processID == pid) {
        head = head->next;
        delete temp;
        return true;
    }
    while (temp && temp->data.processID != pid) {
        temp = temp->next;
    }
    if (!temp) {
        return false;
    }
    delete temp;
    return true;
}
void ProcessList::printList() const {
    ListNode* temp = head;
    while (temp) {
        cout << "ProcessID: " << temp->data.processID << endl;
        cout << "ProcessName: " << temp->data.processName << endl;
        switch (temp->data.processStatus) {
            case ProcessStatus::Running: cout << "ProcessStatus: Running" << endl; break;
            case ProcessStatus::Stopped: cout << "ProcessStatus: Stopped" << endl; break;
            case ProcessStatus::Waiting: cout << "ProcessStatus: Waiting" << endl; break;
        }
        cout << "Command Counter: " << temp->data.commandCounter << endl;
        cout << "CPU Registers: ";
        for (int x: temp -> data.cpuRegisters) {
            cout << x << ", ";
        };
        cout << endl;
        cout << "===================" << endl;
        temp = temp->next;
    }
}


