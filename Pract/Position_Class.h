#ifndef POSITION_CLASS_H_
#define POSITION_CLASS_H_
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Position.h"
#include "Employee.h"
using namespace std;

class Position_Class
{

public:
	position Posit;
	employee Employ;
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
		buffer = "";
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

	void SearchEmp()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Employee.txt", ios::in);
		string serchr = "";
		cout << "Введите искомую должность: ";
		cin.ignore();
		getline(cin, serchr);
		cout << endl;
		RFFSearch(serchr);
		serchr = Posit.position_ind;

		while (finE.peek() != EOF)
		{
			ReadFromFileEC(&finE);

			DeleteLastSps(serchr);
			DeleteLastSps(Employ.eploy_ind);
			DeleteLastSps(Employ.fio.name);
			DeleteLastSps(Employ.fio.sec_name);
			DeleteLastSps(Employ.fio.surname);
			DeleteLastSps(Employ.age);
			DeleteLastSps(Employ.e_adress.city);
			DeleteLastSps(Employ.e_adress.street_name);
			DeleteLastSps(Employ.e_adress.house);
			DeleteLastSps(Employ.e_adress.flat);
			DeleteLastSps(Employ.sex);
			DeleteLastSps(Employ.phone);
			DeleteLastSps(Employ.passport);
			DeleteLastSps(Employ.position_ind);

			if (serchr == Employ.position_ind)
			{
				cout << left
					<< setw(20) << "Номер сотрудника"
					<< setw(36) << "ФИО"
					<< setw(8) << "Возраст"
					<< setw(5) << "Пол"
					<< setw(39) << "Адрес"
					<< setw(20) << "Телефон"
					<< setw(15) << "Паспорт"
					<< setw(10) << "Должность" << endl;

				cout << left
					<< setw(20) << Employ.eploy_ind
					<< setw(12) << Employ.fio.name
					<< setw(12) << Employ.fio.sec_name
					<< setw(12) << Employ.fio.surname
					<< setw(8) << Employ.age
					<< setw(5) << Employ.sex
					<< setw(15) << Employ.e_adress.city
					<< setw(15) << Employ.e_adress.street_name
					<< setw(4) << Employ.e_adress.house << '/'
					<< setw(4) << Employ.e_adress.flat
					<< setw(20) << Employ.phone
					<< setw(15) << Employ.passport
					<< setw(10) << Employ.position_ind << endl;
			}
		}
		finE.close();
	}

	void RFFSearch(string str)
	{
		ifstream fin;
		fin.open("C:\\Pract\\Position.txt", ios::in);

		while (str != Posit.position_ind || str != Posit.pos_name)
		{
			ReadFromFilePC(&fin);
			DeleteLastSps(str);
			DeleteLastSps(Posit.position_ind);
			DeleteLastSps(Posit.pos_name);
			DeleteLastSps(Posit.salary);
			DeleteLastSps(Posit.responsibility);
			DeleteLastSps(Posit.expectations);

			if (str == Posit.position_ind || str == Posit.pos_name)
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
				break;
			}
			if (fin.peek() == EOF)
				break;
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

	void ReadFromFileEC(ifstream* fin)
	{
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Employ.eploy_ind = buffer; buffer = "";

		for (int i = 0; i < 12; i++)
			buffer += fin->get();
		Employ.fio.name = buffer; buffer = "";

		for (int i = 0; i < 12; i++)
			buffer += fin->get();
		Employ.fio.sec_name = buffer; buffer = "";

		for (int i = 0; i < 12; i++)
			buffer += fin->get();
		Employ.fio.surname = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Employ.age = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		Employ.sex = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Employ.e_adress.city = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Employ.e_adress.street_name = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Employ.e_adress.house = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Employ.e_adress.flat = buffer; buffer = "";

		for (int i = 0; i < 20; i++)
			buffer += fin->get();
		Employ.phone = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Employ.passport = buffer; buffer = "";

		for (int i = 0; i <= 5; i++)
			buffer += fin->get();
		Employ.position_ind = buffer; buffer = "";

	}

};

#endif