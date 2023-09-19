//Made by Jason
//jbrycebuyag@gmail.com

#include <vector>
#include <iostream>

void selectionSort(std::vector<int>& list) {
    for (int i=0; i<list.size(); i++) {
        int* minimum = &list.at(i);
        for (int j=i; j<list.size(); j++) {
            if (*minimum>list.at(j)) {minimum = &list.at(j);}
        }
        int temp = *minimum;
        *minimum = list.at(i);
        list.at(i) = temp;
    }
}

void insertionSort(std::vector<int>& list) {
    for (int i=1; i<list.size(); i++) {
        for (int j=i; ( (j>0) && (list.at(j)<list.at(j-1)) ); j--) { 
            int temp = list.at(j);
            list.at(j) = list.at(j-1);
            list.at(j-1) = temp;
        }
    }
}

void bubbleSort(std::vector<int>& list) {
    for (int i=list.size(); i>0; i--) {
        for (int j=0; j<i-1; j++) {
            if ((list.at(j))>(list.at(j+1))) {
                int temp = list.at(j);
                list.at(j) = list.at(j+1);
                list.at(j+1) = temp;
            }
        }
    }
}

//std::vector<int> merge(std::vector<int>& list1, std::vector<int>& list2) {
//    bool startList1 = false;
    //if (list1.at(i)) {}
//}

void mergeSort(std::vector<int>& list) {

}
