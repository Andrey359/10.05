
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool replay; // повтор лучайных чисел
	int range_Start, range_End; //диапазон
	int size; // кол-во

	cout << "Введите размер массива: "; cin >> size;
	int* array = new int[size]; // создание массива

	cout << "Введите даипазон случайных чисел" << endl;
	cout << "От: "; cin >> range_Start;
	cout << "До: "; cin >> range_End;

	cout << "yas - 1, no - 0 " << endl;
	cout << "Повторять числа: ";
	cin >> replay;
	if (!replay && (range_End - range_Start < size)) {
		cerr << "Размер массива больше чем диапазон чисел!";
		return 0;
	}

	//генерация случайных чисел с повтором
	if (replay) {
		for (int i = 0; i < size; i++) {
			array[i] = rand() % (range_End - range_Start + 1) + range_Start;
			cout << array[i] << " ";
		}
	}
	//генерация случайных чисел без повтора
	else {
		for (int i = 0; i < size; i++) {
			array[i] = rand() % (range_End - range_Start + 1) + range_Start;
			for (int j = 1; j < i; j++) {
				if (array[j - 1] == array[j]) {
					i--;
					break;
				}
			}
			cout << array[i] << " ";
		}
	}

    delete[] array; // удаление старого массива
}
