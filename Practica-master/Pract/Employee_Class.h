#ifndef EMPLOYEE_CLASS_H_
#define EMPLOYEE_CLASS_H_
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Employee.h"
#include "Position.h"
#include "Position_Class.h"
using namespace std;

class Employee_Class
{
	// ����� ������������ ������� - �������
	//��� ������� � � ������� � � ���������. � �����
public:
	Position_Class posCl;
	position Posit;
	employee Employ;
	string buffer = "";

	void ShowE()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Employee.txt", ios::in);
		system("cls");

		while (finE.peek()!=EOF)
		{
			ReadFromFileEC(&finE);

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
				<< setw(20) << "����� ����������"
				<< setw(36) << "���"
				<< setw(8) << "�������"
				<< setw(5) << "���"
				<< setw(39) << "�����"
				<< setw(20) << "�������"
				<< setw(15) << "�������"
				<< setw(10) << "���������" << endl;
			
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

			cout << "�������������� ����������: " << endl;

			posCl.RFFSearch(Employ.position_ind);			
		}
		finE.close();
		system("pause");
	}

	void AddElemEC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << setw(40) << "���� ������ � �����������" << endl;
		cout << "��������� �";
		cin >> Employ.eploy_ind;
		cin.ignore();

		cout << "������� ���: ";
		cin >> Employ.fio.name;
		cin.ignore();

		cout << "������� ��������: ";
		cin >> Employ.fio.sec_name;
		cin.ignore();

		cout << "������� �������: ";
		cin >> Employ.fio.surname;
		cin.ignore();

		cout << "������� �������: ";
		cin >> Employ.age;
		cin.ignore();

		cout << "������� �����" << endl
			<< "�����: ";
		cin >> Employ.e_adress.city;
		cin.ignore();

		cout << "�����: ";
		cin >> Employ.e_adress.street_name;
		cin.ignore();

		cout << "� ����: ";
		cin >> Employ.e_adress.house;
		cin.ignore();

		cout << "� ��������: ";
		cin >> Employ.e_adress.flat;
		cin.ignore();

		cout << "������� ��� (�/�): ";
		cin >> Employ.sex;
		cin.ignore();

		cout << "������� ����� ��������: ";
		getline(cin, Employ.phone);

		cout << "������� ����� � ����� ��������: ";
		getline(cin, Employ.passport);

		cout << "���������: ";
		cin >> Employ.position_ind;
		cin.ignore();
		
		cout << "������ ��������.";
		Sleep(1000);
		system("cls");
	}

	void AddToFileEC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Employee.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			/*fout << left << setw(20) 
				<< "����� ����������" << setw(36) 
				<< "���" << setw(5) 
				<< "�������" << setw(3) 
				<< "���" << setw(39)
				<< "�����" << setw(20) 
				<< "�������" << setw(15)
				<< "�������" << setw(10) 
				<< "���������" << endl;*/
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

	void DeleteLastSps(string &str)
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

#endif