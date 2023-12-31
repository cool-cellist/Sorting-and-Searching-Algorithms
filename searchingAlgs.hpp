#include <vector>
#include <cmath>

int linearSearch(std::vector<int>& list, int target) {
  for (int i=0; i<list.size(); i++) {
    if (list.at(i)==target) {
      return i;
    }
  }
  return -1;
}

int binarySearch(std::vector<int>& list, int target) {
  int left = 0, right = list.size()-1;
  int middle = 0;

  while (left <= right) {
    middle = (left+right)/2;
    if (list.at(middle) == target) {
      return middle;
    } else if (list.at(middle) < target) {
      left = middle+1;
    } else {
      right = middle-1;
    }
  }

  return -1;
}

int ternarySearch(std::vector<int>& list, int target) {
  int left = 0, right = list.size()-1;
  int mid1 = 0, mid2 = 0;

  while (left <= right) {
    mid1 = left+(right-left)/3;
    mid2 = right-(right-left)/3;

    if (list.at(mid1)==target) {
      return mid1;
    } else if (list.at(mid2)==target) {
      return mid2;
    }

    if (list.at(mid1) > target) {
      right = mid1-1;
    } else if (list.at(mid2) < target) {
      left = mid2+1;
    } else {
      left = mid1+1;
      right = mid2-1;
    }
  }

  return -1;
}

int exponentialSearch(std::vector<int>& list, int target) {
  if (list.at(0)==target) {return 0;}

  int i = 1;
  while (i<list.size() && list.at(i)<target) {i *= 2;}

  int left=i/2, right = (i>list.size()-1 ? list.size() : i);
  int middle = 0;

  while (left<=right) {
    middle = (left+right)/2;
    if (list.at(middle)==target) {return middle;}
    else if (list.at(middle)>target) {right=middle-1;}
    else {left=middle+1;}
  }

  return -1;
}

int jumpSearch(std::vector<int>& list, int target) {
  int root = (int)sqrt((double)list.size());

  int i = 0;
  while (i<list.size() && list.at(i)<target) {i+=root;}
  
  for (i-=root; i<i+root; i++) {
    if (list.at(i)==target) {return i;}
  } return -1;
}
