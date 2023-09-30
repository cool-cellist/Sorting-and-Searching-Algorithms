#include <vector>

int linearSearch(std::vector<int> list, target) {
  for (int i=0; i<list.size(); i++) {
    if (list.at(i)==target) {
      return i;
    }
  }
}
