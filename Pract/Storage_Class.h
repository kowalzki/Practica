#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Storage.h"
#include "Good_Class.h"
#include "Dealer_Class.h"
#include "Orderer_Class.h"
#include "Employee_Class.h"
using namespace std;

class Storage_Class
{
public:
	storage stor;
	string buffer = "";
	Good_Class gCl;
	Dealer_Class dCl;
	Orderer_Class oCL;
	Employee_Class eCl;

	void ShowS()
	{
		ifstream finS;
		finS.open("C:\\Pract\\Storage.txt", ios::in);
		system("cls");

		while (finS.peek() != EOF)
		{
			ReadFromFileSC(&finS);
			DeleteLastSps(stor.in_date.day);
			DeleteLastSps(stor.in_date.month);
			DeleteLastSps(stor.in_date.year);
			DeleteLastSps(stor.ord_date.day);
			DeleteLastSps(stor.ord_date.month);
			DeleteLastSps(stor.ord_date.year);
			DeleteLastSps(stor.out_date.day);
			DeleteLastSps(stor.out_date.month);
			DeleteLastSps(stor.out_date.year);
			DeleteLastSps(stor.good_ind);
			DeleteLastSps(stor.dealer_ind);
			DeleteLastSps(stor.orderer_ind);
			DeleteLastSps(stor.delivery_type);
			DeleteLastSps(stor.size);
			DeleteLastSps(stor.price);
			DeleteLastSps(stor.eploy_ind);
			string  datain, dataord, dataout;
			datain += stor.in_date.day; datain += '/'; datain += stor.in_date.month; datain += '/'; datain += stor.in_date.year;
			dataord += stor.ord_date.day; dataord += '/'; dataord += stor.ord_date.month; dataord += '/'; dataord += stor.ord_date.year;
			dataout += stor.out_date.day; dataout += '/'; dataout += stor.out_date.month; dataout += '/'; dataout += stor.out_date.year;

			cout << left 
				<< setw(25) << "���� ����������� ������"
				<< setw(15) << "���� ������"
				<< setw(15) << "���� ��������"
				<< setw(15) << "K�� ������"
				<< setw(16) << "K�� ����������"
				<< setw(15) << "K�� ���������"
				<< setw(15) << "��� ��������"
				<< setw(15) << "����� ������"
				<< setw(7)  << "����"
				<< setw(15) << "��� ����������" << endl;

			cout << left
				<< setw(25) << datain
				<< setw(15) << dataord
				<< setw(15) << dataout
				<< setw(15) << stor.good_ind
				<< setw(16) << stor.dealer_ind
				<< setw(15) << stor.orderer_ind
				<< setw(15) << stor.delivery_type
				<< setw(15) << stor.size
				<< setw(7) << stor.price
				<< setw(15) << stor.eploy_ind << endl;

			cout << "�������������� ����������:\n";
			gCl.RFFSearchG(stor.good_ind);
			dCl.RFFSearchDS(stor.dealer_ind);
			oCL.RFFSearchOS(stor.orderer_ind);
			eCl.RFFSearchE(stor.eploy_ind);
			cout << endl;
		}
	}

	void AddElemSC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << "���� ������ �� ������" << endl;

		cout << "���� ����������� ������" << endl;
		cout << "���: ";
		cin >> stor.in_date.year;
		cin.ignore();

		cout << "�����: ";
		cin >> stor.in_date.month;
		cin.ignore();

		cout << "����: ";
		cin >> stor.in_date.day;
		cin.ignore();

		cout << "���� ������" << endl;
		cout << "���: ";
		cin >> stor.ord_date.year;
		cin.ignore();

		cout << "�����: ";
		cin >> stor.ord_date.month;
		cin.ignore();

		cout << "����: ";
		cin >> stor.ord_date.day;
		cin.ignore();
		
		cout << "���� ��������" << endl;
		cout << "���: ";
		cin >> stor.out_date.year;
		cin.ignore();

		cout << "�����: ";
		cin >> stor.out_date.month;
		cin.ignore();

		cout << "����: ";
		cin >> stor.out_date.day;
		cin.ignore();

		cout << "K�� ������: ";
		cin >> stor.good_ind;
		cin.ignore();

		cout << "K�� ����������: ";
		cin >> stor.dealer_ind;
		cin.ignore();

		cout << "K�� ���������: ";
		cin >> stor.orderer_ind;
		cin.ignore();

		cout << "��� ��������: ";
		getline(cin, stor.delivery_type);

		cout << "����� ������: ";
		getline(cin, stor.size);

		cout << "����: ";
		getline(cin, stor.price);

