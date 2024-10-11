#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 9
using namespace std;
int main()
{
    int a[SIZE][SIZE]; 
    int d[SIZE]; 
    int v[SIZE]; 
    int temp, minindex, min;
    int begin_index;
    setlocale(LC_ALL, "Russian");
    cout << "введите начальную вершину" << endl;
    cin >> begin_index;
   
   
    
    for (int i = 0; i < SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            cout << "Введите расстояние " << i + 1 << "  -  "<< j + 1 << "  :";
            cin >>  temp;
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
   
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << a[i][j] << "    ";
        cout << endl;
    }
 
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
  
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { 
            if ((v[i] == 1) && (d[i] < min))
            { 
                min = d[i];
                minindex = i;
            }
        }
  
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    
    cout << endl << "Кратчайшие расстояния до вершин : " << endl;
    for (int i = 0; i < SIZE; i++)
        cout << i +1 << " :"<<  d[i] << "    ";

  
  
}