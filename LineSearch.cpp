
#include <iostream>

using namespace std;

int lineSearch(int mas[], int key, const int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] == key) {
            cnt += 1;

        }
    }
    return cnt;
}

int binarySerch(int mas[], const int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mas[mid] == key) {
            return mid;
        }
        else {
            if (mas[mid] < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int itera_Serch(int mas[], const int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (((key - mas[left])*(right - left)) / (mas[right] - mas[left]));
        if (mas[mid] == key) {
            return mid;
        }
        else {
            if (mas[mid] < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int n = 5;
    int mas[n] = { 12, 11, 12, 2, 38 };
    int key;
    cout << "Массив: ";
    for (int i = 0; i < n; i++){
        cout << mas[i] << ' ';
    }
    cout << endl << "Введите ключ: ";
    cin >> key;
    cout << "Ответ (линейный поиск, количество элементов): " << lineSearch(mas, key, n);

    int mas2[n];
    cout << endl << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> mas2[i];
    }
    int key2;
    cout << endl << "Введите ключ: ";
    cin >> key2;

    int index = binarySerch(mas2, n, key2);
    if (index == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент находится на позиции: " << index + 1 << endl;
    }
    int key3;
    cout << endl << "Введите ключ: ";
    cin >> key3;

    int index2 = itera_Serch(mas2, n, key3);
    if (index == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент находится на позиции: " << index2 + 1 << endl;
    }
    return 0;
}
