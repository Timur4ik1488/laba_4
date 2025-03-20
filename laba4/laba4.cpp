#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;

nachalo:
	cout << "Введите строку: ";
	getline(cin, str);

	if (str.empty()) {
		cout << "Строка не может быть пустой" << endl;
		goto nachalo;
	}

	double MaxRatio_a = 0.0, MaxRatio_b = 0.0;
	string result_a, result_b;
	size_t start = 0;
	size_t end = 0;

	while (start < str.length()) {
		while (start < str.length() && str[start] == ' ') {
			start++;
		}

		if (start >= str.length()) {
			break;
		}

		end = start;
		while (end < str.length() && str[end] != ' ') {
			end++;
		}

		string word = str.substr(start, end - start);

		int count_a = 0;
		for (char ch : word) {
			if (ch == 'а' || ch == 'А') {
				count_a++;
			}
		}

		double procent_a = static_cast<double>(count_a) / word.length();

		if (procent_a > MaxRatio_a) {
			MaxRatio_a = procent_a;
			result_a = word;
		}
		else if (procent_a == MaxRatio_a) {
			result_a = " " + word;
		}

		int count_b = 0;
		for (char ch : word) {
			if (ch == 'б' || ch == 'Б') {
				count_b++;
			}
		}

		double procent_b = static_cast<double>(count_b) / word.length();

		if (procent_b > MaxRatio_b) {
			MaxRatio_b = procent_b;
			result_b = word;
		}
		else if (procent_b == MaxRatio_b) {
			result_b = " " + word;
		}

		start = end;
	}

	cout << "Слово с максимальной долей содержания буквы 'а': " << result_a << endl;
	cout << "Слово с максимальной долей содержания буквы 'б': " << result_b << endl;
	
	//2
	int count_letter = 0, count_number = 0;
	for (char ch : str) {
		if ((ch >= 'А' && ch <= 'я') || (ch == 'Ё' || ch == 'ё')) {
			count_letter++;
		}

		if (isdigit(ch)) {
			count_number++;
		}
	}

	if (count_letter == 0 && count_number == 0) {
		cout << "В строке нет ни букв, ни цифр" << endl;
		goto nachalo;
	}

	cout << "Количество букв в строке: " << count_letter << endl;
	cout << "Количество цифр в строке: " << count_number << endl;

	if (count_letter > count_number) {
		cout << "True" << endl << "В строке букв больше, чем цифр" << endl;
		goto nachalo;
	}
	if (count_letter < count_number) {
		cout << "False" << endl << "В строке букв меньше, чем цифр" << end;
		goto nachalo;
	}
	else if (count_letter = count_number) {
		cout << "Количество букв равно количеству цифр" << endl;
		goto nachalo;
	}
}



