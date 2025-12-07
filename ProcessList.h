//
// Created by user on 30.11.2025.
//

#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"

// Класс ProcessList представляет собой односвязный список процессов (PCB)
// Список отсортирован по processID в порядке возрастания
class ProcessList {
    ListNode* head;  // Указатель на первый узел списка
public:
    ProcessList();   // Конструктор по умолчанию
    ~ProcessList();  // Деструктор для освобождения памяти

    // Вставка нового процесса в список с сохранением сортировки по processID
    // Возвращает true при успешной вставке, false если процесс с таким ID уже существует
    bool insert(const PCB& newPCB);

    // Удаление процесса по его ID (pid)
    // Возвращает true если процесс найден и удален, false если процесс не найден
    bool remove(int pid);

    // Вывод всех процессов списка в консоль в читаемом формате
    void printList() const;
};

#endif //PROCESSLIST_H