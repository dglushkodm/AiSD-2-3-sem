#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

struct map {
    string number;
    string surname;
    string name;
    string otchestvo;
    map* next;
};

const int Sizehex = 32;
map* hashtab[Sizehex];

unsigned int hashFunction(string str) {
    int sum = atoi(str.c_str());
    return sum % Sizehex;
}
void addElement() {
    setlocale(LC_ALL, "rus");
    string num;
    string surname;
    string name;
    string otchestvo;
    cout << "Введите номер телефона: ";
    cin >> num;
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите отчество: ";
    cin >> otchestvo;

    int key = hashFunction(num);
    map* first = hashtab[key];
    if (hashtab[key] != NULL) {
        while (first != NULL) {
            if (first->next == NULL) {
                first->next = new map;
                first->next->surname = surname;
                first->next->name = name;
                first->next->otchestvo = otchestvo;
                first->next->number = num;
                first->next->next = NULL;
                break;
            }
            first = first->next;
        }
    }
    else {
        hashtab[key] = new map;
        hashtab[key]->surname = surname;
        hashtab[key]->name = name;
        hashtab[key]->otchestvo = otchestvo;
        hashtab[key]->number = num;
        hashtab[key]->next = NULL;
    }
}

void findElement() {
    setlocale(LC_ALL, "rus");
    string number;
    cout << "Введите номер телефона: ";
    cin >> number;

    int key = hashFunction(number);
    map* first = hashtab[key];
    if (first != NULL) {
        if (hashtab[key]->number == "") {
            first = NULL;

        }
        unsigned int start = clock();
        while (first != NULL) {
            if (first->number == number) {
                cout << "Key: " << key << endl;
                cout << "ФИО: " << first->surname << " " << first->name << " " << first->otchestvo << endl;
                cout << "номер телефона : " << first->number << endl;
                break;
            }
            first = first->next;
        }
        unsigned int end = clock();
        unsigned int search = end - start;

        cout << endl << "Время поиска: " << search << "мс" << endl;
    }
    else
        cout << "нет такого номера" << endl;
}

void delElement() {
    setlocale(LC_ALL, "rus");
    string number;    
    cout << "Введите номер: ";
    cin >> number;
    int key = hashFunction(number);    
    map* first = hashtab[key];
    while (first->next != NULL) {
        if (first->next->number == number) {
            first->next->surname = "";
            first->next->name = "";            
            first->next->otchestvo = "";
            first->next->number = "";            
            if (first->next != NULL) {
                map* buf = first->next->next;                
                first->next->next = NULL;
                first->next = buf;
            }
            break;
        }
        else {
            first = first->next;
        }
    }
    if (first->next == NULL) {
        first->surname = "";        
        first->name = "";
        first->otchestvo= "";        
        first->number = "";
    }
}

void printElements() {
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < Sizehex; i++)
    {
        if (hashtab[i] != NULL)
        cout << "------------------------------" << i << "----------------------------------" << endl;
        if (hashtab[i] != NULL)
        {
            if (hashtab[i]->number != "") {
                cout << "ФИО: " << hashtab[i]->surname << " " << hashtab[i]->name << " " << hashtab[i]->otchestvo << endl<< "номер телефона : " << hashtab[i]->number << endl << "ключ: " << i << endl;

                if (hashtab[i]->next != NULL)
                {
                    map* temp = hashtab[i];
                    temp = temp->next;
                    while (temp != NULL)
                    {
                        cout << "ФИО: " << temp->surname << " " << temp->name << " " << temp->otchestvo << endl << "номер телефона : " << temp->number << endl << "ключ: " << i << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        if (hashtab[i] != NULL)
        cout << "-----------------------------------------------------------------"<< endl;
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int choice;
    do {
        cout << "1. Добавление элементов в хэш таблицу" << endl;
        cout << "2. Поиск элемента" << endl;
        cout << "3. Список элементов" << endl;
        cout << "4. Удаление элемента" << endl;
        cout << "5. Выход из программы" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: addElement(); break;
        case 2: findElement(); break;
        case 3: printElements(); break;
        case 4: delElement(); break;
        case 5: break;
        default:
            cout << "Только 1-5 пункты";
            break;
        }
    } while (choice != 5);
}