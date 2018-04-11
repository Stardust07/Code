#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "function.h"

using namespace std;

int main() {
    vector<int> arr = { 7, 3, 2, 4, 5, 1, 6, 8, 6, 2 };
    //vector<int> arr = { 16, 7, 3, 20, 17, 8 };
    //vector<int> arr = { 3, 5, 7, 8, 12, 12, 13, 14 };
    vector<vector<int>> arrs = { 
        { 1, 2, 3, 4, 5, 6, 7 },
        { 2, 6, 7, 7, 8, 9, 9 },
        { 3, 4, 5, 6, 8, 9, 12 },
        { 8, 8, 8, 9, 9, 9, 12 },
    };
    // 基础排序算法
    //basic_bubbleSort(arr);
    //basic_selectSort();
    //basic_insertSort(arr);
    basic_shellSort(arr);
    //basic_quickSort(arr);
    //basic_mergeSort(arr);
    //basic_heapSort(arr);

    //replaceSpace("Hello", 5);
    //stackToQueue();
    //cout << minNumberInRotateArray(arr);
    //cout << fibonacci(4);
    //cout << jumpFloorII(3);
    //cout << rectCover(3);
    //cout << numberOf1Between1AndN(12);
    //cout << numberOf1InBinary(1);
    //cout << getUglyNumber(11);
    //printTopK(arrs, 25);
    //print1ToMaxOfNDigits(2);

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
    //zhaohang_real_chess();

    // 腾讯
    //tencent_real_reverseArray();
    //tencent_real_songList();
    //tencent_real_assignMachine();
    return 0;
}
