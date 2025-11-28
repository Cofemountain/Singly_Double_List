#pragma once

class Node {
public:
    double data;
    Node* next;

    Node(double data) : data(data), next(nullptr) {}
};

class OneLinkedList {
private:
    Node* head;
    Node* tail;

public:
    OneLinkedList() : head(nullptr), tail(nullptr) {}

    // Запрещаем копирование и присваивание для простоты
    OneLinkedList(const OneLinkedList&) = delete;
    OneLinkedList& operator=(const OneLinkedList&) = delete;

    ~OneLinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void push_back(double data) {
        Node* new_node = new Node(data);

        if (tail == nullptr) {
            // Список пустой
            head = tail = new_node;
        }
        else {
            // Список не пустой
            tail->next = new_node;
            tail = new_node;
        }
    }

    void push_front(double data) {
        Node* new_node = new Node(data);

        if (head == nullptr) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }

    void pop_front() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr; // Список стал пустым
        }

        delete temp;
    }

    void pop_back() {
        if (tail == nullptr) return;

        if (head == tail) {
            // Один элемент в списке
            delete tail;
            head = tail = nullptr;
            return;
        }

        // Ищем предпоследний элемент
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        // Удаляем последний элемент
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    Node* getAt(int index) {
        if (index < 0) return nullptr;

        Node* current = head;
        int count = 0;

        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }

        return current;
    }

    void insert(int index, double data) {
        if (index < 0) return;

        if (index == 0) {
            push_front(data);
            return;
        }

        Node* prev = getAt(index - 1);
        if (prev == nullptr) return; // Неверный индекс

        Node* new_node = new Node(data);
        new_node->next = prev->next;
        prev->next = new_node;

        // Если вставляем после tail, обновляем tail
        if (prev == tail) {
            tail = new_node;
        }
    }

    void erase(int index) {
        if (index < 0) return;

        if (index == 0) {
            pop_front();
            return;
        }

        Node* prev = getAt(index - 1);
        if (prev == nullptr || prev->next == nullptr) return;

        Node* to_delete = prev->next;
        prev->next = to_delete->next;

        // Если удаляем tail, обновляем tail
        if (to_delete == tail) {
            tail = prev;
        }

        delete to_delete;
    }

    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    bool empty() const {
        return head == nullptr;
    }

    Node* front() const { return head; }
    Node* back() const { return tail; }
};