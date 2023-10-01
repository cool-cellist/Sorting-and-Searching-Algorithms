#include "listResources.hpp"
#include "searchingAlgs.hpp"
#include "sortingAlgs.hpp"

Stopwatch sp = Stopwatch();

int64_t timeAlgo(int (*func)(std::vector<int>&, int), int items, bool needsSorted) {
    std::vector<int> list = generateOrderedSet(items, -100, 100);
    shuffle(list);
    sp.restart();
    if (needsSorted) {heapSort(list);}
    func(list, 50);
    return sp.duration();
}

int main() {
    std::vector<int> items = generateOrderedIncrementedSet(1000, 5000, 1000);
    int tests = items.size();
    
    std::cout << "LINEAR SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(linearSearch, items[i], true) << ", ";}
    std::cout << "\n\n";
}
