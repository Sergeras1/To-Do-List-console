#include <iostream>
#include <string>
#include "Todo.h"

using namespace std;
int main(){
	system("cls");
	setlocale(LC_ALL, "ru");
	Todo todo;
	int NumFunc;
	string text;
		while (1) {
			todo.menu();
				cin >> NumFunc;
				if (!cin) {
					cout << "Неверное значение!";
					break;
					todo.menu();
				}
				switch (NumFunc) {
				case 1:
					todo.add();
					break;
				case 2:
					todo.read();
					break;
				case 3:
					todo.clear();
					break;
				case 4:
					todo.clearTask();
					break;
				default:
					cout << "Данной функции нет \n";
					break;
				}
			
		}
}



