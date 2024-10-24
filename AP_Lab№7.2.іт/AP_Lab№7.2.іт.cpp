// Lab_7_2_1.cpp
// < Савицького Дениса >
// Лабораторна робота № 7.2.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 27
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int SearchMin(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -20;
    int High = 20;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    int minElement = SearchMin(a, n);
    cout << "min element in main diagonal = " << minElement << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SearchMin(int** a, const int n)
{
    // Ініціалізуємо мінімальний елемент першим елементом головної діагоналі
    int min = a[0][0];

    // Проходимо по головній діагоналі (де i == j)
    for (int i = 1; i < n; i++)
    {
        if (a[i][i] < min)
            min = a[i][i];
    }

    return min;
}