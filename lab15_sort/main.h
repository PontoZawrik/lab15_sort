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

	bool result = false;
	for (int i = 0; i < size; i++) {
		if (!isdigit(string[i])) {
			break;
		}
	}
	result = true;

	return result;
}


int maxFrom_num(Train* m, int position, int length) {
	int maxIndex = position;
	for (int i = position + 1; i < length; i++) {
		if (m[i].trainNum > m[maxIndex].trainNum) {
			maxIndex = i;
		}
	}
	return maxIndex;
}

void selectionSort_num(Train* m, int length) {
	for (int i = 0; i < length - 1; i++) {
		mySwap(m[i], m[maxFrom_num(m, i, length)]);
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

int minFrom_char(Train* m, int position, int length) {
	int minIndex = position;
	for (int i = position + 1; i < length; i++) {
		if (strcmp(m[i].destination, m[minIndex].destination) < 0) {
			minIndex = i;
		}
	}
	return minIndex;
}

void selectionSort_char(Train* m, int length) {
	for (int i = 0; i < length - 1; i++) {
		cout << m[i].destination << " - " << m[minFrom_char(m, i, length)].destination << endl;
		mySwap(m[i], m[minFrom_char(m, i, length)]);
	}
}

void shellSort_char(Train* m, int n) {
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = 0; j < n - i; j++) {
			for (int k = j; k > -1; k -= i) {
				if (strcmp(m[k].destination, m[k + i].destination) > 0) {
					mySwap(m[k], m[k + i]);
				}
				else {
					k = 0;
				}
			}
		}
	}
}