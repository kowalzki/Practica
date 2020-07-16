#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "dealer.h"

class Dealer_Class
{
public:
	dealer Dlr;
	string buffer = "";
	
	void AddElemGC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << setw(40) << "Ввод данных о поставщиках" << endl;

		cout << "Индекс поставщика: ";
		cin >> Dlr.dealer_ind;
		cin.ignore();
	
		cout << "Введите название поставщика: ";
		getline(cin, Dlr.name);

		cout << "Введите адрес" << endl
			<< "Город: ";
		cin >> Dlr.dlr_adr.city;
		cin.ignore();

		cout << "Улица: ";
		cin >> Dlr.dlr_adr.street_name;
		cin.ignore();

		cout << "№ дома: ";
		cin >> Dlr.dlr_adr.house;
		cin.ignore();

		cout << "№ офиса: ";
		cin >> Dlr.dlr_adr.flat;
		cin.ignore();

		cout << "Введите код поставляемого товара 1: ";
		cin >> Dlr.del_good1;
		cin.ignore();
	
		cout << "Введите код поставляемого товара 2: ";
		cin >> Dlr.del_good2;
		cin.ignore();

		cout << "Введите код поставляемого товара 3: ";
		cin >> Dlr.del_good3;
		cin.ignore();
	}

	void ShowD()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Dealer.txt", ios::in);
		system("cls");

		while (finE.peek() != EOF)
		{
			ReadFromFileDC(&finE);
			DeleteLastSps(Dlr.dealer_ind);
			DeleteLastSps(Dlr.name);
			DeleteLastSps(Dlr.dlr_adr.city);
			DeleteLastSps(Dlr.dlr_adr.street_name);
			DeleteLastSps(Dlr.dlr_adr.house);
			DeleteLastSps(Dlr.dlr_adr.flat);
			DeleteLastSps(Dlr.del_good1);
			DeleteLastSps(Dlr.del_good2);
			DeleteLastSps(Dlr.del_good3);

		}
	}

	void AddToFileDC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Dealer.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			fout << left
				<< setw(5) << Dlr.dealer_ind
				<< setw(20) << Dlr.name
				<< setw(15) << Dlr.dlr_adr.city
				<< setw(15) << Dlr.dlr_adr.street_name
				<< setw(4) << Dlr.dlr_adr.house
				<< setw(4) << Dlr.dlr_adr.flat
				<< setw(5) << Dlr.del_good1
				<< setw(5) << Dlr.del_good2
				<< setw(5) << Dlr.del_good3 << endl;
		}
		else
			cout << "Ooooooops.. " << endl;
		fout.close();
	}

	void ReadFromFileDC(ifstream *fin)
	{
		buffer = "";
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Dlr.dealer_ind = buffer; buffer = "";

		for (int i = 0; i < 20; i++)
			buffer += fin->get();
		Dlr.name = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Dlr.dlr_adr.city = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Dlr.dlr_adr.street_name = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Dlr.dlr_adr.house = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Dlr.dlr_adr.flat = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Dlr.del_good1 = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Dlr.del_good2 = buffer; buffer = "";

		for (int i = 0; i <= 5; i++)
			buffer += fin->get();
		Dlr.del_good3 = buffer; buffer = "";
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