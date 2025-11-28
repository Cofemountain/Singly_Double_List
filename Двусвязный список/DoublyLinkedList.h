#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class Node {
public:
    double data;
    Node* prev;
    Node* next;

public:
    Node(double data) {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // ИСПРАВЛЕННЫЙ деструктор
    ~DoublyLinkedList() {
        clear();
    }

    // Метод для безопасной очистки
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // Добавление в начало
    Node* push_front(double data) {
        Node* ptr = new Node(data);

        ptr->next = head;
        if (head != nullptr)
            head->prev = ptr;
        if (tail == nullptr)
            tail = ptr;
        head = ptr;

        return ptr;
    }

    // Добавление в конец
    Node* push_back(double data) {
        Node* ptr = new Node(data);

        ptr->prev = tail;
        if (tail != nullptr)
            tail->next = ptr;
        if (head == nullptr)
            head = ptr;
        tail = ptr;

        return ptr;
    }

    // ИСПРАВЛЕННОЕ удаление из начала
    void pop_front() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr; // Если список стал пустым

        delete temp;
    }

    // ИСПРАВЛЕННОЕ удаление с конца
    void pop_back() {
        if (tail == nullptr) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr; // Если список стал пустым

        delete temp;
    }

    // Получение элемента по индексу
    Node* getAt(int index) {
        if (index < 0) return nullptr;

        Node* ptr = head;
        int n = 0;

        while (ptr != nullptr && n < index) {
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }

    // Оператор доступа по индексу
    Node* operator [] (int index) {
        return getAt(index);
    }

    // Вставка элемента по индексу
    Node* insert(int index, double data) {
        Node* right = getAt(index);
        if (right == nullptr)
            return push_back(data);

        Node* left = right->prev;
        if (left == nullptr)
            return push_front(data);

        Node* ptr = new Node(data);

        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        return ptr;
    }

    // ИСПРАВЛЕННОЕ удаление элемента по индексу
    void erase(int index) {
        Node* ptr = getAt(index);
        if (ptr == nullptr)
            return;

        if (ptr->prev == nullptr) {
            pop_front();
            return;
        }

        if (ptr->next == nullptr) {
            pop_back();
            return;
        }

        Node* left = ptr->prev;
        Node* right = ptr->next;
        left->next = right;
        right->prev = left;

        delete ptr;
    }

    // Получение размера списка
    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Вывод списка в прямом направлении
    void printForward() const {
        Node* current = head;
        std::cout << "Forward: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr)
                std::cout << " <-> ";
            current = current->next;
        }
        std::cout << " -> nullptr" << std::endl;
    }

    // Получение головы списка
    Node* getHead() const { return head; }

    // Получение хвоста списка
    Node* getTail() const { return tail; }
};

#endif