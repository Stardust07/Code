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

    // ���������㷨
    //basic_bubbleSort(arr);
    //basic_selectSort();
    //basic_insertSort(arr);
    //basic_shellSort(arr);
    basic_quickSort(arr);
    //basic_mergeSort(arr);
    //basic_heapSort(arr);

    // ����
    //meituan_test_assignCoins();
    //meituan_test_maxArea();
    //meituan_real_minWeightedAssign();
    //meituan_online_findPatitionIndex();

    // ����
    //wangyi_test_placeBrick();
    //wangyi_test_arithmeticSequence();
    //wangyi_test_cross01Series();
    //wangyi_test_operationSeries();
    //wangyi_real_lostNiuniu();
    //wangyi_real_getNumberCountDividedBy3();
    
    // �ε�
    //didi_online_greater();

    // �������ÿ�
    //zhaohang_real_stringConcat();
    //zhaohang_real_stringMatch();
    //zhaohang_real_integerPart();

    // ��Ѷ

    return 0;
}
