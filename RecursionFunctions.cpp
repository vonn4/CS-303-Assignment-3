#include "RecursionFunctions.h"

int recursiveLinearSearch(const std::vector<int>& vec, int target, int pos, int lastFound) {
    if (pos == vec.size()) return lastFound;
    if (vec[pos] == target) lastFound = pos;
    return recursiveLinearSearch(vec, target, pos + 1, lastFound);
}

void insertionSortRecursive(std::vector<int>& vec, int n) {
    if (n <= 1) return;
    insertionSortRecursive(vec, n - 1);
    int last = vec[n - 1];
    int j = n - 2;
    while (j >= 0 && vec[j] > last) {
        vec[j + 1] = vec[j];
        j--;
    }
    vec[j + 1] = last;
}