		cout << "��� ����������: ";
		cin >> stor.eploy_ind;
		cin.ignore();
	}

	void AddToFileSC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Storage.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			fout << left
				<< setw(3) << stor.in_date.day
				<< setw(3) << stor.in_date.month
				<< setw(6) << stor.in_date.year
				<< setw(3) << stor.ord_date.day
				<< setw(3) << stor.ord_date.month
				<< setw(6) << stor.in_date.year
				<< setw(3) << stor.out_date.day
				<< setw(3) << stor.out_date.month
				<< setw(6) << stor.out_date.year
				<< setw(5) << stor.good_ind
				<< setw(5) << stor.dealer_ind
				<< setw(5) << stor.orderer_ind
				<< setw(15)<< stor.delivery_type
				<< setw(10)<< stor.size
				<< setw(7) << stor.price
				<< setw(5) << stor.eploy_ind
				<< endl;
		}
		else
			cout << "Ooooooops.. " << endl;

		fout.close();	
	}

	void ReadFromFileSC(ifstream *fin)
	{
		buffer = "";
		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.in_date.day = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.in_date.month = buffer; buffer = "";

		for (int i = 0; i < 6; i++)
			buffer += fin->get();
		stor.in_date.year = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.ord_date.day = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.ord_date.month = buffer; buffer = "";

		for (int i = 0; i < 6; i++)
			buffer += fin->get();
		stor.ord_date.year = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.out_date.day = buffer; buffer = "";

		for (int i = 0; i < 3; i++)
			buffer += fin->get();
		stor.out_date.month = buffer; buffer = "";

		for (int i = 0; i < 6; i++)
			buffer += fin->get();
		stor.out_date.year = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		stor.good_ind = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		stor.dealer_ind = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		stor.orderer_ind = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		stor.delivery_type = buffer; buffer = "";

		for (int i = 0; i < 10; i++)
			buffer += fin->get();
		stor.size = buffer; buffer = "";

		for (int i = 0; i < 7; i++)
			buffer += fin->get();
		stor.price = buffer; buffer = "";

		for (int i = 0; i <= 5; i++)
			buffer += fin->get();
		stor.eploy_ind = buffer; buffer = "";
	}

	void SearchDT()
	{
		ifstream finSD;
		finSD.open("C:\\Pract\\Storage.txt", ios::in);
		string src;
		cout << "������� ������� ��� ��������: ";
		cin.ignore();
		getline(cin, src);
		DeleteLastSps(src);
		while (finSD.peek() != EOF)
		{
			ReadFromFileSC(&finSD);
			DeleteLastSps(stor.in_date.day);
			DeleteLastSps(stor.in_date.month);
			DeleteLastSps(stor.in_date.year);
			DeleteLastSps(stor.ord_date.day);
			DeleteLastSps(stor.ord_date.month);
			DeleteLastSps(stor.ord_date.year);
			DeleteLastSps(stor.out_date.day);
			DeleteLastSps(stor.out_date.month);
			DeleteLastSps(stor.out_date.year);
			DeleteLastSps(stor.good_ind);
			DeleteLastSps(stor.dealer_ind);
			DeleteLastSps(stor.orderer_ind);
			DeleteLastSps(stor.delivery_type);
			DeleteLastSps(stor.size);
			DeleteLastSps(stor.price);
			DeleteLastSps(stor.eploy_ind);
			string  datain, dataord, dataout;
			datain += stor.in_date.day; datain += '/'; datain += stor.in_date.month; datain += '/'; datain += stor.in_date.year;
			dataord += stor.ord_date.day; dataord += '/'; dataord += stor.ord_date.month; dataord += '/'; dataord += stor.ord_date.year;
			dataout += stor.out_date.day; dataout += '/'; dataout += stor.out_date.month; dataout += '/'; dataout += stor.out_date.year;

			if (src == stor.delivery_type)
			{
				cout << left
					<< setw(25) << "���� ����������� ������"
					<< setw(15) << "���� ������"
					<< setw(15) << "���� ��������"
					<< setw(15) << "K�� ������"
					<< setw(16) << "K�� ����������"
					<< setw(15) << "K�� ���������"
					<< setw(15) << "��� ��������"
					<< setw(15) << "����� ������"
					<< setw(7) << "����"
					<< setw(15) << "��� ����������" << endl;

				cout << left
					<< setw(25) << datain
					<< setw(15) << dataord
					<< setw(15) << dataout
					<< setw(15) << stor.good_ind
					<< setw(16) << stor.dealer_ind
					<< setw(15) << stor.orderer_ind
					<< setw(15) << stor.delivery_type
					<< setw(15) << stor.size
					<< setw(7) << stor.price
					<< setw(15) << stor.eploy_ind << endl;
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
			if (str[i] == ' ')
			{
				str.erase(i, 1);
				i--;
			}
		}
	}
};