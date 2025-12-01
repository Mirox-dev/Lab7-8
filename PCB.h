//
// Created by user on 30.11.2025.
//

#ifndef PCB_H
#define PCB_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum class ProcessStatus {
    Running,
    Waiting,
    Stopped
};

struct PCB {
    int processID;
    string processName;
    ProcessStatus processStatus;
    int commandCounter;
    vector<int> cpuRegisters;
    PCB() : processID(0), processName(""), processStatus(ProcessStatus::Stopped), commandCounter(0), cpuRegisters{} {}
    PCB(int ID, string Name, ProcessStatus Status, int Counter, const vector<int>& Registers) :
        processID(ID), processName(move(Name)), processStatus(Status), commandCounter(Counter), cpuRegisters(Registers) {}
};

#endif
