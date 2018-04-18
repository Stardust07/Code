#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <map>
#include <string>
#include <stack>

#include <algorithm>

using namespace std;

#pragma region DATA_STRUCTURE
struct BiTreeNode {
    int val;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#pragma endregion DATA_STRUCTURE

#pragma region BASIC_SORT
// 经典排序算法
// 冒泡排序
void basic_bubbleSort(vector<int> &arr) {
    int len = arr.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 选择排序
void basic_selectSort(vector<int> &arr) {
    int len = arr.size();
    for (int i = 0; i < len; ++i) {
        int minValue = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < minValue) {
                minIndex = j;
                minValue = arr[j];
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
}

// 插入排序
void basic_insertSort(vector<int> &arr) {
    int len = arr.size();
    for (int i = 1; i < len; ++i) {
        int value = arr[i];
        int j = i - 1;
        for (; (j >= 0) && (value < arr[j]); --j) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}

// 希尔排序
void basic_shellSort(vector<int> &arr) {
    int len = arr.size();
    int shellFactor = len / 3;

    while (shellFactor >= 1) {
        for (int i = shellFactor; i < len; ++i) {
            int value = arr[i];
            int j = i - shellFactor;
            for (; (j >= 0) && (value < arr[j]); j -= shellFactor) {
                arr[j + shellFactor] = arr[j];
            }
            arr[j + shellFactor] = value;
        }

        shellFactor /= 2;
    }
}

// 快速排序
int partition(vector<int> &arr, int left, int right) {
    auto swapInArray = [&](int l, int r) {
        int value = arr[l];
        arr[l] = arr[r];
        arr[r] = value;
    };
    int pivot = arr[left];
    int tail = right;
    int head = left;

    while (tail > head) {
        while ((arr[tail] >= pivot) && (tail > head)) { --tail; }
        if (tail <= head) { break; }
        swapInArray(head, tail);
        ++head;
        while ((arr[head] <= pivot) && (tail > head)) { ++head; }
        if (tail <= head) { break; }
        swapInArray(tail, head);
        --tail;
    }
    return tail;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (right - left <= 0) { return; }
    int index = partition(arr, left, right);
    quickSort(arr, left, index - 1);
    quickSort(arr, index + 1, right);
}

void basic_quickSort(vector<int> &arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// 归并排序
void merge(vector<int> &arr, vector<int> &left, vector<int> &right) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < left.size() + right.size()) {
        if (i >= left.size()) {
            arr[k] = right[j];
            ++j;
        } else if (j >= right.size()) {
            arr[k] = left[i];
            ++i;
        } else {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                ++i;
            } else {
                arr[k] = right[j];
                ++j;
            }
        }
        ++k;
    }
}

void basic_mergeSort(vector<int> &arr) {
    if (arr.size() <= 1) {
        return;
    }
    vector<int> left;
    vector<int> right;

    int mid = floor(arr.size() / 2);
    for (int i = 0; i < arr.size(); ++i) {
        if (i < mid) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }
    basic_mergeSort(left);
    basic_mergeSort(right);
    merge(arr, left, right);
}

// 堆排序
void swapInArray(vector<int> &arr, int l, int r) {
    int value = arr[l];
    arr[l] = arr[r];
    arr[r] = value;
}

void adjustHeap(vector<int> &arr, int i, int n) {
    if (2 * i + 2 < n) {
        if ((arr[2 * i + 1] > arr[2 * i + 2]) && (arr[2 * i + 1] > arr[i])) {
            swapInArray(arr, 2 * i + 1, i);
            adjustHeap(arr, 2 * i + 1, n);
        } else if ((arr[2 * i + 2] > arr[2 * i + 1]) && (arr[2 * i + 2] > arr[i])) {
            swapInArray(arr, 2 * i + 2, i);
            adjustHeap(arr, 2 * i + 2, n);
        }
    } else if (2 * i + 1 < n) {
        if (arr[2 * i + 1] > arr[i]) {
            swapInArray(arr, 2 * i + 1, i);
            adjustHeap(arr, 2 * i + 1, n);
        }
    }
}

void buildMaxHeap(vector<int> &arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        adjustHeap(arr, i, n);
    }
}

void basic_heapSort(vector<int> &arr) {
    int len = arr.size();
    buildMaxHeap(arr, len);
    for (int j = 0; j < len; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;

    for (int i = len - 1; i > 0; --i) {
        swapInArray(arr, 0, i);
        adjustHeap(arr, 0, i);
        for (int j = 0; j < len; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
        //cout << arr.size() << endl;
    }
}

// 基数排序


// 桶排序


// 计数排序
#pragma endregion BASIC_SORT

#pragma region BITREE_OPERATION
// 二叉树
// 非递归的先序遍历
vector<int> PreOrder(BiTreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<BiTreeNode*> s;
    vector<int> res;
    s.push(root);
    res.push_back(root->val);
    BiTreeNode* cur = root->left;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL)//遍历左子节点直到叶子节点  
        {
            s.push(cur);
            res.push_back(cur->val);
            cur = cur->left;
        }
        cur = s.top()->right;//将当前节点设为最近右子节点  
        s.pop();
    }
    return res;
}

// 非递归的中序遍历
vector<int> InOrder(BiTreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<BiTreeNode*> s;
    vector<int> res;
    s.push(root);
    BiTreeNode* cur = root->left;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top()->right;
        res.push_back(s.top()->val);//在弹栈时访问根节点  
        s.pop();
    }
    return res;
}

