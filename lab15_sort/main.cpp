#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "main.h"

void printTrain(Train*, int);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int size;
	cout << "Введите длинну массива: ";
	cin >> size;

	Train* trains = new Train[size];
	bool success = false;
	const int timeSize = 6;
	char time[timeSize];

	for (int i = 0; i < size; i++) {
		cout << "Поезд " << i + 1 << ": " << endl;

		cout << "Пункт назначения: ";
		cin >> trains[i].destination;
		cout << "Номер поезда: ";
		cin >> trains[i].trainNum;

		do {
			cout << "Время отправления: ";
			cin >> time;

			success = trains[i].inputTime(time);

			if (!success) {
				cout << "Неверное время.\n";
			}
		} while (!success);
	}

	cout << "\n===========================\n\n";

	cout << "1) Название пункта назначения (выбором).\n"
		<< "2) Название пункта назначения (Шелла).\n"
		<< "3) Номер поезда (выбором).\n"
		<< "4) Номер поезда (Шелла).\n";

	int p;
	do {
		cout << "Выберите вид сортировки: ";
		cin >> p;

		switch (p) {
			case 1: selectionSort_char(trains, size); break;
			case 2: shellSort_char(trains, size); break;
			case 3: selectionSort_num(trains, size); break;
			case 4: shellSort_num(trains, size); break;

			default: cout << "Неверный номер." << endl;
		}
	} while (p < 1 || p > 4);
	
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Поезд " << i + 1 << ": " << endl;
		printTrain(trains, i);
	}

	char searchText[40];
	cout << "\nВведите искомый номер поезда или место прибытия: ";
	cin >> searchText;

	int findIndex = -1;
	if (isStrDigit(searchText)) {
		findIndex = searchIndex(trains, size, atoi(searchText));
	}
	else {
		findIndex = searchIndex(trains, size, searchText);
	}

	if (findIndex >= 0) {
		printTrain(trains, findIndex);
	}
	else {
		cout << "Поезд не найден." << endl;
	}

	system("pause");
	return 0;
}

void printTrain(Train* arr, int index) {
	cout << "Пункт назначения: " << arr[index].destination
		<< "\nНомер поезда: " << arr[index].trainNum
		<< "\nВремя отправления: " << arr[index].departureTime[0] << ":" << arr[index].departureTime[1] << endl;
}