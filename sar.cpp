#include <chrono>
#include "listResources.hpp"
#include "sortingAlgs.hpp"

int main() {
    //prints list
    std::vector<int> list = generateList(-100, 100, 100);

    //prints unsorted list
    std::cout << "\n\nUNSORTED:\n";
    printList(list);

    //times the sorting algorithm
    auto start = std::chrono::steady_clock::now();
    insertionSort(list);

    //prints the sorted list
    std::cout << "\n\nSORTED:\n";
    printList(list);

    //prints the time taken
    auto dur = std::chrono::steady_clock::now()-start;
    std::cout << "\nMICROSECONDS: " << std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
}