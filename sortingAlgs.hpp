//Made by Jason
//jbrycebuyag@gmail.com

#include <vector>
#include <iostream>
#include <functional>

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

std::vector<int> merge(std::vector<int>& list1, std::vector<int>& list2) {
    int cur1 = 0, cur2 = 0;  std::vector<int> constructedList;
    while ((constructedList.size())!=(list1.size()+list2.size())) {
        if (list1.at(cur1)<list2.at(cur2)) {
            constructedList.push_back(list1.at(cur1));
            cur1++;
            if (cur1==list1.size()) {
                constructedList.insert(constructedList.end(), list2.end()-(list2.size()-cur2), list2.end());
                break;
            }
        } else {
            constructedList.push_back(list2.at(cur2));
            cur2++;
            if (cur2==list2.size()) {
                constructedList.insert(constructedList.end(), list1.end()-(list1.size()-cur1), list1.end());
                break;
            }
        }
    }

    return constructedList;
}

std::vector<int> mergeSort(std::vector<int>& list) {
    if (list.size()==1) {
        return list;
    }

    size_t mid = list.size()/2;
    std::vector<int> lowerhalf(list.begin(), list.begin()+mid);
    std::vector<int> upperhalf(list.begin()+mid, list.end());

    lowerhalf = mergeSort(lowerhalf);
    upperhalf = mergeSort(upperhalf);
    
    return merge(lowerhalf, upperhalf);

}
