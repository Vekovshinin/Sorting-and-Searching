#include <iostream>
#include <vector>
#include <vector>

using namespace std;

// методы сортировки массивов
void BubbleSort(vector<int>& vect) { // метод пузырьком 
	if (vect.size() < 2) {
		return;
	}

	for (int i = 0; i < vect.size() - 1; i++) {
		for (int j = 0; j < vect.size() - i - 1; j++) {
			if (vect[j] > vect[j + 1]) {
				swap(vect[j], vect[j + 1]);
			}
		}
	}
}

void SelectionSort(vector<int>& vect) { // метод выбора
	if (vect.size() < 2) {
		return;
	}

	for (int i = 0; i < vect.size(); i++) {
		int LocalMinIndex = i;
		for (int j = i + 1; j < vect.size(); j++) {
			if (vect[LocalMinIndex] > vect[j]) {
				LocalMinIndex = j;
			}
		}
		swap(vect[i], vect[LocalMinIndex]);
	}
}

void InsertionSort(vector<int>& vect) { // метод вставки 
	if (vect.size() < 2) {
		return;
	}

	for (int i = 1; i < vect.size(); i++) {
		int currentIndex = i;
		int current = vect[currentIndex];
		for (; currentIndex >= 1 && vect[currentIndex - 1] > current; currentIndex--) {
			vect[currentIndex] = vect[currentIndex - 1];
		}
		vect[currentIndex] = current;
	}
}

// простые сортировки
void QuickSort(vector<int>& vect, int beginIndex, int pivotIndex) { // быстрая сортировка
	if (beginIndex < pivotIndex) {
		int currentIndex = beginIndex;
		for (int i = currentIndex; i < pivotIndex; i++) {
			if (vect[i] < vect[pivotIndex]) {
				swap(vect[i], vect[currentIndex++]);
			}
		}
		swap(vect[currentIndex], vect[pivotIndex]);
		QuickSort(vect, beginIndex, currentIndex - 1);
		QuickSort(vect, currentIndex + 1, pivotIndex);
	}
}

void QuickSort(vector<int>& vect) { // перегружаем функцию для удобства вызова 
	if (vect.size() > 1) {
		QuickSort(vect, 0, vect.size() - 1);
	}
}

void BucketSort(vector<int>& vect) { // блочная сортировка 
	if (vect.size() < 2) {
		return;
	}

	int mx = vect[0];
	int mn = vect[0];
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > mx) {
			mx = vect[i];
		}
		else if (vect[i] < mn) {
			mn = vect[i];
		}
	}

	int bucketsLenght = mx / 10 - mn / 10 + 1;
	vector<int>* buckets = new vector<int>[bucketsLenght] {};

	for (int i = 0; i < vect.size(); i++) {
		buckets[vect[i] / 10 - mn / 10].push_back(vect[i]);
	}

	for (int i = 0; i < bucketsLenght; i++) {
		QuickSort(buckets[i]);
	}

	int index = 0;
	for (int i = 0; i < bucketsLenght; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			vect[index++] = buckets[i][j];
		}
	}

	delete[] buckets;
}

void CountingSort(vector<int>& vect) { // сортировка подсчетом 
	if (vect.size() < 2) {
		return;
	}

	int mn = vect[0];
	int mx = vect[0];
	for (int i = 1; i < vect.size(); i++) {
		if (mx < vect[i]) {
			mx = vect[i];
		}
		else if (mn > vect[i]) {
			mn = vect[i];
		}
	}

	int countingArrLenght = mx - mn + 1;
	int* countingArr = new int[countingArrLenght] {};
	for (int i = 0; i < vect.size(); i++) {
		countingArr[vect[i] - mn]++;
	}

	int index = 0;
	for (int i = 0; i < countingArrLenght; i++) {
		for (int j = 0; j < countingArr[i]; j++) {
			vect[index++] = i + mn;
		}
	}

	delete[] countingArr;
}

