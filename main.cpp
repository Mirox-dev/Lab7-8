//
// Created by user on 30.11.2025.
//

#include <iostream>
#include "ProcessList.cpp"

using namespace std;

int main() {
    // Создание списка процессов
    ProcessList PCB_list;

    PCB p1(1, "Process1", ProcessStatus::Running, 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    PCB p2;
    p2.processID = 2;
    p2.processName = "Process2";
    p2.processStatus = ProcessStatus::Stopped;
    p2.commandCounter = 5;
    p2.cpuRegisters = {1, 2, 11};

    PCB p3(1, "Process3", ProcessStatus::Waiting, 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    // Тестирование операций со списком:

    // Вставка p1 (успешно)
    PCB_list.insert(p1);

    // Вставка p2 (успешно, список отсортируется: p1(1), p2(2))
    PCB_list.insert(p2);

    // Вывод текущего состояния списка
    PCB_list.printList();

    // Удаление p2 (успешно)
    PCB_list.remove(p2.processID);

    // Вывод списка после удаления
    PCB_list.printList();

    // Попытка вставки p3 (дубликат ID, должна завершиться ошибкой)
    PCB_list.insert(p3);

    // Попытка удаления несуществующего процесса (должна завершиться ошибкой)
    PCB_list.remove(99);

    // Повторная вставка p2
    PCB_list.insert(p2);

    // Вывод финального состояния списка
    cout << "The final state of the list:" << endl;
    PCB_list.printList();

    return 0;
}