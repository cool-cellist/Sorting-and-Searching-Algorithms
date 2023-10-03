#include "listResources.hpp"
#include "searchingAlgs.hpp"
#include "sortingAlgs.hpp"

nanoStopwatch sp = nanoStopwatch();

int64_t timeAlgo(int (*func)(std::vector<int>&, int), int items, bool needsSorted) {
    std::vector<int> list = generateList(-100, 100, items);
    list.push_back(101);
    if (needsSorted==true) {heapSort(list);}
    sp.restart();
    int index = func(list, 101);
    
    //if (index>-1) {std::cout << "INDEX: " << index << " ";}

    return sp.duration();
}

int main() {
    std::vector<int> items = generateOrderedIncrementedSet(1000, 5000, 1000);
    int tests = items.size();
    
    std::cout << "LINEAR SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(linearSearch, items[i], false) << ", ";}
    std::cout << "\n\n";

    std::cout << "BINARY SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(binarySearch, items[i], true) << ", ";}
    std::cout << "\n\n";

    std::cout << "TERNARY SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(ternarySearch, items[i], true) << ", ";}
    std::cout << "\n\n";
}