void Merge(vector<int>& vect, int beginIndex, int endIndex, int middleIndex) { // сортировка слияния
	int leftIndex = beginIndex;
	int rightIndex = middleIndex + 1;
	int mergeArrLenght = endIndex - beginIndex + 1;
	int* mergeArr = new int[mergeArrLenght];

	for (int i = 0; i < mergeArrLenght; i++) {
		if (leftIndex <= middleIndex &&
			(rightIndex > endIndex || vect[leftIndex] < vect[rightIndex]))
		{
			mergeArr[i] = vect[leftIndex++];
		}
		else
		{
			mergeArr[i] = vect[rightIndex++];
		}
	}

	int currentIndex = beginIndex;
	for (int i = 0; i < mergeArrLenght; i++) {
		vect[currentIndex++] = mergeArr[i];
	}

	delete[] mergeArr;
}

void SliceAndMerge(vector<int>& vect, int beginIndex, int endIndex) { // функция для слияния 
	if (beginIndex < endIndex) {
		int middleIndex = (beginIndex + endIndex) / 2;
		SliceAndMerge(vect, beginIndex, middleIndex);
		SliceAndMerge(vect, middleIndex + 1, endIndex);
		Merge(vect, beginIndex, endIndex, middleIndex);
	}
}

void MergeSort(vector<int>& vect) { // перегружаем функцию для удобства вызова
	if (vect.size() > 1) {
		SliceAndMerge(vect, 0, vect.size() - 1);
	}
}

// сложные сортировки Хоара и Шелла
void HoareSort(vector<int>& vect, int beginIndex, int endIndex) { // сортировка Хоара 
	int pivot = vect[(beginIndex + endIndex) / 2];
	int leftIndex = beginIndex;
	int RightIndex = endIndex;

	while (leftIndex <= RightIndex) {
		while (vect[leftIndex] < pivot) {
			leftIndex++;
		}
		while (vect[RightIndex] > pivot) {
			RightIndex--;
		}
		if (leftIndex <= RightIndex) {
			swap(vect[leftIndex++], vect[RightIndex--]);
		}
	}
	if (beginIndex < RightIndex) {
		HoareSort(vect, beginIndex, RightIndex);
	}
	if (leftIndex < endIndex) {
		HoareSort(vect, leftIndex, endIndex);
	}
}

void HoareSort(vector<int>& vect) { // перегружаем функцию для удобства вызова
	if (vect.size() > 1) {
		HoareSort(vect, 0, vect.size() - 1);
	}
}

void ShellSort(vector<int>& vect) { // сортировка Шелла
	if (vect.size() < 2) {
		return;
	}

	for (int step = vect.size() / 2; step > 0; step /= 2) {
		for (int i = step; i < vect.size(); ++i) {
			for (int j = i - step; j >= 0 && vect[j] > vect[j + step]; j -= step) {
				swap(vect[j], vect[j + step]);
			}
		}
	}
}

void WriteVector(vector<int>& vect) { // функция печати вектора
	if (vect.size() > 0) {
		cout << vect[0];
	}
	for (int i = 1; i < vect.size(); i++) {
		cout << ' ' << vect[i];
	}
	cout << '\n';
}

bool IsEqualVectors(vector<int>& firstVect, vector<int>& secondVect) { // равные ли векторы по длине
	bool isEqual = firstVect.size() == secondVect.size();
	for (int i = 0; i < firstVect.size() && isEqual; i++) {
		isEqual = firstVect[i] == secondVect[i];
	}
	return isEqual;
}

bool IsSortAscendingVector(vector<int>& vect) { // функция отстортирован ли вектор
	if (vect.size() < 2) {
		return true;
	}

	bool isSort = true;
	for (int i = 1; i < vect.size() && isSort; i++) {
		isSort = vect[i - 1] <= vect[i];
	}
	return isSort;
}

typedef void(*ptr)(vector<int>&); // создание нового типа ptr

int main() {
	setlocale(LC_ALL, "Ru");
	ptr functionPointers[] = {
		&BubbleSort, &CountingSort, &SelectionSort,
		&InsertionSort, &ShellSort, &MergeSort,
		&BucketSort, &QuickSort, &HoareSort };
	int lenv;
	cout << "Введите количество элементов вектора: ";
	cin >> lenv;
	cout << "Введите элементы вектора: ";
	vector<int> vect;
	for (int i = 0; i < lenv; i++) {
		int a;
		cin >> a;
		vect.push_back(a);
	}
	for (ptr i : functionPointers) {
		i(vect);
		if (IsSortAscendingVector(vect)) {
			WriteVector(vect);
		}
	}
}