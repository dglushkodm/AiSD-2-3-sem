#include <iostream> 
#include <time.h>
using namespace std;

int fib(int n)
{


    int c = 0, p = 1, q;
    
    
    for (int i = 1; i <= n; ++i)
    {
        cout << c << " ";
        q = c + p;
        p = c;
        c = q;
    }
    
    return c;

    
}
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 2) + fibo(n - 1);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    float t = 0.0, sek = 0, min = 0;
    cout << "n="; cin >> n;
    clock_t begin = clock();
    cout << fib(n) << " ";
    cout << endl;
    clock_t end = clock();
    t = end - begin;
    sek = t / 1000;
    min = floor(sek / 60);
    sek = sek - min * 60;
    cout << "время выполнения: " << min << " минут " << sek << " секунд " << endl;
    
   
    clock_t begin1 = clock();
    for (int i = 0; i <= n; ++i)
    {
        cout << fibo(i) << " ";
    }
    cout << endl;
    clock_t end1 = clock();
    t = end1 - begin1;
    sek = t / 1000;
    min = floor(sek / 60);
    sek = sek - min * 60;
    cout << "время выполнения: " << min << " минут " << sek << " секунд " << endl;
    return 0;

    
    
    cout << endl;
}
