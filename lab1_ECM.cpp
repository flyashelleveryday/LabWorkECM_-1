#include <iostream>
#include <iomanip>
using namespace std;

//unsigned char 
void printBinaryUC(unsigned char num) 
{
    unsigned char mask = 1 << 7;
    for (int i = 0; i < 8; i++) 
    {
        putchar((num & mask) ? '1' : '0');
        mask >>= 1;
    }
    cout << endl;
}
void changeBitsUC(unsigned char& num) 
{
    int count, pos, state;
    cout << "Сколько бит изменить? ";
    cin >> count;
    for (int i = 0; i < count; i++) 
    {
        cout << "Введите номер бита (0-7): ";
        cin >> pos;
        while (pos < 0 || pos > 7) 
        {
            cout << "Ошибка! Повторите ввод: ";
            cin >> pos;
        }
        cout << "Введите состояние (0 или 1): ";
        cin >> state;
        while (state != 0 && state != 1) 
        {
            cout << "Ошибка! Повторите ввод: ";
            cin >> state;
        }
        unsigned char mask = 1 << pos;
        if (state) 
        {
            num |= mask;
        }
        else 
        {
            num &= ~mask;
        }
    }
}
void workWithUC() 
{
    unsigned char num;
    cout << "Введите значение (0..255): ";
    int tmp; 
    cin >> tmp;
    num = (unsigned char)(tmp & 0xFF);

    int choice;
    do 
    {
        system("cls");
        cout << "Работа с unsigned char\n";
        cout << "Текущее значение: " << (int)num << "   двоично: ";
        printBinaryUC(num);

        cout << "1. Изменить биты\n";
        cout << "2. Ввести новое число\n";
        cout << "0. Назад\n>";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            changeBitsUC(num);
            break;
        case 2:
            cout << "Введите значение (0..255): ";
            cin >> tmp;
            num = (unsigned char)(tmp & 0xFF);
            break;
        }
        if (choice != 0) 
        {
            system("pause>nul");
        }
    } while (choice != 0);
}

//long double 
void printBinaryLD(long double num) 
{
    union 
    {
        long double value;
        unsigned char bytes[sizeof(long double)];
    } u;
    u.value = num;
    for (int i = sizeof(long double) - 1; i >= 0; i--) 
    {
        unsigned char mask = 1 << 7;
        for (int j = 0; j < 8; j++) 
        {
            putchar((u.bytes[i] & mask) ? '1' : '0');
            mask >>= 1;
        }
        cout << " ";
    }
    cout << endl;
}
void changeBitsLD(long double& num) 
{
    union 
    {
        long double value;
        unsigned char bytes[sizeof(long double)];
    } u;
    u.value = num;

    int totalBits = sizeof(long double) * 8;
    int count, pos, state;
    cout << "Сколько бит изменить? ";
    cin >> count;
    for (int i = 0; i < count; i++) 
    {
        cout << "Введите номер бита (0.." << totalBits - 1 << "): ";
        cin >> pos;
        while (pos < 0 || pos >= totalBits) 
        {
            cout << "Ошибка! Повторите ввод: ";
            cin >> pos;
        }
        cout << "Введите состояние (0 или 1): ";
        cin >> state;
        while (state != 0 && state != 1) 
        {
            cout << "Ошибка! Повторите ввод: ";
            cin >> state;
        }
        int byteIndex = pos / 8;
        int bitIndex = pos % 8;
        unsigned char mask = 1 << bitIndex;
        if (state) 
        {
            u.bytes[byteIndex] |= mask;
        }
        else 
        {
            u.bytes[byteIndex] &= ~mask;
        }
    }
    num = u.value;
}
void workWithLD() 
{
    long double num;
    cout << "Введите значение long double: ";
    cin >> num;

    int choice;
    do 
    {
        system("cls");
        cout << "Работа с long double\n";
        cout << "Текущее значение: " << num << endl;
        cout << "Двоичное представление:\n";
        printBinaryLD(num);

        cout << "\n1. Изменить биты\n";
        cout << "2. Ввести новое число\n";
        cout << "0. Назад\n>";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            changeBitsLD(num);
            break;
        case 2:
            cout << "Введите значение long double: ";
            cin >> num;
            break;
        }
        if (choice != 0) 
        {
            system("pause>nul");
        }
    } while (choice != 0);
}

// Главное меню 
int main() 
{
    setlocale(LC_ALL, "");
    int mode;
    do 
    {
        system("cls");
        cout << "С чем вы хотите работать?\n";
        cout << "1. unsigned char\n";
        cout << "2. long double\n";
        cout << "0. Выход\n>";
        cin >> mode;

        switch (mode) 
        {
        case 1:
            workWithUC();
            break;
        case 2:
            workWithLD();
            break;
        }
    } while (mode != 0);
    return 0;
}
