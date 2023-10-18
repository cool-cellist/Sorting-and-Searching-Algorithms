#include <random> //random number generator
#include <x86intrin.h> //seeding for random numbers
#include <iostream> //input and output
#include <vector> //basically arrays that can grow, shrink, etc.
#include <chrono> //to time the program

//a class obj to time the algorithms.  comes with two functions to restart the stopwatch and get the current running time
class Stopwatch {
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();

    public:
    void restart() {start = std::chrono::steady_clock::now();}
    int64_t duration() {return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count();}
};

//basically the stopwatch above, but measures in nanoseconds instead of milliseconds.  this is for precise testing.
class nanoStopwatch {
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();

    public:
    void restart() {start = std::chrono::steady_clock::now();}
    int64_t duration() {return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-start).count();}
};

//prints any given integer vector (all these functions only work with integer vectors)
void printList(std::vector<int>& list) {
    for (int i=0; i<list.size(); i++) {
        std::cout << "\n" << list.at(i);
    }
    std::cout << "\n";
}

std::mt19937 engine(0); //uses the cpu for generating a psuedo-random number and time as seeding

//generates a random list of n or 'size' numbers within 'min' -> 'max'
std::vector<int> generateList(int min, int max, int size) {
    engine.seed(_rdtsc()); //seeds the engine with the current tick to make it actually random (but not truly)
    std::uniform_int_distribution<> generator(min, max); //the generator for the random number

    std::vector<int> returnThis(size);
    for (int i=0; i<size; i++) {
        returnThis[i] = generator(engine); //the generator needs the engine for seeding
    }

    return returnThis;
}

//generates a set, which is a list with no duplicates.  it goes from min to max in defined increments
std::vector<int> generateOrderedIncrementedSet(int min, int max, int increment) {
    std::vector<int> list;

    for (int i=min; i<=max; i+=increment) {
        list.push_back(i);
    }

    return list;
}

//uses the fisher-yates shuffling algorithm, where from the beginning to end of the list, a random number within the list is chosen to swap with the current one.
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