// 非递归的后序遍历
vector<int> PostOrder(BiTreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<BiTreeNode*> s;
    stack<bool> isFirst;//存储是否是第一次被访问  
    vector<int> res;
    s.push(root);
    isFirst.push(true);
    BiTreeNode* cur = root->left;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            isFirst.push(true);
            cur = cur->left;
        }
        if (isFirst.top())//如果第一次被访问更新标记，更新当前节点为右子树  
        {
            isFirst.pop();
            isFirst.push(false);
            cur = s.top()->right;
        } else//如果已经被访问过一次，则返回值且弹出  
        {
            res.push_back(s.top()->val);
            isFirst.pop();
            s.pop();
        }
    }
    return res;
}
#pragma endregion BITREE_OPERATION

#pragma region ONLINE_TEST
// 刷题
// 03.二维数组中的查找
bool findInPartiallySortedMatrix(int target, vector<vector<int> > arr) {
    int j = arr[0].size() - 1;
    for (int i = 0; i < arr.size(); ++i) {
        for (; j >= 0; --j) {
            if (arr[i][j] <= target) {
                break;
            }
        }
        if (j < 0) { return false; }
        if (arr[i][j] == target) { return true; }
    }
    return false;
}

// 04.替换空格
void replaceSpace(char *str, int length) {
    string s(str);
    ostringstream oss;
    int len = length;
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (isblank(*i)) {
            oss << "%20";
            len += 2;
        } else {
            oss << *i;
        }
    }
    str = (char *)realloc(str, len * sizeof(char));
    strcpy(str, oss.str().c_str());
}

// 05.从尾到头打印链表
vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> values;
    ListNode *p = head;
    for (; p != NULL; p = p->next) {
        values.push(p->val);
    }
    int len = values.size();
    vector<int> res(len);
    for (int i = 0; i < len; ++i) {
        res[i] = values.top();
        values.pop();
    }
    return res;
}

// 06.重建二叉树(先序和中序)
BiTreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    BiTreeNode *root = NULL;

    if (pre.size() > 0) {
        vector<int> preLeft;
        vector<int> preRight;
        vector<int> vinLeft;
        vector<int> vinRight;

        int index = vin.size();
        for (int i = 0; i < vin.size(); ++i) {
            if (vin[i] == pre[0]) {
                index = i;
            }
            if (i < index) {
                vinLeft.push_back(vin[i]);
                preLeft.push_back(pre[i + 1]);
            } else if (i > index) {
                vinRight.push_back(vin[i]);
                preRight.push_back(pre[i]);
            }
        }
        root = new BiTreeNode(pre[0]);
        root->left = reConstructBinaryTree(preLeft, vinLeft);
        root->right = reConstructBinaryTree(preRight, vinRight);
    }
    return root;
}

// 07.用两个栈实现队列
void stackToQueue() {
    stack<int> stack1;
    stack<int> stack2;

    auto pop = [&]()->int {
        int x = stack1.top();
        stack1.pop();
        return x;
    };
    auto push = [&](int node) {
        int count = stack1.size();

        for (int i = 0; i < count; ++i) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        for (int i = 0; i < count; ++i) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    };
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        push(x);
    }
    for (int i = 0; i < n; ++i) {
        cout << pop() << " ";
    }
}

