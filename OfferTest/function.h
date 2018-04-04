#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <map>
#include <string>

#include <algorithm>

using namespace std;

#pragma region BASIC_SORT
// æ≠µ‰≈≈–ÚÀ„∑®
// √∞≈›≈≈–Ú
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

// —°‘Ò≈≈–Ú
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

// ≤Â»Î≈≈–Ú
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

// œ£∂˚≈≈–Ú
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

// øÏÀŸ≈≈–Ú
void partition() {}

void basic_quickSort(vector<int> &arr) {}

// πÈ≤¢≈≈–Ú
void merge();

void basic_mergeSort(vector<int> &arr) {}

// ∂—≈≈–Ú
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

// ª˘ ˝≈≈–Ú


// Õ∞≈≈–Ú


// º∆ ˝≈≈–Ú
#pragma endregion BASIC_SORT

#pragma region MEITUAN_TEST
// √¿Õ≈¡∑œ∞
// ∑÷”≤±“
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

// º∆À„æÿ–Œ◊Ó¥Û√Êª˝
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
// √¿Õ≈∞◊∞Â±‡≥Ã
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
#pragma endregion MEITUAN_REAL

#pragma region WANGYI_TEST
// Õ¯“◊¡∑œ∞1
// ≤ …´µƒ◊©øÈ
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

// µ»≤Ó ˝¡–
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

// Ωª¥Ì01¥Æ
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

// ≤Ÿ◊˜–Ú¡–
void wangyi_test_operationSeries() {}
#pragma endregion WANGYI_TEST

