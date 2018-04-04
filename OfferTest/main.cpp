#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "function.h"

using namespace std;
int main() {
    //vector<int> arr = { 7, 3, 2, 4, 5, 1, 6, 8, 6, 2 };
    vector<int> arr = { 16, 7, 3, 20, 17, 8 };
    //basic_bubbleSort(arr);
    //basic_selectSort();
    //basic_insertSort(arr);
    basic_heapSort(arr);

    //wangyi_test_placeBrick();
    //wangyi_test_arithmeticSequence();
    //wangyi_test_cross01Series();
    //wangyi_test_operationSeries();
    
    return 0;
}
