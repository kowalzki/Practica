#ifndef POSITION_CLASS_H_
#define POSITION_CLASS_H_
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Position.h"
using namespace std;

class Position_Class
{

public:
	position Posit;
	string buffer = "";

	void AddElemPC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << setw(40) << "Ввод данных о должностях" << endl;

		cout << "Индекс должности: ";
		cin >> Posit.position_ind;
		cin.ignore();

		cout << "Введите наименование: ";
		getline(cin, Posit.pos_name);

		cout << "Введите оклад: ";
		getline(cin, Posit.salary);

		cout << "Введите обязанности: ";
		getline(cin, Posit.responsibility);

		cout << "Введите требования: ";
		getline(cin, Posit.expectations);

		cout << "Запись окончена.";
		Sleep(1000);
		system("cls");
	}

	void AddToFilePC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Position.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			/*fout << left << setw(20)
				<< "Номер сотрудника" << setw(36)
				<< "ФИО" << setw(5)
				<< "Возраст" << setw(3)
				<< "Пол" << setw(39)
				<< "Адрес" << setw(20)
				<< "Телефон" << setw(15)
				<< "Паспорт" << setw(10)
				<< "Должность" << endl;*/
			fout << left
				<< setw(5) << Posit.position_ind
				<< setw(25) << Posit.pos_name
				<< setw(10) << Posit.salary
				<< setw(50) << Posit.responsibility
				<< setw(50) << Posit.expectations << endl;
		}
		else
			cout << "Ooooooops.. " << endl;

		fout.close();
	}

	void ReadFromFilePC(ifstream* fin)
	{
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Posit.position_ind = buffer; buffer = "";

		for (int i = 0; i < 25; i++)
			buffer += fin->get();
		Posit.pos_name = buffer; buffer = "";

		for (int i = 0; i < 10; i++)
			buffer += fin->get();
		Posit.salary = buffer; buffer = "";

		for (int i = 0; i < 50; i++)
			buffer += fin->get();
		Posit.responsibility = buffer; buffer = "";

		for (int i = 0; i <= 50; i++)
			buffer += fin->get();
		Posit.expectations = buffer; buffer = "";
	}

	void RFFSearch(string str)
	{
		ifstream fin;
		fin.open("C:\\Pract\\Position.txt", ios::in);

		while (str != Posit.position_ind)
		{
			ReadFromFilePC(&fin);
			DeleteLastSps(str);
			DeleteLastSps(Posit.position_ind);
			DeleteLastSps(Posit.pos_name);
			DeleteLastSps(Posit.salary);
			DeleteLastSps(Posit.responsibility);
			DeleteLastSps(Posit.expectations);

			if (str == Posit.position_ind)
			{
				cout << left
					<< setw(15) << "Код должности"
					<< setw(25) << "Название должности"
					<< setw(10) << "Оклад"
					<< setw(50) << "Обязанности"
					<< setw(50) << "Требования" << endl;

				cout << left
					<< setw(15) << Posit.position_ind
					<< setw(25) << Posit.pos_name
					<< setw(10) << Posit.salary
					<< setw(50) << Posit.responsibility
					<< setw(50) << Posit.expectations << endl << endl;
			}
		}
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
			if (str[i] == ' ' || str[i] == '\n')
			{
				str.erase(i, 1);
				i--;
			}
		}
	}

};

#endif