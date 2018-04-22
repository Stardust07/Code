#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "function.h"

using namespace std;

BiTreeNode *constructBiTree(vector<int> list) {
    if (list.size() <= 0) { return NULL; }

    BiTreeNode *root = new BiTreeNode(list[0]);
    BiTreeNode *p = root;
    BiTreeNode *r = NULL;
    int i = 0;
    bool leftFinished = false;
    bool rightFinished = false;

    while ((2 * i + 1) < list.size()) {
        if (p) {
            if (list[2 * i + 1] != '#') {
                p->left = new BiTreeNode(list[2 * i + 1]);
            }
            if (((2 * i + 2) < list.size()) && (list[2 * i + 2] != '#')) {
                p->right = new BiTreeNode(list[2 * i + 2]);
            }
        }

        if (!leftFinished) {
            r = p;
            p = p->left;
            leftFinished = true;
        } else if (!rightFinished) {
            p = r->right;
            rightFinished = true;
        } else {
            p = r->left;
            //p = r->left;
            leftFinished = false;
            rightFinished = false;
        }

        ++i;
    }
    return root;
}

void printBiTree(BiTreeNode *root) {
    if (!root) { return; }
    
    queue<BiTreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        BiTreeNode *r = nodes.front();
        nodes.pop();

        if (r) {
            cout << r->val << " ";
            if (r->left || r->right) {
                nodes.push(r->left);
                nodes.push(r->right);
            }
        } else {
            cout << "#" << " ";
        }
    }
    cout << endl;
}

ListNode *constructLinkList(vector<int> list) {
    if (list.size() <= 0) { return NULL; }
    ListNode *head = new ListNode(list[0]);
    ListNode *p = head;
    for (int i = 1; i < list.size(); ++i, p = p->next) {
        p->next = new ListNode(list[i]);
    }
    return head;
}

void printLinkList(ListNode *head) {
    if (!head) { return; }

    ListNode *p = head;
    while (p->next) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << p->val << endl;
}

int main() {
    vector<int> arr = { 16, 7, 3, 20, 17, 8 };
    vector<vector<int>> arrs = {
        //{ 1, 2, 3, 4, 5, 6, 7 },
        //{ 2, 6, 7, 7, 8, 9, 9 },
        //{ 3, 4, 5, 6, 8, 9, 12 },
        //{ 8, 8, 8, 9, 9, 9, 12 },
        { 1 },
        { 2 },
        { 3 },

    };
    ListNode *linkList = constructLinkList({ 1, 2, 3, 4, 5, 6 });
    BiTreeNode *biTree = constructBiTree({ 8, 8, 10, 5, 7, 9, 11 });
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
    //cout << fibonacci(3);
    //cout << numberOf1InBinary(1);
    //cout << power(2, 3);
    //print1ToMaxOfNDigits(2);
    //deleteNode();
    //reorderOddEven(arr);
    //cout << findKthNodeToTail(linkList, 2)->val;
    //reverseList(linkList);
    //mergeSortedListRecursively();
    //mergeSortedList();
    //cout << hasSubtree();
    //mirrorRecursively();
    //mirror(biTree);
    //printMatrixInCircle(arrs);
    //21
    //cout << isPopOrder({ 1, 2, 3, 4, 5 }, { 4, 3, 5, 1, 2 });
    //printFromTopToBottom(biTree);
    cout << verifySequenceOfBST({ 4, 6, 7, 5 }, 0, 3);
    //25-31
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
    //meituan_real_count();

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
