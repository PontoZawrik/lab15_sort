#pragma once
#include "../../utils/utils/utils.h"
#include <iostream>
using namespace std;

bool isStrDigit(char*);

struct Train {
	char destination[40];
	int trainNum;
	int departureTime[2];

	bool inputTime(char* string) {
		char d[] = ".,:-";
		char* p = strtok(string, d);
		int i = 0;
		bool success = true;

		while (isStrDigit(p) && i < 2) {
			this->departureTime[i] = atoi(p);
			p = strtok(NULL, d);
			i++;
		}
		if (i < 2) {
			success = false;
		}

		return success;
	}
};

bool isStrDigit(char* string) {
	if (!string) {
		return false;
	}
	int size = strlen(string);

	bool result = true;
	for (int i = 0; i < size; i++) {
		if (!isdigit(string[i])) {
			result = false;
			break;
		}
	}

	return result;
}


void quickSort(double* m, int left, int right) {
	int leftArrow = left, rightArrow = right;
	double pivot = m[(left + right) / 2];

	do {
		while (m[rightArrow] > pivot) {
			rightArrow--;
		}
		while (m[leftArrow] < pivot) {
			leftArrow++;
		}

		if (leftArrow <= rightArrow) {
			mySwap(m[leftArrow], m[rightArrow]);
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

void insertSort(char* m, int n) {
	for (int i = 1; i < n; i++) {
		char t = m[i];
		for (int j = i - 1; j > -1 & t < m[j]; j--) {
			m[j + 1] = m[j];
			m[j] = t;
		}
	}
}

void shellSort_num(Train* m, int n) {
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = 0; j < n - i; j++) {
			for (int k = j; k > -1; k -= i) {
				if (m[k].trainNum < m[k + i].trainNum) {
					mySwap(m[k], m[k + i]);
				}
				else {
					k = 0;
				}
			}
		}
	}
}


int* maxIndex(short** arr, int rows, int cols, int start_r, int start_c) {
	int max_r = start_r;
	int max_c = start_c;

	for (int j = start_c + 1; j < cols; ++j) {
		if (arr[start_r][j] > arr[max_r][max_c]) {
			max_c = j;
		}
	}

	for (int r = start_r + 1; r < rows; ++r) {
		for (int j = 0; j < cols; ++j) {
			if (arr[r][j] > arr[max_r][max_c]) {
				max_r = r;
				max_c = j;
			}
		}
	}

	int max[] = { max_r, max_c };
	return max;
}

void selectionSort(short** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int* max = maxIndex(arr, rows, cols, i, j);
			mySwap(arr[i][j], arr[max[0]][max[1]]);
		}
	}
}