// 08.旋转数组的最小数字
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() <= 0) {
        return 0;
    }
    int lo = 0;
    int hi = rotateArray.size() - 1;
    int mid = lo;

    while (rotateArray[lo] >= rotateArray[hi]) {
        if (hi - lo == 1) { return rotateArray[hi]; }

        mid = (lo + hi) / 2;
        if ((rotateArray[mid] == rotateArray[lo]) && (rotateArray[mid] == rotateArray[hi])) {
            int ret = rotateArray[lo];
            for (int i = lo + 1; i <= hi; ++i) {
                ret = min(ret, rotateArray[i]);
            }
            return ret;
        }

        if ((rotateArray[mid] >= rotateArray[lo])) {
            lo = mid;
        } else if ((rotateArray[mid] <= rotateArray[hi])) {
            hi = mid;
        }
    }
    return rotateArray[mid];
}

// 09.斐波拉契数列
int fibonacci(int n) {
    int pre1, pre2;
    pre1 = 1;
    pre2 = 0;
    for (int i = 1; i < n; ++i) {
        int temp = pre1;
        pre1 += pre2;
        pre2 = temp;
    }
    return (pre1 + pre2);
}

// 变态青蛙跳台阶
int jumpFloorII(int number) {
    vector<int> dp(number + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= number; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j];
        }
    }
    return dp[number];
}

// 10.二进制中1的个数
int numberOf1InBinary(int n) {
    int count = 0;

    //unsigned int flag = 1;
    //while (flag <= n) {
    //    if (n & flag) {
    //        ++count;
    //    }
    //    flag <<= 1;
    //}

    while (n) {
        ++count;
        n &= (n - 1);
    }

    return count;
}


// 11.数值的整数次方
double powWithUnsignedExponent(double base, int exponent) {
    //if (exponent == 0) {
    //    return 1.0;
    //}
    //if (exponent == 1) {
    //    return base;
    //}
    //double result = powWithUnsignedExponent(base, exponent >> 1);
    //result *= result;
    //if (exponent & 0x1 == 1) {
    //    result *= base;
    //}
    //return result;

    stack<int> indices;
    for (int i = exponent; i >= 1; i >>= 1) {
        indices.push(i);
    }
    double result = 1.0;
    int len = indices.size();
    for (int i = 0; i < len; ++i) {
        int e = indices.top();
        result *= result;
        if (e & 0x1 == 1) { result *= base; }
        indices.pop();
    }
    return result;
}

double power(double base, int exponent) {
    double res = 1.0;

    if (abs(base - 0.0) <= 0.0000001 && exponent < 0) {
        // 特殊情况：底数为零指数为负
        return 0.0;
    }

    res = powWithUnsignedExponent(base, abs(exponent));

    res = (exponent < 0) ? (1 / res) : res;
    return res;
}

// 12.打印1到最大的n位数(递归)
void printStringNumber(char *str) {
    int len = strlen(str);
    bool firstZero = true;
    for (int i = 0; i < len; ++i) {
        if (firstZero && (str[i] == '0')) {
            continue;
        }
        firstZero = false;
        cout << str[i];
    }
    if (!firstZero) { cout << endl; }
}

void print1ToMaxOfNDigitsRecursively(char *prefix, int length, int index) {
    if (index == length) {
        printStringNumber(prefix);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        prefix[index] = i + '0';
        print1ToMaxOfNDigitsRecursively(prefix, length, index + 1);
    }
}

void print1ToMaxOfNDigits(int n) {
    char *str = new char[n + 1];
    str[n] = '\0';
    print1ToMaxOfNDigitsRecursively(str, n, 0);
}


// 13.在O（1）时间删除链表结点
ListNode *deleteNode(ListNode *head, ListNode *toBeDeleted) {
    if (toBeDeleted == head) {
        head = toBeDeleted->next;
        delete toBeDeleted;
    } else if (toBeDeleted->next == NULL) {
        ListNode *p = head;
        while (p->next != toBeDeleted) {
            p = p->next;
        }
        p->next = NULL;
        delete toBeDeleted;
    } else {
        ListNode *next = toBeDeleted->next;
        toBeDeleted->val = next->val;
        toBeDeleted->next = next->next;
        delete next;
    }

    return head;
}

// 14.调整数组顺序使奇数位于偶数前面
void reorderOddEven(vector<int> &arr) {
    auto swapInArray = [&](int l, int r) {
        int value = arr[l];
        arr[l] = arr[r];
        arr[r] = value;
    };
    if (arr.size() <= 1) { return; }

    int head = 0;
    int tail = arr.size() - 1;
    while (head < tail) {
        while ((head < tail) && (arr[head] % 2 != 0)) { ++head; }
        while ((head < tail) && (arr[tail] % 2 == 0)) { --tail; }
        swapInArray(head, tail);
    }
}

