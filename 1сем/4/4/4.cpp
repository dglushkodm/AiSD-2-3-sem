#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void PuzirSort(int n, int chisla[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (chisla[j] > chisla[j + 1]) {
                int b = chisla[j];
                chisla[j] = chisla[j + 1];
                chisla[j + 1] = b;
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int n, first = 0, second = 0, third = 0, res = 0;
    cout << "Введите число участников: " << endl;
    cin >> n;
    int* A = new int[n];


    srand(time(NULL));

    cout << "Результаты участников: " << endl;
    for (int i = 0; i < n; i++)
    {
        *(A + i) = 1 + rand() % 100;
        cout << *(A + i) << " ";
    }
    PuzirSort(n, A);

    int max = A[n-1];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max) {
            max = A[i];
        }
    }
    first = max;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < max && A[i] > second) {
            second = A[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] < second && A[i] > third) {
            third = A[i];
        }
    }
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == first) {
            c1++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] == second) {
            c2++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] == third) {
            c3++;
        }
    }
   
    res = c1 + c2 + c3;
    cout << endl << "Кол-во призёров:" << res;
  
    delete[] A;
}