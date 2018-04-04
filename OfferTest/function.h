#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <map>
#include <string>
#include <stack>

#include <algorithm>

using namespace std;

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
    for (int i = 1; i < len; ++i) {
        int value = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            if (value < arr[j]) {
                arr[j + 1] = arr[j];
                arr[j] = value;
            } else {
                break;
            }
        }
    }
}

// 快速排序
void partition() {}

void basic_quickSort(vector<int> &arr) {}

// 归并排序
void merge();

void basic_mergeSort(vector<int> &arr) {}

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 非递归的先序遍历
vector<int> PreOrder(TreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<TreeNode*> s;
    vector<int> res;
    s.push(root);
    res.push_back(root->val);
    TreeNode* cur = root->left;
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
vector<int> InOrder(TreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<TreeNode*> s;
    vector<int> res;
    s.push(root);
    TreeNode* cur = root->left;
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
vector<int> PostOrder(TreeNode* root) {
    if (root == NULL) return vector<int>();
    stack<TreeNode*> s;
    stack<bool> isFirst;//存储是否是第一次被访问  
    vector<int> res;
    s.push(root);
    isFirst.push(true);
    TreeNode* cur = root->left;
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
// 替换空格
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

// 用两个栈实现队列
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
#pragma endregion ZHAOHANG_REAL

#pragma region TENCENT_REAL
void tencent_real_() {}

#pragma endregion TENCENT_REAL