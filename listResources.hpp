#include <random>
#include <x86intrin.h>
#include <iostream>
#include <vector>

void printList(std::vector<int>& list) {
    for (int i=0; i<list.size(); i++) {
        std::cout << "\n" << list.at(i);
    }
    std::cout << "\n";
}

std::mt19937 engine(0);

std::vector<int> generateList(int min, int max, int size) {
    engine.seed(_rdtsc());
    std::uniform_int_distribution<> generator(min, max);

    std::vector<int> returnThis(size);
    for (int i=0; i<size; i++) {
        returnThis[i] = generator(engine);
    }

    return returnThis;
}