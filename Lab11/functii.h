#pragma once
#include <iostream>
#include <vector>
#include "pch.h"

using namespace std;

template <typename T>
void classicSort(vector<T>& vec) {
    size_t idx_i;
    size_t idx_j;
    bool swap_flag;
    idx_i = 0;
    for (; idx_i + 1 < vec.size(); ++idx_i) {
        for (idx_j = 0; idx_j + 1 < vec.size(); ++idx_j) {

            if (vec[idx_j] >= vec[idx_i]) {
                swap(vec[idx_j], vec[idx_i]);
                swap_flag = true;
            }
        }
    }
}

template <typename T>
void show(const vector<T>& vec) {
    size_t pos = 0;
    for (; pos < vec.size(); ) {
        cout << vec[pos] << " ";
        ++pos;
    }
    cout << endl;
}

template <typename T>
bool isSorted(const vector<T>& vec) {
    size_t pos = 0;
    for (; pos + 1 < vec.size(); ++pos) {
        if (vec[pos] > vec[pos + 1]) {
            return false;
        }
    }
    return true;
}
