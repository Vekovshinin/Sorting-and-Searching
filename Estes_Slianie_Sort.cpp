#include<iostream>
using namespace std;
void printMas(int mas[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}
void SortSeries(int* mas, int indexS1, int indexS2) {
	int insertIndex;
	bool flag = false;
	for (int i = 0; i <= indexS1; i++)//проход по первой серии
	{
		for (int j = indexS1 + 1; j <= indexS2; j++)//проход по второй серии
		{
			if (mas[i] >= mas[j])
			{
				insertIndex = j;
				flag = true;
			}
		}
		if (flag)
		{
			int tmp = mas[i];
			for (int k = i; k < insertIndex; k++)
			{
				mas[k] = mas[k + 1];
			}
			mas[insertIndex] = tmp;
			indexS1--;
			i--;
			flag = false;
		}
	}
}
void NaturalSort(int* mas, int size) {

	int s1 = mas[0], s2 = 0;
	int indexS1, indexS2;
	bool flag = true;
	for (int i = 1; i < size; i++)
	{
		if (s1 < mas[i] && flag)
		{
			s1 = mas[i];
			indexS1 = i;
		}
		else
		{
			if (s2 < mas[i] || flag) {
				flag = false;//s1 сформирован. начинаем формировать s2
				s2 = mas[i];
				indexS2 = i;
			}
			else
			{
				//с1 и с2 сформированы, далее необходимо сортировать эти серии
				SortSeries(mas, indexS1, indexS2);
				flag = true;
				s1 = mas[i - 1];
				indexS1 = i - 1;
				s2 = mas[i];
				indexS2 = i;
			}
		}
	}
	SortSeries(mas, indexS1, indexS2);//последний проход оставшихся с1 и с2
}
int main()
{
	setlocale(LC_ALL, "Ru");
	int n = 25;
	int* A = new int[n] {16, 51, 8, 15, 24, 2, 1, 12, 7, 10, 3, 1, 24, 45, 43, 22, 34, 4, 3, 3, 33, 43, 4, 23, 34};

	cout << "Исходный массив:\n";
	printMas(A, n);

	NaturalSort(A, n);

	cout << "Упорядоченный массив:\n";
	printMas(A, n);

	return 0;
}