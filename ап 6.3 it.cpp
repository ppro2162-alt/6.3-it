#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ---------- Виведення масиву ----------
void PrintArray(const int* a, const int size);
template <typename T>
void PrintArray(const T* a, const int size);

// ---------- Обмін двох елементів ----------
void SwapElements(int& x, int& y);
template <typename T>
void SwapElements(T& x, T& y);

// ---------- Пошук індексу максимального елемента ----------
int FindMaxIndex(const int* a, const int size, const int start);
template <typename T>
int FindMaxIndex(const T* a, const int size, const int start);

// ---------- Впорядкування за незростанням ----------
void SortNonIncreasing(int* a, const int size);
template <typename T>
void SortNonIncreasing(T* a, const int size);

int main()
{
    const int n = 10;

    int a[n] = { 3, 9, 1, 7, 5, 10, 2, 8, 4, 6 };
    cout << "Before (int):    ";
    PrintArray(a, n);
    cout << endl;
    SortNonIncreasing(a, n);
    cout << "After  (int):    ";
    PrintArray(a, n);
    cout << endl << endl;

    int a2[n] = { 3, 9, 1, 7, 5, 10, 2, 8, 4, 6 };
    cout << "Before (T=int):  ";
    PrintArray<int>(a2, n);
    cout << endl;
    SortNonIncreasing<int>(a2, n);
    cout << "After  (T=int):  ";
    PrintArray<int>(a2, n);
    cout << endl << endl;

    double b[n] = { 3.3, 9.9, 1.1, 7.7, 5.5, 10.0, 2.2, 8.8, 4.4, 6.6 };
    cout << "Before (double): ";
    PrintArray<double>(b, n);
    cout << endl;
    SortNonIncreasing<double>(b, n);
    cout << "After  (double): ";
    PrintArray<double>(b, n);
    cout << endl << endl;

    string c[n] = { "3", "9", "1", "7", "5", "10", "2", "8", "4", "6" };
    cout << "Before (string): ";
    PrintArray<string>(c, n);
    cout << endl;
    SortNonIncreasing<string>(c, n);
    cout << "After  (string): ";
    PrintArray<string>(c, n);
    cout << endl;

    return 0;
}

// ================= PrintArray =================
void PrintArray(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
}

template <typename T>
void PrintArray(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
}

// ================= SwapElements =================
void SwapElements(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

template <typename T>
void SwapElements(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}

// ================= FindMaxIndex =================
int FindMaxIndex(const int* a, const int size, const int start)
{
    int maxIndex = start;
    for (int i = start + 1; i < size; i++)
        if (a[i] > a[maxIndex])
            maxIndex = i;
    return maxIndex;
}

template <typename T>
int FindMaxIndex(const T* a, const int size, const int start)
{
    int maxIndex = start;
    for (int i = start + 1; i < size; i++)
        if (a[i] > a[maxIndex])
            maxIndex = i;
    return maxIndex;
}

// ================= SortNonIncreasing =================
void SortNonIncreasing(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int m = FindMaxIndex(a, size, i);
        SwapElements(a[i], a[m]);
    }
}

template <typename T>
void SortNonIncreasing(T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int m = FindMaxIndex<T>(a, size, i);
        SwapElements<T>(a[i], a[m]);
    }
}