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

    // 基础排序算法
    //basic_bubbleSort(arr);
    //basic_selectSort();
    //basic_insertSort(arr);
    //basic_shellSort(arr);
    basic_quickSort(arr);
    //basic_mergeSort(arr);
    //basic_heapSort(arr);

    // 美团
    //meituan_test_assignCoins();
    //meituan_test_maxArea();
    //meituan_real_minWeightedAssign();
    //meituan_online_findPatitionIndex();

    // 网易
    //wangyi_test_placeBrick();
    //wangyi_test_arithmeticSequence();
    //wangyi_test_cross01Series();
    //wangyi_test_operationSeries();
    //wangyi_real_lostNiuniu();
    //wangyi_real_getNumberCountDividedBy3();
    
    // 滴滴
    //didi_online_greater();

    // 招行信用卡
    //zhaohang_real_stringConcat();
    //zhaohang_real_stringMatch();
    //zhaohang_real_integerPart();

    // 腾讯

    return 0;
}
