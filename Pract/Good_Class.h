#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Good.h"
#include "Good_type_Class.h"
using namespace std;

class Good_Class
{
public:
	good Good;
	string buffer = "";
	Good_Type_Class gtC;

	void ShowG()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Good.txt", ios::in);
		system("cls");

		while (finE.peek() != EOF)
		{
			ReadFromFileGC(&finE);
			DeleteLastSps(Good.good_ind);
			DeleteLastSps(Good.type_ind);
			DeleteLastSps(Good.prod);
			DeleteLastSps(Good.name);
			DeleteLastSps(Good.hold_condit);
			DeleteLastSps(Good.package);
			DeleteLastSps(Good.exp_date);

			cout << left
				<< setw(15) << "Индекс товара"
				<< setw(15) << "Индекс типа"
				<< setw(25) << "Производитель"
				<< setw(25) << "Название товара"
				<< setw(25) << "Условия хранения"
				<< setw(25) << "Упаковка"
				<< setw(15) << "Срок годности" << endl;

			cout << left
				<< setw(15) << Good.good_ind
				<< setw(15) << Good.type_ind
				<< setw(25) << Good.prod
				<< setw(25) << Good.name
				<< setw(25) << Good.hold_condit
				<< setw(25) << Good.package
				<< setw(15) << Good.exp_date << endl;

			cout << "Дополнительная информация:\n";
			gtC.RFFSearchG(Good.type_ind);
		}
		finE.close();
		system("pause");
	}

	void AddElemGC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << setw(40) << "Ввод данных о товарах" << endl;

		cout << "Индекс товара: ";
		cin >> Good.good_ind;
		cin.ignore();

		cout << "Индекс типа: ";
		cin >> Good.type_ind;
		cin.ignore();

		cout << "Введите производителя: ";
		getline(cin, Good.prod);

		cout << "Введите наименование товара: ";
		getline(cin, Good.name);

		cout << "Введите условия хранения: ";
		getline(cin, Good.hold_condit);

		cout << "Введите упаковку: ";
		getline(cin, Good.package);

		cout << "Введите срок хранения: ";
		getline(cin, Good.exp_date);

		cout << "Запись окончена.";
		Sleep(1000);
		system("cls");
	}

	void AddToFileGC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Good.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			fout << left
				<< setw(5) << Good.good_ind
				<< setw(5) << Good.type_ind
				<< setw(25) << Good.prod
				<< setw(25) << Good.name
				<< setw(25) << Good.hold_condit
				<< setw(25) << Good.package
				<< setw(10) << Good.exp_date << endl;
		}
		else
			cout << "Ooooooops.. " << endl;

		fout.close();
	}

	void ReadFromFileGC(ifstream* fin)
	{
		buffer = "";
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Good.good_ind = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Good.type_ind = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Good.prod = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Good.name = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Good.hold_condit = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Good.package = buffer; buffer = "";

		for (int i = 0; i <= 10; i++)
			buffer += fin->get();
		Good.exp_date = buffer; buffer = "";
	}

	void DeleteLastSps(string& str)
	{
		int i;
		i = str.length() - 1;
		while (str[i] == ' ' || str[i] == '\n')
		{
			str.pop_back();
			i--;
		}
	}

	void DeleteAllSps(string& str)
	{
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ')
			{
				str.erase(i, 1);
				i--;
			}
		}
	}

};
