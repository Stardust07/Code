#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "function.h"

using namespace std;

ListNode *constructLinkList() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    return head;
}

int main() {
    vector<int> arr = { 16, 7, 3, 20, 17, 8 };
    vector<vector<int>> arrs = { 
        { 1, 2, 3, 4, 5, 6, 7 },
        { 2, 6, 7, 7, 8, 9, 9 },
        { 3, 4, 5, 6, 8, 9, 12 },
        { 8, 8, 8, 9, 9, 9, 12 },
    };
    ListNode *linkList = constructLinkList();

    // 基础排序算法
    //basic_bubbleSort(arr);
    //basic_selectSort(arr);
    //basic_insertSort(arr);
    //basic_shellSort(arr);
    //basic_quickSort(arr);
    //basic_mergeSort(arr);
    //basic_heapSort(arr);


    //cout << findInPartiallySortedMatrix(4, arrs);
    //replaceSpace("Hello world", 11);
    //printListFromTailToHead();
    //reConstructBinaryTree();
    //stackToQueue();
    //cout << minNumberInRotateArray({ 2, 3, 4, 1, 2 });
    //cout << fibonacci(4);
    //cout << numberOf1InBinary(1);
    //cout << power(2, 3);
    //print1ToMaxOfNDigits(2);
    //deleteNode();
    //reorderOddEven(arr);
    //cout << findKthNodeToTail(linkList, 2)->val;
    //reverseList(linkList);
    //mergeSortedListRecursively();
    //mergeSortedList();
    //18-31
    //cout << numberOf1Between1AndN(1000);
    //cout << numberOfBetween1AndN(1000);
    //33
    //cout << getUglyNumber(11);
    //35-67

    //cout << jumpFloorII(3);
    //cout << rectCover(3);
    //printTopK(arrs, 25);

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
    //getInfinityDomain();
    return 0;
}
