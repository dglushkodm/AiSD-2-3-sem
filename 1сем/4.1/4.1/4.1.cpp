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
    int n, sum = 0;
    cout << "Введите кол-во товаров" << endl;
    cin >> n;
    int num = int(n / 2);
    int* A = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        *(A + i) = 1 + rand() % 50;
    }
   
    PuzirSort(n, A);
    int j = n - 1;
    if (n % 2 != 0)
    {
        j--;
    }
    for (int i = 0; i < num; i += 2)
    {
        swap(*(A + i), *(A + j));
        j -= 2;
    }

    cout << "Порядок пробивания на кассе: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(A + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i += 2)
    {
        sum += *(A + i);
    }
    cout << "Маскимальная сумма чека: " << sum << endl;
    delete[] A;
}