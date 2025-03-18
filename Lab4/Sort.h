#pragma once
class Sort
{
    int* v;
    int dimensiune_vector;
public:
    Sort(int nr, int mini, int maxi);
    Sort();
    Sort(int* a, int nr);
    Sort(int count, ...);
    Sort(char* c);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void QuickSort1(int a, int b, bool c);
    int partitie(int a, int b, bool c);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
