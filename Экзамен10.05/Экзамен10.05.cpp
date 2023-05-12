
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	bool replay; // повтор случайных чисел
	int range_Start, range_End; //диапазон
	int size; // кол-во

	cout << "Введите размер массива: "; cin >> size;
	int* array = new int[size];

	cout << "Введите даипазон случайных чисел" << endl;
	cout << "От: "; cin >> range_Start;
	cout << "До: "; cin >> range_End;
	//Исправление ввод пользователя
	if (range_Start > range_End) {
		int l = range_Start;
		range_Start = range_End;
		range_End = l;
	}

	cout << "yas - 1, no - 0 " << endl;
	cout << "Повторять числа: ";
	cin >> replay;
	if (!replay && (range_End - range_Start < size - 1)) {
		cerr << "Размер массива больше чем диапазон чисел!";
		return -1;
	}
	//генерация случайных чисел с повтором
	if (replay) {
		for (int i = 0; i < size; i++) {
			array[i] = rand() % (range_End - range_Start + 1) + range_Start;
		}
	}
	//генерация случайных чисел без повтора
	else {
		for (int i = 0; i < size; i++) {
			array[i] = rand() % (range_End - range_Start + 1) + range_Start;
			for (int j = 1; j <= i; j++) {
				if (array[j - 1] == array[i]) {
					i--;
					break;
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

    delete[] array;
	return 0;
}
