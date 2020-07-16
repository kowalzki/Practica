#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include "Employee_Class.h"
#include "Position_Class.h"
#include "Good_Class.h"
#include "Good_type_Class.h"
#include "Dealer_Class.h"
#include "Orderer_Class.h"
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
	Good_Class gdCl;
	Good_Type_Class gotCl;
	Dealer_Class delCl;
	Orderer_Class ordCl;
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
		cout << "5: Список товаров" << endl;
		cout << "6: Заказы" << endl;
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
			cout << "Сохранение в файл:" << endl;
			cout << "1: Сотрудник" << endl;
			cout << "2: Должность" << endl;
			cout << "3: Товар" << endl;
			cout << "4: Тип товара" << endl;
			cout << "5: Поставщик" << endl;
			cout << "6: Заказчик" << endl;
			cout << "_____________________" << endl << endl;
			cout << "Выберите (__): ";
			cin >> chs;
			switch (chs)
			{
			case 1: emplC.AddToFileEC(); system("pause"); break;
			case 2: posC.AddToFilePC(); system("pause"); break;
			case 3: gdCl.AddToFileGC(); system("pause"); break;
			case 4: gotCl.AddToFileGTC(); system("pause"); break;
			case 5: delCl.AddToFileDC(); system("pause"); break;
			case 6: ordCl.AddToFileOC(); system("pause"); break;
			}
			break;
		}

		case 2:
		{
			system("cls");
			cout << "Добавить элемент в:" << endl;
			cout << "1: Сотрудник" << endl;
			cout << "2: Должность" << endl;
			cout << "3: Товар" << endl;
			cout << "4: Тип товара" << endl;
			cout << "5: Поставщик" << endl;
			cout << "_____________________" << endl << endl;
			cout << "Выберите (__): ";
			cin >> chs;
			switch (chs)
			{
			case 1: emplC.AddElemEC(); system("pause"); break;
			case 2: posC.AddElemPC(); system("pause"); break;
			case 3: gdCl.AddElemGC(); system("pause"); break;
			case 4: gotCl.AddElemGTC(); system("pause"); break;
			case 5: delCl.AddElemGC(); system("pause"); break;
			case 6: ordCl.AddElemOC(); system("pause"); break;
			}
			break;
		}

		case 3: emplC.ShowE(); system("pause"); break;

		case 4:
		{
			cout << "Вывести всех сотрудников или поиск по должности? (1/0): ";
			cin >> flag2;
			if (flag2)
			{
				emplC.ShowE(); system("pause"); break;
			}
			else
			{
				posC.SearchEmp(); system("pause"); break;
			}

			break;
		}
		case 5:
		{
			cout << "Вывести все товары или поиск по типу? (1/0): ";
			cin >> flag2;
			if (flag2)
			{
				gdCl.ShowGF(); system("pause"); break;
			}
			else
			{
				gotCl.SearchGds(); system("pause"); break;
			}
			break;
		}
		case 6:
		{
			cout << "По полю -Поставщики- или -Заказчики- ? (1/0): ";
			cin >> flag2;
			if (flag2)
			{
				cout << "Вывести всех поставщиков или поиск по конкретному? (1/0): ";
				cin >> flag2;
				if (flag2)
				{
					delCl.ShowD(); system("pause"); break;
				}
				else
				{
					delCl.RFFSearchD(); system("pause"); break;
				}
			}
		}
		default: cout << "Повторите ввод. " << endl; system("pause"); break;
		}
	}

	system("pause");
	return 0;
}
