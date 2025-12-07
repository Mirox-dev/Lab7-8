//
// Created by user on 30.11.2025.
//

#ifndef LISTNODE_H
#define LISTNODE_H

#include <utility>

#include "PCB.h"

using namespace std;

// Класс ListNode представляет узел односвязного списка
// Каждый узел содержит PCB (данные) и указатель на следующий узел
class ListNode {
public:
    PCB data;        // Данные процесса (PCB)
    ListNode* next;  // Указатель на следующий узел в списке

    // Конструктор создает узел с заданными данными PCB
    // nextNode по умолчанию nullptr (конец списка)
    ListNode(PCB  pcb, ListNode* nextNode) :
        data(std::move(pcb)), next(nextNode) {}
};

#endif //LISTNODE_H