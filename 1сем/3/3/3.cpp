
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
void ViborSort(int n, int chisla[]) {
    int min, buf;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (chisla[j] < chisla[min]) ? j : min;
        if (i != min) {
            buf = chisla[i];
            chisla[i] = chisla[min];
            chisla[min] = buf;
        }
        
    }
    cout << "Массив в отсортированном виде: ";

    for (int i = 0; i < n; i++) {
        cout << chisla[i] << " "; 
    }
    cout << endl;
}
void PuzirSort(int n, int chisla[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (chisla[j] > chisla[j + 1]) {
                int b = chisla[j]; 
                chisla[j] = chisla[j + 1]; 
                chisla[j + 1] = b;
            }
        }
    }

    cout << "Массив в отсортированном виде: ";

    for (int i = 0; i < n; i++) {
        cout << chisla[i] << " "; 
    }
    cout << endl;
}
void ShellSort(int n, int chisla[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = chisla[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < chisla[j - step])
                    chisla[j] = chisla[j - step];
                else
                    break;
            }
            chisla[j] = tmp;
        }
    cout << "Массив в отсортированном виде: ";

    for (int i = 0; i < n; i++) {
        cout << chisla[i] << " ";
    }
    cout << endl;
}
void quicksort(int l, int r, int* E)
{
    int leftside = l, rightside = r;
    int opora = E[(leftside + rightside) / 2];
    while (leftside <= rightside)
    {
        while (E[leftside] < opora)
            leftside++;
        while (E[rightside] > opora)
            rightside--;
        if (leftside <= rightside)
            swap(E[leftside++], E[rightside--]);
    }
    if (l < rightside)
        quicksort(l, rightside, E);
    if (r > leftside)
        quicksort(leftside, r, E);
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];
    int* C = new int[n];
    int* D = new int[n];
    int* E = new int[n];
    

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 1000;
        *(B + i) = rand() % 1000;
        *(C + i) = rand() % 1000;
        *(D + i) = rand() % 1000;
        *(E + i) = rand() % 1000;
        
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    double start_time1 = clock();
    PuzirSort(n, B);
    double end_time1 = clock();
    double result_time1 = end_time1 - start_time1;
    cout << endl;
    double start_time2 = clock();
    ShellSort(n, C);
    double end_time2 = clock();
    double result_time2 = end_time2 - start_time2;
    cout << endl;
    double start_time3 = clock();
    ViborSort(n, D);
    double end_time3 = clock();
    double result_time3 = end_time3 - start_time3;
    cout << endl;
    double start_time4 = clock();
    quicksort(0, n-1, E);
    double end_time4 = clock();
    double result_time4 = end_time4 - start_time4;
    cout << "Массив в отсортированном виде: ";
    for (int i = 0; i < n; i++) {
        cout << E[i] << " "; 
    }
    cout << endl;
    



    printf("Время выполнения пузырьковой сортировкой: %.2lf милисекунд(ы)\n", result_time1);
    printf("Время выполнения сортировкой методом Шелла: %.2lf милисекунд(ы)\n", result_time2);
    printf("Время выполнения сортировкой выбора: %lf милисекунд(ы)\n", result_time3);
    printf("Время выполнения быстрой сортировкой: %lf милисекунд(ы)\n", result_time4);

    
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;
}