// 15.链表中倒数第k个结点
ListNode *findKthNodeToTail(ListNode *head, int k) {
    if ((head == NULL) || (k <= 0)) { return NULL; }
   
    ListNode *p = head;
    for (int i = 1; (i < k) && (p != NULL); ++i, p = p->next) {

    }
    if (p == NULL) {
        return NULL;
    }
    ListNode *q = head;
    while (p->next != NULL) {
        p = p->next;
        q = q->next;
    }
    return q;
}

// 16.反转链表
ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = NULL;
    ListNode *reverseHead = NULL;

    while (cur != NULL) {
        reverseHead = cur;
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return reverseHead;
}

// 17.合并两个排序的链表(递归)
ListNode *mergeSortedListRecursively(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL) {
        return pHead2;
    } else if (pHead2 == NULL) {
        return pHead1;
    }
    ListNode *head = NULL;
    if (pHead1->val < pHead2->val) {
        head = pHead1;
        head->next = mergeSortedListRecursively(pHead1->next, pHead2);
    } else {
        head = pHead2;
        head->next = mergeSortedListRecursively(pHead1, pHead2->next);
    }
    return head;
}

// 17.合并两个排序的链表(非递归)
ListNode *mergeSortedList(ListNode *pHead1, ListNode *pHead2) {
    ListNode *p = pHead1;
    ListNode *q = pHead2;

    if (p == NULL) {
        return pHead2;
    } else if (q == NULL) {
        return pHead1;
    }
    ListNode *head = NULL;
    ListNode *curNode = NULL;
    if (p->val < q->val) {
        head = pHead1;
        p = p->next;
    } else {
        head = pHead2;
        q = q->next;
    }
    curNode = head;

    while (p != NULL && q != NULL) {
        if (p->val < q->val) {
            curNode->next = p;
            p = p->next;
        } else {
            curNode->next = q;
            q = q->next;
        }
        curNode = curNode->next;
    }

    if (p == NULL) {
        curNode->next = q;
    } else {
        curNode->next = p;
    }
    return head;
}

// 18.树的子结构
bool hasSubtree(BiTreeNode *root, BiTreeNode *sub) {
    if (!root) { return false; }
    if (!sub) { return true; }

    if (root->val == sub->val) {

    }

    return false;
}

// 32.从1到n整数中1出现的次数
int numberOf1Between1AndN(unsigned int n) {

    return 0;
}

// 32.从1到n整数中包含1的整数的个数
int numberOfBetween1AndN(unsigned int n) {
    ostringstream oss;
    oss << n;
    string str = oss.str();
    int len = str.length();
    cout << str << endl;
    if (len == 1) {
        return ((str[0] == '0') ? 0 : 1);
    }
    int result = 0;
    int highDigit = n / static_cast<int>(pow(10, len - 1));
    if (highDigit > 1) {
        result += (highDigit - 1) * (static_cast<int>(pow(10, len - 1)) - static_cast<int>(pow(9, len - 1)));
        result += static_cast<int>(pow(10, len - 1));
        result += numberOfBetween1AndN(n - highDigit * static_cast<int>(pow(10, len - 1)));
    } else {
        result += static_cast<int>(pow(10, len - 1)) - static_cast<int>(pow(9, len - 1));
        result += n - highDigit * static_cast<int>(pow(10, len - 1)) + 1;
    }
    return result;
}

// 34.丑数
int getUglyNumber(int index) {
    if (index <= 0) { return 0; }
    vector<int> uglyNumbers(index);
    uglyNumbers[0] = 1;

    int count = 1;
    int maxMultiple2Index = 0;
    int maxMultiple3Index = 0;
    int maxMultiple5Index = 0;
    while (count < index) {
        int a = uglyNumbers[maxMultiple2Index] * 2;
        int b = uglyNumbers[maxMultiple3Index] * 3;
        int c = uglyNumbers[maxMultiple5Index] * 5;
        uglyNumbers[count] = min(a, min(b, c));

        while (uglyNumbers[maxMultiple2Index] * 2 <= uglyNumbers[count]) { ++maxMultiple2Index; }
        while (uglyNumbers[maxMultiple3Index] * 3 <= uglyNumbers[count]) { ++maxMultiple3Index; }
        while (uglyNumbers[maxMultiple5Index] * 5 <= uglyNumbers[count]) { ++maxMultiple5Index; }

        ++count;
    }

    return uglyNumbers[index - 1];
}

