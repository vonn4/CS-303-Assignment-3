#ifndef RECURSIONFUNCTIONS_H
#define RECURSIONFUNCTIONS_H

#include <vector>

int recursiveLinearSearch(const std::vector<int>& vec, int target, int pos = 0, int lastFound = -1);
void insertionSortRecursive(std::vector<int>& vec, int n);

#endif // RECURSIONFUNCTIONS_H
