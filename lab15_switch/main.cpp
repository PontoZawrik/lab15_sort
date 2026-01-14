#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "main.h"

void printTrain(Train*, int);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int p;

	do {
		cout << "Введите номер задания (-1 для выхода): ";
		cin >> p;

		switch (p) {
			case 1: {
				char type[20];
				do {
					cout << "Выберите тип массива (double/char): ";
					cin >> type;
				} while (strcmp(type, "double") != 0 && strcmp(type, "char"));

				int size;
				cout << "Введите размер массива: ";
				cin >> size;

				if (strcmp(type, "double") == 0) {
					double* arr = createArray<double>(size);

					for (int i = 0; i < size; i++) {
						cout << "arr[" << i << "]: ";
						cin >> arr[i];
					}
					quickSort(arr, 0, size-1);

					cout << "\nОтсортированный массив:" << endl;
					printArray(arr, size);

					delete[] arr;
					arr = NULL;
				}
				else {
					char* arr = createArray<char>(size);

					for (int i = 0; i < size; i++) {
						cout << "arr[" << i << "]: ";
						cin >> arr[i];
					}
					insertSort(arr, size);

					cout << "\nОтсортированный массив:" << endl;
					printArray(arr, size);

					delete[] arr;
					arr = NULL;
				}

			} break;

			case 2: {
				int n, m;
				cout << "Введите размер массива (n, m): ";
				cin >> n >> m;

				short int** arr = createArray<short int>(n, m);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						cout << "arr[" << i << "][" << j << "]: ";
						cin >> arr[i][j];
					}
				}
				selectionSort(arr, n, m);

				cout << "\nОтсортированный массив:" << endl;
				printArray(arr, n, m);

				deleteArray(arr, n);
			} break;

			case 3: {
				int size;
				cout << "Введите размер массива: ";
				cin >> size;

				Train* trains = createArray<Train>(size);
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
				shellSort_num(trains, size);
				
				cout << "\nОтсортированный массив:" << endl;
				for (int i = 0; i < size; i++) {
					cout << "Поезд " << i + 1 << ": " << endl;
					printTrain(trains, i);
				}

				delete[] trains;
				trains = NULL;
			} break;


			case -1: cout << "Выход из программы.\n"; break;
			default: cout << "Неверный номер.\n";
		}

		cout << endl;
	} while (p != -1);
}


void printTrain(Train* arr, int index) {
	cout << "Пункт назначения: " << arr[index].destination
		<< "\nНомер поезда: " << arr[index].trainNum
		<< "\nВремя отправления: " << arr[index].departureTime[0] << ":" << arr[index].departureTime[1] << endl;
}