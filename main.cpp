//
// Created by user on 30.11.2025.
//

#include <iostream>
#include "ProcessList.h"

using namespace std;

int main() {
    ProcessList PCB_list;
    PCB p1(1, "Process1", ProcessStatus::Running, 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    PCB p2;
    p2.processID = 2;
    p2.processName = "Process2";
    p2.processStatus = ProcessStatus::Stopped;
    p2.commandCounter = 5;
    p2.cpuRegisters = {1, 2, 11};
    PCB p3(1, "Process3", ProcessStatus::Waiting, 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    PCB_list.insert(p1);
    PCB_list.insert(p2);
    PCB_list.printList();
    PCB_list.remove(p2.processID);
    cout << "Process list after removing process 2" << endl;
    PCB_list.printList();
    if (!PCB_list.insert(p3)) {
        cout << "Process list insert failed" << endl;
    }
    if (!PCB_list.remove(99)) {
        cout << "Process list remove failed" << endl;
    }
    cout << "The final state of the list:" << endl;
    PCB_list.printList();
    return 0;
}