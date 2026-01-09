#include <iostream>
#include <Windows.h>
using namespace std;

void bubleSort(int*, int);
void print(int*, int);
void printStr(char*, int);
void swap(int&, int&);
int minimumFrom(int*, int, int);
void selectionSort(int*, int);
void insertSort(char*, int);
void quickSort(int*, int, int);
void shellSort(int*, int);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int size = 10;
	int ar[size] = { 9, 0, 8, 1, 7, 2, 6, 3, 5, 4 };

	cout << "Изначальный массив: " << endl;
	print(ar, size);

	quickSort(ar, 0, size - 1);
	cout << "\nОтсортированный массив : " << endl;
	print(ar, size);

	system("pause");
	return 0;
}


void bubleSort(int* m, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (m[j] > m[j + 1]) {
				int t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

void print(int* m, int n) {
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	cout << endl;
}

void printStr(char* m, int n) {
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	cout << endl;
}

void swap(int& first, int& second) {
	int t = first;
	first = second;
	second = t;
}

int minimumFrom(int* m, int position, int length) {
	int minIndex = position;
	for (int i = position + 1; i < length; i++) {
		if (m[i] < m[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}

void selectionSort(int* m, int length) {
	for (int i = 0; i < length - 1; i++) {
		swap(m[i], m[minimumFrom(m, i, length)]);
	}
}

void insertSort(char* m, int n) {
	for (int i = 1; i < n; i++) {
		char t = m[i];
		for (int j = i - 1; j > -1 & t < m[i]; j--) {
			m[j + 1] = m[j];
			m[j] = t;
		}
	}
}

void quickSort(int* m, int left, int right) {
	int leftArrow = left, rightArrow = right;
	int pivot = m[(left + right) / 2];

	do {
		while (m[rightArrow] > pivot) {
			rightArrow--;
		}
		while (m[leftArrow] < pivot) {
			leftArrow++;
		}

		if (leftArrow <= rightArrow) {
			swap(m[leftArrow], m[rightArrow]);
			leftArrow++;
			rightArrow--;
		}
	} while (rightArrow >= leftArrow);

	if (left < rightArrow) {
		quickSort(m, left, rightArrow);
	}
	if (leftArrow < right) {
		quickSort(m, leftArrow, right);
	}
}

void shellSort(int* m, int n) {
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = 0; j < n - i; j++) {
			for (int k = j; k > -1; k -= i) {
				if (m[k] > m[k + i]) {
					int t = m[k];
					m[k] = m[k + i];
					m[k + i] = t;
				}
				else {
					k = 0;
				}
			}
		}
	}
}