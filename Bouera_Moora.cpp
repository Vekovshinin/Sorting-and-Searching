#include <iostream>
#include <string>

using namespace std;

const int maxn = 100005;
const int maxm = 100005;

string text; // исходная строка в которой ищем подстроку
string pattern; // подстрока, которую ищем

int shift[maxm]; // таблица смещений
int n, m;

void prepare_shift() {
    for (int i = 0; i < maxm; i++) {
        shift[i] = m;
    }
    for (int i = 0; i < m; i++) {
        shift[pattern[i]] = m - i - 1; // заполняем таблицу смещений для символов подстроки
    }
}

// функция для поиска подстроки
int boyer_moore() {
    int i = 0;
    while (i <= n - m) { // идем по строке, но чтобы не выйти за границу массива
        int j = m - 1; // Индекс последнего элемента подстроки
        while (j >= 0 && text[i + j] == pattern[j]) { // ищем совпадение последнего символа подстроки с сиволом строки
            j--; // для проверки подстроки
        }
        if (j == -1) {
            return i; // найдено совпадение 
        }
        i += shift[text[i + j]]; // смещаем границу по таблице
    }
    return -1; // совпадений не найдено
}

int main()
{
    system("chcp 1251 > null");
    setlocale(LC_ALL, "Ru");
    cout << "Введите строку: ";
    getline(cin, text);
    cout << "Введите подстроку: ";
    cin >> pattern;
    n = text.length();
    m = pattern.length();
    prepare_shift();
    int pos = boyer_moore();
    if (pos == -1) {
        cout << "Подстрока не найдена(";
    }
    else {
        cout << "Подстрока найдена на позиции: " << pos << endl;
    }
    return 0;
}
