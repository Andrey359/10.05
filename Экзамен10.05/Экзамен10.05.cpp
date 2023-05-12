
#include <iostream>
#include <time.h>

using namespace std;

int char_To_Int(char c[]) {
	int integer = 0;
	for (int i = 0; c[i] > NULL; i++) {
		if ((int)c[i] >= 48 && 57) {
			integer = integer * 10 + (int)c[i] - 48;
		}
		else {
			integer += (int)c[i];
		}
	}
	return integer;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	char text[64];
	bool replay; // повтор случайных чисел
	int range_Start, range_End; //диапазон
	int size; // кол-во

	cout << "Это \"рандомайзер\" случайных чисел в котором можно вводить любые символы за исключением Кириллицы!" << endl;
	cout << "Сначала нужно ввести размер массива т.е. кол-во чисел." << endl;
	cout << "Далее диапазон чисел, например если выбрать: От: 1; До: 5, то сгенерирует случайное число из: 1, 2, 3, 4, 5." << endl;
	cout << "И на конец \"повтор чисел\" если выбрать любой символ, то автоматически все числа будут случайным образом, 0 - уникальными." << endl;
	cout << "Внимание, размер массива должен быть больше чем диапазон чисел, если выбрали НЕ повторять числа! " << endl;
	cout << "Введите размер массива: "; 
	gets_s(text);
	size = char_To_Int(text);
	int* array = new int[size];

	cout << "Введите даипазон случайных чисел" << endl;
	cout << "От: "; 
	gets_s(text);
	range_Start = char_To_Int(text);
	cout << "До: "; 
	gets_s(text);
	range_End = char_To_Int(text);
	//Исправление ввод пользователя
	if (range_Start > range_End) {
		int l = range_Start;
		range_Start = range_End;
		range_End = l;
	}

	cout << "yes - любой символ, no - 0 " << endl;
	cout << "Повторять числа: ";
	gets_s(text);
	replay = char_To_Int(text);
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
