#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Employee.h"
using namespace std;

class Employee_Class
{
	// когда обрабатывать запросы - удалить
	//все пробелы и в запросе и в структуре. К херам
public:
	//struct employee employees[10] = {};
	//vector <employee> employees;
	employee Employ;
	string buffer = "";
	//unsigned int empN = 0, posN = 0;
	void Show()
	{
		ifstream fin;
		fin.open("C:\\Pract\\Employee.txt", ios::in);
		cout << left
			<< setw(20) << "Номер сотрудника"
			<< setw(36) << "ФИО"
			<< setw(8) << "Возраст"
			<< setw(5) << "Пол"
			<< setw(39) << "Адрес"
			<< setw(20) << "Телефон"
			<< setw(15) << "Паспорт"
			<< setw(10) << "Должность" << endl;

		while (fin.peek()!=EOF)
		{
			ReadFromFile(&fin);

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
			
			cout << left 
				<< setw(20) << Employ.eploy_ind 
				<< setw(12)	<< Employ.fio.name
				<< setw(12)	<< Employ.fio.sec_name
				<< setw(12)	<< Employ.fio.surname
				<< setw(8)  << Employ.age 
				<< setw(5)  << Employ.sex
				<< setw(15)	<< Employ.e_adress.city
				<< setw(15)	<< Employ.e_adress.street_name
				<< setw(4)  << Employ.e_adress.house << '/'
				<< setw(4)  << Employ.e_adress.flat 
				<< setw(20)	<< Employ.phone 
				<< setw(15) << Employ.passport 
				<< setw(10)  << Employ.position_ind << endl;
		}
		fin.close();
		system("pause");
	}

	void AddElem()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		bool flag = false;
		//unsigned int empN = 0, posN = 0;
		ios_base::left;
		cout << setw(40) << "Ввод данных о сотрудниках" << endl;
		//employees.push_back(Employ);
		cout << "TYT" << endl;
		cout << "Сотрудник №";
		cin >> Employ.eploy_ind;
		cin.ignore();

		cout << "Введите имя: ";
		cin >> Employ.fio.name;
		cin.ignore();

		cout << "Введите отчество: ";
		cin >> Employ.fio.sec_name;
		cin.ignore();

		cout << "Введите фамилию: ";
		cin >> Employ.fio.surname;
		cin.ignore();

		cout << "Введите возраст: ";
		cin >> Employ.age;
		cin.ignore();

		cout << "Введите адрес" << endl
			<< "Город: ";
		cin >> Employ.e_adress.city;
		cin.ignore();

		cout << "Улица: ";
		cin >> Employ.e_adress.street_name;
		cin.ignore();

		cout << "№ дома: ";
		cin >> Employ.e_adress.house;
		cin.ignore();

		cout << "№ квартиры: ";
		cin >> Employ.e_adress.flat;
		cin.ignore();

		cout << "Введите пол (м/ж): ";
		cin >> Employ.sex;
		cin.ignore();

		cout << "Введите номер телефона: ";
		getline(cin, Employ.phone);

		cout << "Введите серию и номер паспорта: ";
		getline(cin, Employ.passport);

		cout << "Должность: ";
		cin >> Employ.position_ind;
		cin.ignore();
		
		cout << "Запись окончена.";
		Sleep(2000);
		system("cls");
	}

	void AddToFile()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Employee.txt", ios::app);
		ios_base::left;

		/*cout << endl << employees.at(0).phone << endl;
		cout << endl << employees.size() << endl;*/

		if (fout.is_open())
		{
			cout << endl << "Ok" << endl;
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
				<< setw(5)  << Employ.eploy_ind
				<< setw(12)	<< Employ.fio.name 
				<< setw(12)	<< Employ.fio.sec_name
				<< setw(12)	<< Employ.fio.surname
				<< setw(5)  << Employ.age 
				<< setw(3)	<< Employ.sex
				<< setw(15) << Employ.e_adress.city 
				<< setw(15) << Employ.e_adress.street_name
				<< setw(4)  << Employ.e_adress.house
				<< setw(4) 	<< Employ.e_adress.flat
				<< setw(20)	<< Employ.phone 
				<< setw(15)	<< Employ.passport 
				<< setw(5)  << Employ.position_ind << endl;
		}
		else
			cout << "Ooooooops.. " << endl;

		fout.close();
	}

	void ReadFromFile(ifstream *fin)
	{
			//getline(fin, buffer);
		/*while (fin->peek() != '\n' && !fin->eof()) // +setw
		{*/
			//fin.seekg(20, ios_base::beg);
	/*	while (!fin->eof())
		{*/
		 /*if (!fin->eof())
		{*/

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
			/*}*/
		/*}*/
	}

	void DeleteLastSps(string &str)
	{
		int i;
		i = str.length() - 1;
		//cout << i;
		while (str[i] == ' ')
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