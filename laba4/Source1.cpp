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
				count_a++ ;
			}
		}

		double procent_a = static_cast<double>(count_a) / word.length();

		if (procent_a > MaxRatio_a) {
			MaxRatio_a = procent_a;
			result_a = word;
		}
		else if (procent_a == MaxRatio_a){
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

	cout << "Слово с а: " << result_a << endl;
	cout << "Слово с б: " << result_b << endl;
	goto nachalo;
}