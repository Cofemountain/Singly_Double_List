#include <gtest/gtest.h>

// Главная функция для всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running All Google Tests..." << std::endl;
    return RUN_ALL_TESTS();
}