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
		cout << "�������� ��� ������? (y/n)\n\n";
		cin >> ch;
		if (ch == 'y') {
			add();
		}
		else if (ch == 'n') {
			cout << "������ ���������!\n\n";
		}
		else {
			cout << "������\n\n";
		}
}

void Todo::read(){
	system("cls");
	string text;
	ifstream file;
	file.open("data.txt");
	cout << "������: \n\n";
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

	cout << "��� ������ �������!\n\n";
}

void Todo::clearTask() {
	system("cls");
	ifstream inputFile("data.txt");
	ofstream tmpFile("tmp.txt");

	int IdLine = 1;
	string str;
	int IdxLine;
	read();
	cout << "������� ����� ������:\n";
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
		cout << "������ ��� ������������� �����!";
	};
}

void Todo::menu(){
	cout << "�������� �������: \n";
	cout << "1. �������� ������; \n";
	cout << "2. ���������� ������; \n";
	cout << "3. �������� ��� ������; \n";
	cout << "4. ������� ������; \n";
}
