
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

void GetHistoryOfOperations(const string& filename);
void DeleteHistoryOfOperations(const string& filename);
void GetCalculations(int& num1, int& num2, int& choiceOfCalc, const string& filename);
void HistoryMenu(int& choice, const string& filename);


int main() {
	const string filename = "CalculationOperations.txt";
	setlocale(LC_ALL, "Ru");

	while (true) {
		int choice;
		cout << "\nКалькулятор\n";
		cout << "1. Сделать вычисление\n";
		cout << "2. Действия с историей вычислений\n";
		cout << "3. Выход\n";
		cout << "Выберите: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int number1, number2, calculationChoice;
			cout << "Выберите операцию (1-сложение, 2-вычитание, 3-деление, 4-умножение): ";
			cin >> calculationChoice;
			cout << "Введите два числа: ";
			cin >> number1 >> number2; 
			GetCalculations(number1, number2, calculationChoice, filename);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			int historyChoice;
			cout << "1. Просмотреть историю\n";
			cout << "2. Удалить историю\n";
			cout << "3. Назад\n";
			cin >> historyChoice;
			HistoryMenu(historyChoice, filename);
			system("pause");
			system("cls");
			break;
		}
		case 3:
			return 0; 
		default:
			cout << "Неверный выбор!\n";
			system("pause");
			system("cls");
		}
	}
}
void GetCalculations(int& num1, int& num2, int& choiceOfCalc, const string& filename) {
	ofstream filecalc(filename, ios::app );
	int result;
	switch (choiceOfCalc) {
	case 1:
		result = num1 + num2;
		cout << "Результат: " << result << endl;
		filecalc << num1 << "+" << num2 << "=" << result << std::endl;
		break;
	case 2:
		result = num1 - num2;
		cout << "Результат: " << result << endl;
		filecalc << num1 << "-" << num2 << "=" << result << std::endl;
		break;
	case 3: 
		if (num2 == 0) {
			cout << "Ошибка: деление на ноль!" << endl;
			filecalc << num1 << " / " << num2 << " = ОШИБКА (деление на ноль)" << endl;
		}
		else {
			result = num1 / num2;
			cout << "Результат: " << result << endl;
			filecalc << num1 << " / " << num2 << " = " << result << endl;
		}
		break;
	case 4:
		result = num1 * num2;
		cout << "Результат: " << result << endl;
		filecalc << num1 << "*" << num2 << "=" << result << std::endl;
		break;
	default:
		cout << "Неправильная операция!" << endl;
		result = 0;
		break;
	}
}
void HistoryMenu(int& choice, const string& filename) {
	switch (choice) {
	case 1:
		GetHistoryOfOperations(filename);
		break;
	case 2:
		DeleteHistoryOfOperations(filename);
		break;
	default:
		cout << "Неправильный выбор!" << endl;
	}
}
void GetHistoryOfOperations(const string& filename) {
	ifstream filecalc(filename, ios::in);
	if (filecalc.is_open()) {
		string line;
		system("cls");
		while (getline(filecalc, line)) {
			cout << line << endl;
		}
		system("pause");
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
}

void DeleteHistoryOfOperations(const string& filename) {
	ofstream filecalc(filename, ios::trunc);
	if (filecalc.is_open()) {
		cout << "История удалена." << endl;
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
}