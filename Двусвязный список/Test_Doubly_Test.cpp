#include "pch.h"
#include "DoublyLinkedList.h"

// Фикстура для тестов
class DoublyLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        list = new DoublyLinkedList();
    }

    void TearDown() override {
        delete list;
    }

    DoublyLinkedList* list = nullptr; // Инициализация для избежания предупреждений
};

// Тест 1: Создание пустого списка
TEST_F(DoublyLinkedListTest, EmptyOnCreation) {
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Тест 2: Добавление в конец
TEST_F(DoublyLinkedListTest, PushBackAddsElements) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    EXPECT_FALSE(list->isEmpty());
    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 1.0);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 3.0);
}



// Тест 3: Добавление в начало
TEST_F(DoublyLinkedListTest, PushFrontAddsElements) {
    list->push_front(3.0);
    list->push_front(2.0);
    list->push_front(1.0);

    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 1.0);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 3.0);
}

// Тест 4: Удаление из начала
TEST_F(DoublyLinkedListTest, PopFrontRemovesElements) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    list->pop_front();
    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 2.0);

    list->pop_front();
    EXPECT_EQ(list->size(), 1);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 3.0);

    list->pop_front();
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Тест 5: Удаление с конца
TEST_F(DoublyLinkedListTest, PopBackRemovesElements) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    list->pop_back();
    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 2.0);

    list->pop_back();
    EXPECT_EQ(list->size(), 1);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 1.0);

    list->pop_back();
    EXPECT_TRUE(list->isEmpty());
}

// Тест 6: Доступ по индексу
TEST_F(DoublyLinkedListTest, GetAtReturnsCorrectElements) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    Node* first = list->getAt(0);
    Node* second = list->getAt(1);
    Node* third = list->getAt(2);
    Node* invalid = list->getAt(5);

    EXPECT_NE(first, nullptr);
    EXPECT_DOUBLE_EQ(first->data, 1.0);

    EXPECT_NE(second, nullptr);
    EXPECT_DOUBLE_EQ(second->data, 2.0);

    EXPECT_NE(third, nullptr);
    EXPECT_DOUBLE_EQ(third->data, 3.0);

    EXPECT_EQ(invalid, nullptr);
}

// Тест 7: Оператор индексации
TEST_F(DoublyLinkedListTest, OperatorBracketWorks) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    EXPECT_DOUBLE_EQ((*list)[0]->data, 1.0);
    EXPECT_DOUBLE_EQ((*list)[1]->data, 2.0);
    EXPECT_DOUBLE_EQ((*list)[2]->data, 3.0);
    EXPECT_EQ((*list)[5], nullptr);
}

// Тест 8: Вставка в середину
TEST_F(DoublyLinkedListTest, InsertInMiddle) {
    list->push_back(1.0);
    list->push_back(3.0);

    list->insert(1, 2.0);

    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ((*list)[0]->data, 1.0);
    EXPECT_DOUBLE_EQ((*list)[1]->data, 2.0);
    EXPECT_DOUBLE_EQ((*list)[2]->data, 3.0);
}

// Тест 9: Вставка в начало через insert
TEST_F(DoublyLinkedListTest, InsertAtBeginning) {
    list->push_back(2.0);
    list->push_back(3.0);

    list->insert(0, 1.0);

    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 1.0);
}

// Тест 10: Вставка в конец через insert
TEST_F(DoublyLinkedListTest, InsertAtEnd) {
    list->push_back(1.0);
    list->push_back(2.0);

    list->insert(10, 3.0); // Несуществующий индекс

    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 3.0);
}

// Тест 11: Удаление из середины
TEST_F(DoublyLinkedListTest, EraseFromMiddle) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);
    list->push_back(4.0);

    list->erase(1);

    EXPECT_EQ(list->size(), 3);
    EXPECT_DOUBLE_EQ((*list)[0]->data, 1.0);
    EXPECT_DOUBLE_EQ((*list)[1]->data, 3.0);
    EXPECT_DOUBLE_EQ((*list)[2]->data, 4.0);
}

// Тест 12: Удаление из начала через erase
TEST_F(DoublyLinkedListTest, EraseFromBeginning) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    list->erase(0);

    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 2.0);
}

// Тест 13: Удаление с конца через erase
TEST_F(DoublyLinkedListTest, EraseFromEnd) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    list->erase(2);

    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 2.0);
}

// Тест 14: Двунаправленные связи
TEST_F(DoublyLinkedListTest, BidirectionalLinks) {
    list->push_back(1.0);
    list->push_back(2.0);
    list->push_back(3.0);

    // Проверка связей вперед
    Node* first = list->getHead();
    Node* second = first->next;
    Node* third = second->next;

    EXPECT_EQ(first->next, second);
    EXPECT_EQ(second->next, third);
    EXPECT_EQ(third->next, nullptr);

    // Проверка связей назад
    EXPECT_EQ(third->prev, second);
    EXPECT_EQ(second->prev, first);
    EXPECT_EQ(first->prev, nullptr);

    // Проверка данных
    EXPECT_DOUBLE_EQ(first->data, 1.0);
    EXPECT_DOUBLE_EQ(second->data, 2.0);
    EXPECT_DOUBLE_EQ(third->data, 3.0);
}

// Тест 15: Граничные случаи
TEST_F(DoublyLinkedListTest, EdgeCases) {
    // Удаление из пустого списка
    list->pop_front();
    list->pop_back();
    EXPECT_TRUE(list->isEmpty());

    // Работа с одним элементом
    list->push_back(5.0);
    list->pop_front();
    EXPECT_TRUE(list->isEmpty());

    list->push_front(5.0);
    list->pop_back();
    EXPECT_TRUE(list->isEmpty());

    // Неверные индексы
    list->push_back(1.0);
    list->insert(5, 2.0); // Добавится в конец
    list->erase(5); // Ничего не произойдет

    EXPECT_EQ(list->size(), 2);
}

// Тест 16: Деструктор очищает память
TEST_F(DoublyLinkedListTest, DestructorCleansMemory) {
    DoublyLinkedList* localList = new DoublyLinkedList();

    // Добавляем много элементов
    for (int i = 0; i < 100; ++i) {
        localList->push_back(i * 1.0);
    }

    // Деструктор должен очистить всю память
    EXPECT_NO_THROW(delete localList);
}

// Тест 17: Смешанные операции
TEST_F(DoublyLinkedListTest, MixedOperations) {
    list->push_front(2.0);
    list->push_back(3.0);
    list->push_front(1.0);
    list->push_back(4.0);

    EXPECT_EQ(list->size(), 4);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 1.0);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 4.0);

    list->pop_front();
    list->pop_back();

    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 2.0);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 3.0);

    list->insert(1, 2.5);
    list->erase(0);

    EXPECT_EQ(list->size(), 2);
    EXPECT_DOUBLE_EQ(list->getHead()->data, 2.5);
    EXPECT_DOUBLE_EQ(list->getTail()->data, 3.0);
}

