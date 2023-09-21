#include <chrono>
#include "listResources.hpp"
#include "sortingAlgs.hpp"

class Stopwatch {
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();

    public:
    void restart() {
        start = std::chrono::steady_clock::now();
    }

    int64_t duration() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count();
    }
};

Stopwatch sp = Stopwatch();
int64_t testAlgo(void (*func)(std::vector<int>&), int items) {
    std::vector<int> list = generateList(-100, 100, items);
    sp.restart();
    func(list);
    return sp.duration();
}

int64_t testAlgo(std::vector<int> (*func)(std::vector<int>&), int items) {
    std::vector<int> list = generateList(-100, 100, items);
    sp.restart();
    list = func(list);
    return sp.duration();
}

int main() {
    int items[] = {100, 1000, 10000};

    std::cout << "\nSELECTION SORT MICROSECONDS: ";
    for (int i=0; i<3; i++) {
        std::cout << testAlgo(selectionSort, items[i]) << ", ";
    }
    std::cout << "\n\n";

    std::cout << "\nINSERTION SORT MICROSECONDS: ";
    for (int i=0; i<3; i++) {
        std::cout << testAlgo(insertionSort, items[i]) << ", ";
    }
    std::cout << "\n\n";

    std::cout << "\nBUBBLE SORT MICROSECONDS: ";
    for (int i=0; i<3; i++) {
        std::cout << testAlgo(bubbleSort, items[i]) << ", ";
    }
    std::cout << "\n\n";

    std::cout << "\nMERGE SORT MICROSECONDS: ";
    for (int i=0; i<3; i++) {
        std::cout << testAlgo(mergeSort, items[i]) << ", ";
    }
    std::cout << "\n\n";
}
