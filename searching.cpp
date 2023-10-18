#include "listResources.hpp" //contains my custom functions for testing
#include "searchingAlgs.hpp" //has the searching algorithm functions
#include "sortingAlgs.hpp" //has the sorting algorithm functions

nanoStopwatch sp = nanoStopwatch(); //uses a nano stopwatch, since milliseconds does not provide enough information

//times the algorithm and returns the duration.  takes the searching algorithm, items to test with, and if it needs the list to be sorted
int64_t timeAlgo(int (*func)(std::vector<int>&, int), int items, bool needsSorted) {
    std::vector<int> list = generateList(-100, 100, items);
    list.push_back(101); //will search for 101 at the end of the list for consistent worst-case scenarios
    if (needsSorted==true) {heapSort(list);}
    sp.restart();
    func(list, 101);
    return sp.duration();
}

int main() {
    std::vector<int> items = generateOrderedIncrementedSet(1000, 5000, 1000); //1000, 2000, 3000, 4000, and 5000 items to test with/
    int tests = items.size(); //the 'items' vector will be in a loop, so this is needed
    
    std::cout << "LINEAR SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(linearSearch, items[i], false) << ", ";}
    std::cout << "\n\n";

    std::cout << "BINARY SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(binarySearch, items[i], true) << ", ";}
    std::cout << "\n\n";

    std::cout << "TERNARY SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(ternarySearch, items[i], true) << ", ";}
    std::cout << "\n\n";

    std::cout << "EXPONENTIAL SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(exponentialSearch, items[i], true) << ", ";}
    std::cout << "\n\n";

    std::cout << "JUMP SEARCH MICROSECONDS: ";
    for (int i=0; i<tests; i++) {std::cout << timeAlgo(jumpSearch, items[i], true) << ", ";}
    std::cout << "\n\n";
}
