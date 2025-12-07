//
// Created by user on 30.11.2025.
//

#ifndef PCB_H
#define PCB_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Перечисление возможных состояний процесса
// Running - выполняется, Waiting - ожидает, Stopped - остановлен
enum class ProcessStatus {
    Running,
    Waiting,
    Stopped
};

// Структура PCB (Process Control Block) - блок управления процессом
struct PCB {
    int processID;           // Уникальный идентификатор
    string processName;      // Имя процесса
    ProcessStatus processStatus; // Текущее состояние процесса
    int commandCounter;      // Счетчик команд (указатель на следующую команду)
    vector<int> cpuRegisters; // Состояние регистров процессора

    // Конструктор по умолчанию инициализирует поля нулевыми значениями
    PCB() : processID(0), processStatus(ProcessStatus::Stopped),
            commandCounter(0), cpuRegisters{} {}

    // Параметризованный конструктор для создания PCB со всеми данными
    // Использует move-семантику для эффективной передачи строки
    PCB(int ID, string Name, ProcessStatus Status, int Counter, const vector<int>& Registers) :
        processID(ID), processName(std::move(Name)), processStatus(Status),
        commandCounter(Counter), cpuRegisters(Registers) {}
};

#endif