// 矩形覆盖
int rectCover(int number) {
    vector<int> dp(number + 1);
    if (number <= 0) {
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= number; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[number];
}

// 打印N个数组整体最大的topK
struct HeapNode {
    int value;
    int arrNum;
    int index;

    HeapNode() :value(0), arrNum(-1), index(-1) {}
    HeapNode(int v, int a, int i) :value(v), arrNum(a), index(i) {}
};

void heapify(vector<HeapNode> &heap, int root, int heapSize) {
    auto swapInHeap = [&](int l, int r) {
        HeapNode node = heap[l];
        heap[l] = heap[r];
        heap[r] = node;
    };
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int largest = root;
    while (left < heapSize) {
        if ((left < heapSize) && (heap[left].value > heap[root].value)) {
            largest = left;
        }
        if ((right < heapSize) && (heap[right].value > heap[largest].value)) {
            largest = right;
        }
        if (largest == root) { break; }
        swapInHeap(root, largest);
        root = largest;
        left = 2 * root + 1;
        right = 2 * root + 2;
    }
}

void heapInsert(vector<HeapNode> &heap, int leaf) {
    HeapNode node = heap[leaf];
    while (leaf > 0) {
        int root = (leaf - 1) / 2;
        if (heap[root].value >= node.value) {
            break;
        }
        heap[leaf] = heap[root];
        leaf = root;
    }
    heap[leaf] = node;
}

void printTopK(vector<vector<int>> matrix, int topK) {
    int numOfArrs = matrix.size();
    if (numOfArrs <= 0) { return; }

    int heapSize = numOfArrs;
    vector<HeapNode> maxTopHeap(heapSize);

    for (int i = 0; i < heapSize; ++i) {
        int index = matrix[i].size() - 1;
        maxTopHeap[i] = HeapNode(matrix[i][index], i, index);
        heapInsert(maxTopHeap, i);
    }
    int k = 0;
    while (k < topK) {
        cout << maxTopHeap[0].value << " ";
        //for (int i = 0; i < heapSize; ++i) {
        //    cout << maxTopHeap[i].value << " ";
        //}
        //cout << endl;
        int arr = maxTopHeap[0].arrNum;
        int index = maxTopHeap[0].index;
        if (index > 0) {
            maxTopHeap[0] = HeapNode(matrix[arr][index - 1], arr, index - 1);
        } else {
            maxTopHeap[0] = maxTopHeap[--heapSize];
        }
        heapify(maxTopHeap, 0, heapSize);

        ++k;
    }
}
#pragma endregion ONLINE_TEST

#pragma region MEITUAN_TEST
// 美团练习
// 分硬币
void meituan_test_assignCoins() {
    int opts[] = { 1, 5, 10, 20, 50, 100 };

    auto findOpt = [&](int x)->bool {
        for (auto i = 0; i < 6; ++i) {
            if (x == opts[i]) { return true; }
        }
        return false;
    };

    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 6; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j - opts[i] < 0) { continue; }
            dp[j] += dp[j - opts[i]];
        }
    }

    cout << dp[n];
}

// 计算矩形最大面积
long calculateArea(int s, int t, vector<int> height) {
    int n = t - s + 1;
    if (n == 0) { return 0; }
    //if (n == 1) { return height[0]; }
    long result = 0;
    int index = s;
    if (n >= 1) {
        int minValue = height[s];
        for (int i = s; i <= t; ++i) {
            if (height[i] < minValue) {
                index = i;
                minValue = height[i];
            }
        }
        result = minValue * n;
    }
    result = max(result, calculateArea(s, index - 1, height));
    result = max(result, calculateArea(index + 1, t, height));
    return result;
}

void meituan_test_maxArea() {
    int n;
    cin >> n;
    vector<int> height(n, 0);
    //int minValue = 1000000;
    long result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
        //minValue = min(minValue, height[i]);
    }
    //result = minValue * n;
    result = calculateArea(0, n - 1, height);

    cout << result;
}
#pragma endregion MEITUAN_TEST

#pragma region MEITUAN_REAL
// 美团白板编程
// 找到升序序列划分的位置
void meituan_online_findPatitionIndex() {
    int len = 9;
    int arr[] = { 3, 4, 5, 6, 7, 8, 9, 1, 2 };
    int start = 0, end = len - 1;
    int mid = 0;
    while (end - start > 1) {
        mid = (end + start) / 2;
        if ((arr[mid] < arr[start]) && (arr[mid] < arr[end])) {
            end = mid;
        } else if ((arr[mid] > arr[start]) && (arr[mid] > arr[end])) {
            start = mid;
        }
    }
    int result = (arr[mid] < arr[0]) ? (len - mid) : (len - mid - 1);
    cout << result;
}

