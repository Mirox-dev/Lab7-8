# Lab7-8 — Список процессов (PCB)

*[Русский](#ru) | [English](#en)*

---

<a name="ru"></a>

## Описание

Реализация структуры данных **односвязный список** для управления процессами операционной системы на **C++**. Демонстрирует работу с блоками управления процессами (PCB — Process Control Block).

## Структуры данных

### `PCB` (Process Control Block)

| Поле | Тип | Описание |
|---|---|---|
| `processID` | `int` | Уникальный идентификатор |
| `processName` | `string` | Имя процесса |
| `processStatus` | `ProcessStatus` | Состояние: Running / Waiting / Stopped |
| `commandCounter` | `int` | Счётчик команд |
| `cpuRegisters` | `vector<int>` | Состояние регистров процессора |

### `ProcessList`

Односвязный список PCB, **отсортированный по `processID`** в порядке возрастания.

| Метод | Описание |
|---|---|
| `insert(pcb)` | Добавить процесс (с сохранением сортировки); `false` если ID уже существует |
| `remove(pid)` | Удалить процесс по ID; `false` если не найден |
| `printList()` | Вывести все процессы в консоль |

## Структура проекта

```
Lab7-8/
├── PCB.h             # Структура PCB и перечисление ProcessStatus
├── ListNode.h        # Узел связного списка
├── ProcessList.h     # Объявление класса ProcessList
├── ProcessList.cpp   # Реализация ProcessList
└── main.cpp          # Демонстрация работы
```

## Требования

- Компилятор с поддержкой **C++11** и выше

## Сборка и запуск

```bash
g++ main.cpp ProcessList.cpp -o process_list
./process_list
```

---

<a name="en"></a>

## Description

A **singly linked list** data structure implementation for OS process management in **C++**. Demonstrates working with Process Control Blocks (PCB).

## Data Structures

### `PCB` (Process Control Block)

| Field | Type | Description |
|---|---|---|
| `processID` | `int` | Unique identifier |
| `processName` | `string` | Process name |
| `processStatus` | `ProcessStatus` | State: Running / Waiting / Stopped |
| `commandCounter` | `int` | Instruction pointer |
| `cpuRegisters` | `vector<int>` | CPU register state |

### `ProcessList`

A singly linked list of PCBs, **sorted by `processID`** in ascending order.

| Method | Description |
|---|---|
| `insert(pcb)` | Insert a process (maintaining sort order); returns `false` if ID already exists |
| `remove(pid)` | Remove a process by ID; returns `false` if not found |
| `printList()` | Print all processes to the console |

## Project Structure

```
Lab7-8/
├── PCB.h             # PCB struct and ProcessStatus enum
├── ListNode.h        # Linked list node
├── ProcessList.h     # ProcessList class declaration
├── ProcessList.cpp   # ProcessList implementation
└── main.cpp          # Usage demonstration
```

## Requirements

- Compiler with **C++11** or higher support

## Build & Run

```bash
g++ main.cpp ProcessList.cpp -o process_list
./process_list
```
