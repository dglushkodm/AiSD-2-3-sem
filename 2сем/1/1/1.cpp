#include <iostream>
#include <Windows.h>
using namespace std;
void hanoiTower(int n, int strart, int finish, int sup) {
    if (n == 1) {
        cout << "Диск 1 двигаем с " << strart << " на " << finish << endl;
        return;
    }
    hanoiTower(n - 1, strart, sup, finish);
    cout << "Диск " << n << " двигаем с " << strart << " на " << finish << endl;
    hanoiTower(n - 1, sup, finish, strart);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int disks, rods;
    cout << "Введите кол-во дисков: ";
    cin >> disks;
    cout << "Введите кол-во стержней: ";
    cin >> rods;

    if (disks < 1 || rods < 3) {
        cout << "Некоректный ввод" << endl;
        return 1;
    }

    hanoiTower(disks, 1, rods, 2);

    return 0;
}
