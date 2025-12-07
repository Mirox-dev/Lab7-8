//
// Created by user on 30.11.2025.
//

#include "ProcessList.h"

using namespace std;

// Конструктор инициализирует пустой список
ProcessList::ProcessList() : head(nullptr) {}

// Деструктор освобождает всю память, занимаемую узлами списка
ProcessList::~ProcessList() {
    ListNode* temp = head;
    while (temp != nullptr) {
        ListNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}

// Вставка нового процесса с сохранением сортировки по processID
bool ProcessList::insert(const PCB &newPCB) {
    // Список пустой или новый ID меньше головного
    if (!head || newPCB.processID < head->data.processID) {
        head = new ListNode(newPCB, head);
        cout << "-----" << newPCB.processName << " insert successful-----" << endl;
        return true;
    }

    // Поиск позиции для вставки (список отсортирован по возрастанию ID)
    ListNode* temp = head;
    while (temp->next && temp->next->data.processID < newPCB.processID) {
        temp = temp->next;
    }

    // Обнаружен дубликат ID (вставка невозможна)
    if (temp->data.processID == newPCB.processID || temp->next && temp->next->data.processID == newPCB.processID) {
        cout << "-----" << newPCB.processName << " insert failed-----" << endl;
        return false;
    }

    // Вставка в список
    temp->next = new ListNode(newPCB, temp->next);
    cout << "-----" << newPCB.processName << " insert successful-----" << endl;
    return true;
}

// Удаление процесса по его ID
bool ProcessList::remove(const int pid) {
    // Список пустой
    if (!head) {
        cout << "-----Process" << pid << " removing failed-----" << endl;
        return false;
    }

    // Удаление головы
    ListNode* temp = head;
    if (head->data.processID == pid) {
        head = head->next;
        delete temp;
        cout << "-----Process" << pid << " removing complete-----" << endl;
        return true;
    }

    // Поиск узла, предшествующего удаляемому
    while (temp->next && temp->next->data.processID != pid) {
        temp = temp->next;
    }

    // Процесс не найден
    if (!temp->next) {
        cout << "-----Process" << pid << " removing failed-----" << endl;
        return false;
    }

    // Удаление из середины или конца списка
    ListNode* Delete = temp->next;
    temp->next = Delete->next;
    cout << "-----Process" << pid << " removing complete-----" << endl;
    delete Delete;
    return true;
}

// Вывод всех процессов списка в консоль
void ProcessList::printList() const {
    ListNode* temp = head;
    cout << "Process List: " << endl;

    while (temp) {
        cout << "ProcessID: " << temp->data.processID << endl;
        cout << "ProcessName: " << temp->data.processName << endl;

        // Вывод статуса процесса в читаемом формате
        switch (temp->data.processStatus) {
            case ProcessStatus::Running: cout << "ProcessStatus: Running" << endl; break;
            case ProcessStatus::Stopped: cout << "ProcessStatus: Stopped" << endl; break;
            case ProcessStatus::Waiting: cout << "ProcessStatus: Waiting" << endl; break;
        }

        cout << "Command Counter: " << temp->data.commandCounter << endl;
        cout << "CPU Registers: ";

        // Вывод регистров процессора с правильным форматированием (через запятую)
        auto last = prev(temp->data.cpuRegisters.end());
        for (auto x = temp->data.cpuRegisters.begin(); x != last; ++x) {
            cout << *x << ", ";
        };
        cout << temp->data.cpuRegisters.back() << endl;

        // Разделитель между процессами
        cout << "===========================================" << endl;
        temp = temp->next;
    }
}