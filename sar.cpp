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

int main() {
    //prints list
    Stopwatch sp = Stopwatch();
    std::vector<int> list = generateList(-100, 100, 1000);
    //times the sorting algorithm
    sp.restart();
    selectionSort(list);
    //prints the time taken
    std::cout << "\nSELECTION SORT MICROSECONDS: " << sp.duration() <<"\n\n";



    //prints list
    list = generateList(-100, 100, 1000);
    //times the sorting algorithm
    sp.restart();
    insertionSort(list);
    //prints the time taken
    std::cout << "\nINSERTION SORT MICROSECONDS: " << sp.duration() <<"\n\n";



    //prints list
    list = generateList(-100, 100, 1000);
    //times the sorting algorithm
    sp.restart();
    bubbleSort(list);
    //prints the time taken
    std::cout << "\nBUBBLE SORT MICROSECONDS: " << sp.duration() <<"\n\n";

    //prints list
    list = generateList(-100, 100, 1000);
    //times the sorting algorithm
    sp.restart();
    list = mergeSort(list);
    //prints the time taken
    std::cout << "\nMERGE SORT MICROSECONDS: " << sp.duration() <<"\n\n";
}
