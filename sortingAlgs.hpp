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

/*

basically split, then split, then split
then from there, return merge, return merge, and finally
return a merged list

in mergeSort
split "lower" and mergeSort
split "upper" and mergeSort
unless it cant be split...then you would return mergeSort(lower, upper)

in merge
cur1 = list1[0], cur2 = list2[0], vec = new vec
and while the vecsize does not equal the combined size of both lists, we merge it into the vec, checking which value to put in

*/

void mergeSort(std::vector<int>& list) {

}