// 美团笔试
// 找到重要城市配对的最小权重
int costX(vector<int> src, vector<vector<int>> minCost) {
    if (src.size() == 2) {
        return minCost[src[0]][src[1]];
    }
    for (auto i = 0; i < src.size(); ++i) {
        for (auto j = 0; j < src.size(); ++j) {
            if (src[i] == src[j]) {
                continue;
            }
            vector<int> cop;
            for (auto k = 0; k < src.size(); ++k) {
                if (src[i] == src[k] || src[j] == src[k]) {
                    continue;
                }
                cop.push_back(src[k]);
            }

            return costX({ src[i],src[j] }, minCost) + costX(cop, minCost);
        }
    }
}

void meituan_real_minWeightedAssign() {
    const int MaxValue = 100 * 10001;
    int n, kNum;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] < 0) {
                matrix[i][j] = MaxValue;
            }
        }
    }
    cin >> kNum;
    vector<int> vital(kNum * 2);
    vector<bool> selected(kNum * 2, false);
    for (int i = 0; i < 2 * kNum; ++i) {
        cin >> vital[i];
        --vital[i];
    }
    int cost = 0;
    vector<vector<int>> minCost(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minCost[i][j] = matrix[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (minCost[i][j] > minCost[i][k] + minCost[k][j]) {
                    minCost[i][j] = minCost[i][k] + minCost[k][j];
                }
            }
        }
    }

    //for (int k = 0; k < kNum; ++k) {
    //    int minC = MaxValue;
    //    int u = -1, v = -1;
    //    for (int i = 0; i < 2 * kNum - 1; ++i) {
    //        if (selected[i]) {
    //            continue;
    //        }
    //        for (int j = i + 1; j < 2 * kNum; ++j) {
    //            if (selected[j]) {
    //                continue;
    //            }
    //            if (minCost[i][j] < minC) {
    //                minC = minCost[i][j];
    //                u = i;
    //                v = j;
    //            }
    //        }
    //    }
    //    selected[u] = true;
    //    selected[v] = true;
    //    cost += minC;
    //}

    cout << costX(vital, minCost);
}
#pragma endregion MEITUAN_REAL

#pragma region WANGYI_TEST
// 网易练习1
// 彩色的砖块
void wangyi_test_placeBrick() {
    char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
        'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    string s;
    cin >> s;
    map<char, int> numbers;
    for (int i = 0; i < sizeof(letters);++i) {
        numbers[letters[i]] = 0;
    }
    for (auto i = s.begin(); i != s.end(); ++i) {
        ++numbers[*i];
    }
    int colorCount = 0;
    for (int i = 0; i < sizeof(letters); ++i) {
        if (numbers[letters[i]] > 0) {
            ++colorCount;
        }
    }
    if (colorCount <= 0) {
        cout << 1;
    } else if (colorCount <= 1) {
        cout << 1;
    } else if (colorCount <= 2) {
        cout << 2;
    } else {
        cout << 0;
    }
}

// 等差数列
void wangyi_test_arithmeticSequence() {
    bool possible = true;
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    if (len <= 1) { possible = true; }
    int d = arr[1] - arr[0];
    for (int i = 1; i < len - 1; ++i) {
        if (arr[i + 1] - arr[i] != d) { possible = false; break; }
    }
    if (possible) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }
}

// 交错01串
void wangyi_test_cross01Series() {
    string s;
    cin >> s;

    vector<int> subStringLen(s.size(), 0);
    subStringLen[0] = 1;
    int last = s[0] - '0';
    int len = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (last + s[i] - '0' == 1) {
            subStringLen[i] = subStringLen[i - 1] + 1;
            len = max(len, subStringLen[i]);
        } else {
            subStringLen[i] = 1;
        }
        last = s[i] - '0';
    }
    cout << len;
}

// 操作序列
void wangyi_test_operationSeries() {}
#pragma endregion WANGYI_TEST

#pragma region WANGYI_REAL
// 网易笔试
// 迷路的牛牛
void wangyi_real_lostNiuniu() {
    // NESW
    int n;
    cin >> n;
    //vector<int> status(n, 0);
    char choice;
    int status = 0;
    for (int i = 0; i < n; ++i) {
        cin >> choice;
        if (choice == 'R') {
            ++status;
            status = (status + 4) % 4;
        } else if (choice == 'L') {
            --status;
            status = (status + 4) % 4;
        }
    }
    switch (status) {
    case 0:cout << "N"; break;
    case 1:cout << "E"; break;
    case 2:cout << "S"; break;
    case 3:cout << "W"; break;
    default:
        break;
    }
}

