#include <random>
#include <x86intrin.h>
#include <iostream>
#include <vector>
#include <chrono>

class Stopwatch {
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();

    public:
    void restart() {start = std::chrono::steady_clock::now();}
    int64_t duration() {return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count();}
};

class nanoStopwatch {
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();

    public:
    void restart() {start = std::chrono::steady_clock::now();}
    int64_t duration() {return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-start).count();}
};


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

std::vector<int> generateOrderedIncrementedSet(int min, int max, int increment) {
    std::vector<int> list;

    for (int i=min; i<=max; i+=increment) {
        list.push_back(i);
    }

    return list;
}

void shuffle(std::vector<int>& list) {
    engine.seed(_rdtsc());
    std::uniform_int_distribution<> generator(0, list.size()-1);
    for (int i=0; i<list.size(); i++) {
        int randomIndex = generator(engine);
        int temp = list.at(i);
        list.at(i) = list.at(randomIndex);
        list.at(randomIndex) = temp;
    }
}
