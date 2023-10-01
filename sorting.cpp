#include "listResources.hpp"
#include "sortingAlgs.hpp"

Stopwatch sp = Stopwatch();
int64_t timeAlgo(void (*func)(std::vector<int>&), int items) {
    std::vector<int> list = generateList(-100, 100, items);
    sp.restart();
    func(list);
    return sp.duration();
}

int64_t timeAlgo(std::vector<int> (*func)(std::vector<int>&), int items) {
    std::vector<int> list = generateList(-100, 100, items);
    sp.restart();
    list = func(list);
    return sp.duration();
}

int64_t timeAlgo(void (*func)(std::vector<int>&, int, int), int items) {
    std::vector<int> list = generateList(-100, 100, items);
    sp.restart();
    func(list, 0, -1);
    return sp.duration();
} 

int main() {

    std::vector<int> items = generateOrderedIncrementedSet(1000, 5000, 1000);
    int tests = items.size();

    std::cout << "\nSELECTION SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(selectionSort, items[i]) << ", ";}
    std::cout << "\n\n";

    std::cout << "\nINSERTION SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(insertionSort, items[i]) << ", ";}
    std::cout << "\n\n";

    std::cout << "\nBUBBLE SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(bubbleSort, items[i]) << ", ";}
    std::cout << "\n\n";

    std::cout << "\nMERGE SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(mergeSort, items[i]) << ", ";}
    std::cout << "\n\n";

    std::cout << "\nQUICK SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(quickSort, items[i]) << ", ";}
    std::cout << "\n\n";

    std::cout << "\nHEAP SORT MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(heapSort, items[i]) << ", ";}
    std::cout << "\n\n";
}