// 被3整除的数字序列
int wangyi_real_getNumberCountDividedBy3() {
    int l, r;
    cin >> l >> r;

    auto getSum = [](int n)->int {
        int m = n % 3;
        int t = n / 3;
        return (t * 2 + m / 2);
    };

    cout << getSum(r) - getSum(l - 1) << endl;

    return 0;
}
#pragma endregion WANGYI_REAL

#pragma region DIDI_REAL
// 滴滴白板编程
void didi_online_greater() {
    vector<int> arr = { 8, 4, 8, 5, 3, 3, 1 };


    int i = arr.size() - 1;
    for (; (i > 0) && (arr[i] <= arr[i - 1]); --i) {}
    --i;
    int insertValue = arr[i];
    int j = i + 1;
    for (; j < arr.size(); ++j) {
        if (arr[j] < insertValue) {
            arr[i] = arr[j - 1];
            arr[j - 1] = insertValue;
            break;
        }
    }
    arr[j - 1] = insertValue;
    int k = 0;
    auto it = arr.begin();
    for (; it != arr.end(); ++it, ++k) {
        if (k == i) { break; }
    }


    sort(it + 1, arr.end());

    for (auto i = arr.begin(); i != arr.end(); ++i) {
        cout << *i;
    }
}
#pragma endregion DIDI_REAL

#pragma region ALIBABA_REAL
// 求最大公约数
int commonDivisor(int m, int n) {
    int i;
    for (i = m; i >= 1; i--) {
        if (m % i == 0 && n % i == 0) { break; }
    }
    return i;
}

// HR姐姐能看到的人数
void alibaba_online_shineStar() {
    int n;
    cin >> n;

    long r = 3;
    for (int i = 2; i <= n; ++i) {
        r += 2;
        for (int j = 2; j < i; ++j) {
            if (commonDivisor(j, i) == 1) {
                r += 2;
            }
        }
    }
    cout << r;
}
#pragma endregion ALIBABA_REAL

#pragma region ZHAOHANG_REAL
// 招行笔试
// 可以首尾连接成字符串的最大子串
void zhaohang_real_stringConcat() {
    string str;
    cin >> str;
    int len = str.length();
    int subLen = 0;

    for (int i = 0; i < len - 1; ++i) {
        ostringstream oss;
        if (len % (i + 1) != 0) {
            continue;
        }
        string sub = str.substr(0, i + 1);
        for (int j = 0; j < len / (i + 1); ++j) {
            oss << sub;
        }
        if (str.compare(oss.str()) == 0) {
            subLen = i + 1;
        }
    }
    if (subLen > 0) {
        cout << str.substr(0, subLen);
    } else {
        cout << "false";
    }
}

// 输入能够两两匹配的n对括号（未ac）
void zhaohang_real_stringMatch() {
    int n;
    cin >> n;

    string s;
    int endIndex = n - 1;
    int startIndex = endIndex + 1;
    for (auto i = 0; i <= endIndex; ++i) {
        s += '(';
    }
    for (auto i = startIndex; i < 2 * n; ++i) {
        s += ')';
    }
    cout << s;

    bool found = false;

    do {
        s[endIndex] = ')';
        s[startIndex] = '(';

        //cout << startIndex << " " << endIndex;
        cout << "," << s;
        found = false;
        if (startIndex <= 2) { break; }
        for (auto i = s.length() - 3; i > 0; --i) {
            if (s[i] == '(') {
                endIndex = i;
                startIndex = i + 1;
                found = true;
                break;
            }
        }
    } while (found && startIndex > 1);

}

// 大整数分解，使得乘积最大
void zhaohang_real_integerPart() {
    int n;
    cin >> n;

    int result = 0;
    switch (n) {
    case 1: result = 0; break;
    case 2: result = 1; break;
    case 3: result = 2; break;
    default:
        break;
    }
    int a, b;
    if (n >= 4) {
        if (n % 2) {
            a = ((n - 3) % 6) / 2;
            b = ((n - 3) / 6) * 2 + 1;
            result = pow(2, a) * pow(3, b);
        } else {
            a = (n % 6) / 2;
            b = (n / 6) * 2;
            result = pow(2, a) * pow(3, b);
        }
    }
    cout << result;
}

