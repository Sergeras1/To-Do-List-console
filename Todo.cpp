#include "Todo.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int id;

void Todo::add(){
	system("cls");
	string text;
	ofstream data;
	data.open("data.txt", ios::app);
	cout << ">> ";
	cin.get();
	getline(cin, text);
	id++;
		data << id << "." << "\t" << text << "\n";
		data.close();

		char ch;
		cout << "Добавить еще задачу? (y/n)\n\n";
		cin >> ch;
		if (ch == 'y') {
			add();
		}
		else if (ch == 'n') {
			cout << "Запись добавлена!\n\n";
		}
		else {
			cout << "Ошибка\n\n";
		}
}

void Todo::read(){
	system("cls");
	string text;
	ifstream file;
	file.open("data.txt");
	cout << "Задачи: \n\n";
	while (getline(file, text)) {
		cout << text << "\n";
	}
	file.close();
}

void Todo::clear(){
	system("cls");
	ofstream file;
	file.open("data.txt");
	file.clear();
	file.close();

	cout << "Все задачи удалены!\n\n";
}

void Todo::clearTask() {
	system("cls");
	ifstream inputFile("data.txt");
	ofstream tmpFile("tmp.txt");

	int IdLine = 1;
	string str;
	int IdxLine;
	read();
	cout << "Введите номер задачи:\n";
	cin >> IdxLine;

	while (getline(inputFile, str)) {
		if (IdLine != IdxLine) {
			tmpFile << str << "\n";
		}
		IdLine++;
	}
	inputFile.close();
	tmpFile.close();

	remove("data.txt");
	if (rename("tmp.txt", "data.txt") != 0) {
		cout << "Ошибка при переменовании файла!";
	};
}

void Todo::menu(){
	cout << "Выберите функцию: \n";
	cout << "1. Добавить задачу; \n";
	cout << "2. Посмотреть задачи; \n";
	cout << "3. Очистить все задачи; \n";
	cout << "4. Удалить задачу; \n";
}
