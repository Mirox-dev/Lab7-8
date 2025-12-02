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
        cout << "-----" << newPCB.processName << " insert successful" << "-----" << endl;
        return true;
    }
    if (newPCB.processID < head->data.processID) {
        auto* newNode = new ListNode(newPCB);
        newNode->next = head;
        head = newNode;
        cout <<  "-----" << newPCB.processName << " insert successful" << "-----" << endl;
        return true;
    }

    ListNode* temp = head;
    while (temp->next && temp->next->data.processID < newPCB.processID) {
        temp = temp->next;
    }
    if (!temp->next && temp->data.processID != newPCB.processID) {
        auto* newNode = new ListNode(newPCB);
        temp->next = newNode;
        cout << "-----" << newPCB.processName << " insert successful" << "-----" << endl;
        return true;
    }
    if (!temp->next && temp->data.processID == newPCB.processID) {
        cout << "-----" << newPCB.processName << " insert failed" << "-----" << endl;
        return false;
    }
    if (temp->next->data.processID == newPCB.processID) {
        cout << "-----" << newPCB.processName << " insert failed" << "-----" << endl;
        return false;
    }
    auto* newNode = new ListNode(newPCB);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "-----" << newPCB.processName << " insert successful" << "-----" << endl;
    return true;
}
bool ProcessList::remove(const int pid) {
    if (!head) {
        cout << "-----" << "Process" << pid << " removing failed" << "-----" << endl;
        return false;
    }
    ListNode* temp = head;
    if (head->data.processID == pid) {
        head = head->next;
        delete temp;
        cout << "-----" << "Process" << pid << " removing complete" << "-----" << endl;
        return true;
    }
    while (temp->next && temp->next->data.processID != pid) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "-----" << "Process" << pid << " removing failed" << "-----" << endl;
        return false;
    }
    ListNode* Delete = temp->next;
    temp->next = Delete->next;
    cout << "-----" << "Process" << pid << " removing complete" << "-----" << endl;
    delete Delete;
    return true;
}
void ProcessList::printList() const {
    ListNode* temp = head;
    cout << "Process List: " << endl;
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
        auto last = prev(temp->data.cpuRegisters.end());
        for (auto x = temp -> data.cpuRegisters.begin(); x != last; ++x) {
            cout << *x << ", ";
        };
        cout << temp->data.cpuRegisters.back() << endl;
        cout << "========================================" << endl;
        temp = temp->next;
    }
}