void zhaohang_real_chess() {
    const int MOD = 1000000007;
    const int xBound = 8;
    const int yBound = 9;
    int moveNum;
    cin >> moveNum;

    int x, y;
    cin >> x >> y;

    vector<vector<vector<int>>> dp(xBound + 1, vector<vector<int>>(yBound + 1, vector<int>(moveNum + 1, 0)));

    dp[0][0][0] = 1;
    for (int k = 1; k <= moveNum; ++k) {
        for (int i = 0; i <= xBound; ++i) {
            for (int j = 0; j <= yBound; ++j) {
                if (i >= 1) {
                    if (j >= 2) {
                        dp[i][j][k] += dp[i - 1][j - 2][k - 1];
                        dp[i][j][k] %= MOD;
                    } 
                    if (j <= yBound - 2) {
                        dp[i][j][k] += dp[i - 1][j + 2][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
                if (i >= 2) {
                    if (j >= 1) {
                        dp[i][j][k] += dp[i - 2][j - 1][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                    if (j <= yBound - 1) {
                        dp[i][j][k] += dp[i - 2][j + 1][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
                if (i <= xBound - 1) {
                    if (j >= 2) {
                        dp[i][j][k] += dp[i + 1][j - 2][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                    if (j <= yBound - 2) {
                        dp[i][j][k] += dp[i + 1][j + 2][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
                if (i <= xBound - 2) {
                    if (j >= 1) {
                        dp[i][j][k] += dp[i + 2][j - 1][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                    if (j <= yBound - 1) {
                        dp[i][j][k] += dp[i + 2][j + 1][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[x][y][moveNum];

}
#pragma endregion ZHAOHANG_REAL

#pragma region TENCENT_REAL
// 翻转数列
void tencent_real_reverseArray() {
    long long n, m;
    cin >> n >> m;

    long long mid = n / (2 * m);
    long long mid_value = m * m;
    long long result = mid * mid_value;
    cout << result;
}

// 小Q的歌单
void tencent_real_songList() {
    const int MOD = 1000000007;
    int n;
    cin >> n;

    int l1, l2, n1, n2;
    cin >> l1 >> n1 >> l2 >> n2;

    vector<int> len(n1 + n2);
    for (int i = 0; i < n1; ++i) {
        len[i] = l1;
    }
    for (int i = n1; i < n1 + n2; ++i) {
        len[i] = l2;
    }
    vector<vector<int>> results(n1 + n2, vector<int>(n + 1));
    for (int i = 0; i < n1 + n2; ++i) {
        results[i][0] = 1;
    }
    results[0][len[0]] = 1;

    for (int i = 1; i < n1 + n2; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j - len[i] >= 0) {
                results[i][j] += results[i - 1][j - len[i]];
            }
            results[i][j] += results[i - 1][j];
            results[i][j] %= MOD;
        }
    }
    cout << results[n1 + n2 - 1][n];
}

// 安排机器(未ac)
void tencent_real_assignMachine() {
    int n, m;
    cin >> n >> m;
    vector<int> machineTime(n);
    vector<int> machineLevel(n);
    vector<int> taskTime(m);
    vector<int> taskLevel(m);
    for (int i = 0; i < n; ++i) {
        cin >> machineTime[i] >> machineLevel[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> taskTime[i] >> taskLevel[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {

        if (taskLevel[0] <= machineLevel[i] && taskTime[0] <= machineTime[i]) {
            dp[1][i + 1] = 1;
        }
    }
    //for (int i = 0; i < length; ++i) {
    //    for (int j = 0; j < length; ++j) {

    //    }
    //}
    //cout << dp[]
}

void tencent_real_assignMachine();

// 微众银行
// 有限域
bool isPrime(int x, vector<int> &primes) {
    for (int i = 0; primes[i] * primes[i] <= x; ++i) { //用primes中存储的素数做为试除因子。 
        if (x % primes[i] == 0) { return false; }
    }
    return true;
}

vector<int> countPrimes(int n) {
    vector<int> primes;
    if (n < 2) { return primes; }

    if (n >= 2) { // 2是第一个素数
        primes.push_back(2);
    }

    for (int i = 3; i <= n; ++i) {
        if (isPrime(i, primes)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int getInfinityDomain() {
    int n;
    cin >> n;

    int result = 0;

    if (n <= 0) { return 0; }
    vector<int> primes = countPrimes(n);

    for (int i = 0; i < primes.size(); ++i) {
        for (int k = 2; pow(primes[i], k) <= n; ++k) {
            ++result;
        }
    }
    result += primes.size();
    cout << result;
    return result;
}

#pragma endregion TENCENT_REAL