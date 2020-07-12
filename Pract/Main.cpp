#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include "Employee_Class.cpp"
using namespace std;

//void AddElement();
//void PushToFile(Employee_Class* emp);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout.setf(ios::left);
	bool flag = true;
	int choice;
	employee empl;
	Employee_Class emplC;
	cout << "Приветствую вас в БД оптового склада :)" << endl;
	Sleep(1000);

	while (flag)
	{
		system("cls");
		cout << " Меню" << endl;
		cout << "_____________________" << endl;
		cout << "1: Сохранить файл" << endl;
		cout << "2: Добавить Элемент" << endl;
		cout << "3: Показать файл на экране" << endl;
		cout << "0: Выйти" << endl;
		cout << "_____________________" << endl << endl;
		cout << "Выберите (__): ";
		cin >> choice;
		switch (choice)
		{
		case 0: cout << "Хорошего дня ;)" 
			<< endl; flag = false; break;
		case 1: emplC.AddToFile(); system("pause"); break;
		case 2: emplC.AddElem(); system("pause"); break;
		case 3: emplC.Show(); system("pause"); break;
		default: cout << "Повторите ввод. " << endl; system("pause"); break;
		}
	}
	system("pause");
	return 0;
}
