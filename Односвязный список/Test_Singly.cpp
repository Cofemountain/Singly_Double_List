#include <gtest/gtest.h>
#include "SinglyLinkedList.h"

TEST(OneLinkedListTest, DefaultConstructor) {
    OneLinkedList list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.front(), nullptr);
    EXPECT_EQ(list.back(), nullptr);
}

TEST(OneLinkedListTest, SinglePushBack) {
    OneLinkedList list;

    list.push_back(1.0);

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    ASSERT_NE(list.front(), nullptr);
    ASSERT_NE(list.back(), nullptr);
    EXPECT_EQ(list.front()->data, 1.0);
    EXPECT_EQ(list.back()->data, 1.0);
}

TEST(OneLinkedListTest, MultiplePushBack) {
    OneLinkedList list;

    list.push_back(1.0);
    list.push_back(2.0);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front()->data, 1.0);
    EXPECT_EQ(list.back()->data, 2.0);

    // Проверка связей
    ASSERT_NE(list.front()->next, nullptr);
    EXPECT_EQ(list.front()->next->data, 2.0);
    EXPECT_EQ(list.back()->next, nullptr);
}

TEST(OneLinkedListTest, PushFront) {
    OneLinkedList list;

    list.push_front(1.0);
    list.push_front(2.0);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front()->data, 2.0);
    EXPECT_EQ(list.back()->data, 1.0);
}

TEST(OneLinkedListTest, PopFront) {
    OneLinkedList list;
    list.push_back(1.0);
    list.push_back(2.0);

    list.pop_front();

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front()->data, 2.0);
    EXPECT_EQ(list.back()->data, 2.0);

    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(OneLinkedListTest, PopBack) {
    OneLinkedList list;
    list.push_back(1.0);
    list.push_back(2.0);

    list.pop_back();

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front()->data, 1.0);
    EXPECT_EQ(list.back()->data, 1.0);

    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(OneLinkedListTest, GetAt) {
    OneLinkedList list;
    list.push_back(1.0);
    list.push_back(2.0);
    list.push_back(3.0);

    Node* node0 = list.getAt(0);
    ASSERT_NE(node0, nullptr);
    EXPECT_EQ(node0->data, 1.0);

    Node* node1 = list.getAt(1);
    ASSERT_NE(node1, nullptr);
    EXPECT_EQ(node1->data, 2.0);

    Node* node2 = list.getAt(2);
    ASSERT_NE(node2, nullptr);
    EXPECT_EQ(node2->data, 3.0);

    Node* node3 = list.getAt(3);
    EXPECT_EQ(node3, nullptr);
}

TEST(OneLinkedListTest, Insert) {
    OneLinkedList list;

    // Вставка в пустой список
    list.insert(0, 1.0);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front()->data, 1.0);

    // Вставка в начало
    list.insert(0, 0.5);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front()->data, 0.5);
    EXPECT_EQ(list.back()->data, 1.0);

    // Вставка в середину
    list.insert(1, 0.75);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getAt(0)->data, 0.5);
    EXPECT_EQ(list.getAt(1)->data, 0.75);
    EXPECT_EQ(list.getAt(2)->data, 1.0);
}

TEST(OneLinkedListTest, Erase) {
    OneLinkedList list;
    list.push_back(1.0);
    list.push_back(2.0);
    list.push_back(3.0);
    list.push_back(4.0);

    // Удаление из середины
    list.erase(1);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getAt(0)->data, 1.0);
    EXPECT_EQ(list.getAt(1)->data, 3.0);
    EXPECT_EQ(list.getAt(2)->data, 4.0);

    // Удаление первого элемента
    list.erase(0);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front()->data, 3.0);

    // Удаление последнего элемента
    list.erase(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front()->data, 3.0);
    EXPECT_EQ(list.back()->data, 3.0);
}

TEST(OneLinkedListTest, EdgeCases) {
    OneLinkedList list;

    // Операции на пустом списке
    list.pop_front();
    list.pop_back();
    list.erase(0);

    EXPECT_TRUE(list.empty());

    // Добавление и удаление одного элемента
    list.push_back(1.0);
    list.pop_front();
    EXPECT_TRUE(list.empty());

    list.push_front(1.0);
    list.pop_back();
    EXPECT_TRUE(list.empty());
}