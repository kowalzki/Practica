#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Good.h"
#include "Good_type.h"
using namespace std;

class Good_Type_Class
{
public:
	good_type Got;
	good Good;
	string buffer = "";

	void AddElemGTC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << setw(40) << "Ввод данных о типах товаров" << endl;

		cout << "Код типа: ";
		cin >> Got.type_ind;
		cin.ignore();

		cout << "Введите наименование типа: ";
		getline(cin, Got.name);

		cout << "Введите описание типа: ";
		getline(cin, Got.description);

		cout << "Введите особенности типа: ";
		getline(cin, Got.features);

		cout << "Запись окончена.";
		Sleep(1000);
		system("cls");
	}

	void AddToFileGTC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Good_type.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			fout << left
				<< setw(5) << Got.type_ind
				<< setw(25) << Got.name
				<< setw(30) << Got.description
				<< setw(25) << Got.features << endl;
		}
		else
			cout << "Ooooooops.. " << endl;

		fout.close();
	}

	void ReadFromFileGTC(ifstream* fin)
	{
		buffer = "";
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Got.type_ind = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Got.name = buffer; buffer = "";

		for (int i = 0; i < 30; i++)
			buffer += fin->get();
		Got.description = buffer; buffer = "";

		for (int i = 0; i <= 25; i++)
			buffer += fin->get();
		Got.features = buffer; buffer = "";
	}

	void RFFSearchG(string str)
	{
		ifstream fin;
		fin.open("C:\\Pract\\Good_type.txt", ios::in);

		while (str != Got.type_ind || str != Got.name)
		{
			ReadFromFileGTC(&fin);
			DeleteLastSps(str);
			DeleteLastSps(Got.type_ind);
			DeleteLastSps(Got.name);
			DeleteLastSps(Got.description);
			DeleteLastSps(Got.features);

			if (str == Got.type_ind || str == Got.name)
			{
				cout << left 
					<< setw(15) << "Код типа"
					<< setw(25) << "Название типа"
					<< setw(30) << "Описание"
					<< setw(25) << "Особенности" << endl;

				cout << left
					<< setw(15)  << Got.type_ind
					<< setw(25) << Got.name
					<< setw(30) << Got.description
					<< setw(25) << Got.features << endl << endl;
				break;
			}
			if (fin.peek() == EOF)
				break;
		}
	}

	void SearchGds()
	{
		ifstream fin;
		fin.open("C:\\Pract\\Good.txt", ios::in);
		string serchr = "";
		cout << "Введите искомый тип товаров: ";
		cin.ignore();
		getline(cin, serchr);
		cout << endl;

		cout << "Информация по этому типу:" << endl;
		RFFSearchG(serchr);
		serchr = Got.type_ind;

		while (fin.peek() != EOF)
		{
			ReadFromFileGC(&fin);
			DeleteLastSps(Good.good_ind);
			DeleteLastSps(Good.type_ind);
			DeleteLastSps(Good.prod);
			DeleteLastSps(Good.name);
			DeleteLastSps(Good.hold_condit);
			DeleteLastSps(Good.package);
			DeleteLastSps(Good.exp_date);

			if (serchr == Good.type_ind)
			{
				cout << left
					<< setw(15) << "Код товара"
					<< setw(15) << "Код типа"
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
			}
			if (fin.peek() == EOF)
				break;
		}
		fin.close();
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
};