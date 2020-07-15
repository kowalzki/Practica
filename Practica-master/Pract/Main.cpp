#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include "Employee_Class.h"
#include "Position_Class.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout.setf(ios::left);
	bool flag = true, flag2;
	int choice, chs;
	employee empl;
	Employee_Class emplC;
	position posit;
	Position_Class posC;
	cout << "Приветствую вас в БД оптового склада :)" << endl;
	Sleep(1000);

	while (flag)
	{
		system("cls");
		cout << " Меню" << endl;
		cout << "_____________________" << endl;
		cout << "1: Сохранить в файл" << endl;
		cout << "2: Добавить элемент" << endl;
		cout << "3: Показать файл на экране" << endl;
		cout << "4: Отдел кадров" << endl;
		cout << "0: Выйти" << endl;
		cout << "_____________________" << endl << endl;
		cout << "Выберите (__): ";
		cin >> choice;
		switch (choice)
		{
		case 0: cout << "Хорошего дня ;)"
			<< endl; flag = false; break;

		case 1:
		{
			system("cls");
			cout << "Сотрудник/Должность? (1/2): ";
			cin >> chs;
			switch (chs)
			{
			case 1: emplC.AddToFileEC(); system("pause"); break;
			case 2: posC.AddToFilePC(); system("pause"); break;
			}
			break;
		}

		case 2:
		{
			system("cls");
			cout << "Сотрудник/Должность? (1/2): ";
			cin >> chs;
			switch (chs)
			{
			case 1: emplC.AddElemEC(); system("pause"); break;
			case 2: posC.AddElemPC(); system("pause"); break;
			}
			break;
		}

		case 3: emplC.ShowE(); system("pause"); break;

		case 4:
		{
			cout << "Вывести всех сотрудников или поиск по должности? (1/0): ";
			cin >> flag2;
			if (flag2)
				emplC.ShowE(); system("pause"); break;

			break;
		}
		default: cout << "Повторите ввод. " << endl; system("pause"); break;
		}
	}

	system("pause");
	return 0;
}
