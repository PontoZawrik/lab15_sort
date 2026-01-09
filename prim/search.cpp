//#include <iostream>
//using namespace std;
//
//int findElementInMas(int*, int, int);
//int binaryFindElementInMas(int*, int, int);
//
//int main() {
//	setlocale(LC_ALL, "ru");
//
//	const int size = 10;
//	int array[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	for (int i = 0; i < size; i++) {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	int x;
//	cout << "Значение для поиска: ";
//	cin >> x;
//
//	int result = binaryFindElementInMas(array, size, x);
//	if (result != -1) {
//		cout << "Индекс: " << result << endl;
//	}
//	else {
//		cout << "Данный элемент не обнаружен." << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//
//int findElementInMas(int* m, int n, int key) {
//	for (int i = 0; i < n; i++) {
//		if (m[i] == key) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//int binaryFindElementInMas(int* m, int n, int key) {
//	int first = 0, last = n - 1;
//	int centr = (first + last) / 2;
//
//	while (first <= last) {
//		if (m[centr] == key) {
//			return centr;
//		}
//	
//		if (m[centr] > key) {
//			last = centr - 1;
//		}
//		else {
//			first = centr + 1;
//		}
//		centr = (first + last) / 2;
//	}
//
//	return -1;
//}