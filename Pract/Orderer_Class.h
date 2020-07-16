#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include "Orderer.h"
#include "Good_Class.h"
using namespace std;

class Orderer_Class
{
public:
	orderer Odr;
	Good_Class goCl;
	string buffer = "";

	void ShowO()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Orderer.txt", ios::in);
		system("cls");

		while (finE.peek() != EOF)
		{
			ReadFromFileDC(&finE);
			DeleteLastSps(Odr.orderer_ind);
			DeleteLastSps(Odr.name);
			DeleteLastSps(Odr.orer_adr.city);
			DeleteLastSps(Odr.orer_adr.street_name);
			DeleteLastSps(Odr.orer_adr.house);
			DeleteLastSps(Odr.orer_adr.flat);
			DeleteLastSps(Odr.del_good1);
			DeleteLastSps(Odr.del_good2);
			DeleteLastSps(Odr.del_good3);

			cout << left
				<< setw(15) << "Код заказчика"
				<< setw(20) << "Название заказчика"
				<< setw(15) << "Город"
				<< setw(15) << "Улица"
				<< setw(5) << "Дом"
				<< setw(6) << "Офис"
				<< setw(15) << "Код товара 1"
				<< setw(15) << "Код товара 2"
				<< setw(15) << "Код товара 3" << endl;

			cout << left
				<< setw(15) << Odr.orderer_ind
				<< setw(20) << Odr.name
				<< setw(15) << Odr.orer_adr.city
				<< setw(15) << Odr.orer_adr.street_name
				<< setw(5)  << Odr.orer_adr.house << '/'
				<< setw(6)  << Odr.orer_adr.flat
				<< setw(15) << Odr.del_good1
				<< setw(15) << Odr.del_good2
				<< setw(15) << Odr.del_good3 << endl;

			cout << "Дополнительная информация:\n";
			cout << "Информация по товару с индексом 1" << endl;
			goCl.RFFSearchG(Odr.del_good1);
			cout << "Информация по товару с индексом 2" << endl;
			goCl.RFFSearchG(Odr.del_good2);
			cout << "Информация по товару с индексом 3" << endl;
			goCl.RFFSearchG(Odr.del_good3);
		}
	}

	void RFFSearchO()
	{
		ifstream finE;
		finE.open("C:\\Pract\\Orderer.txt", ios::in);
		system("cls");
		cout << "Введите наименование заказчика: ";
		string srch = "";
		cin.ignore();
		getline(cin, srch);
		DeleteLastSps(srch);

		while (srch != Odr.name)
		{
			ReadFromFileDC(&finE);
			DeleteLastSps(Odr.orderer_ind);
			DeleteLastSps(Odr.name);
			DeleteLastSps(Odr.orer_adr.city);
			DeleteLastSps(Odr.orer_adr.street_name);
			DeleteLastSps(Odr.orer_adr.house);
			DeleteLastSps(Odr.orer_adr.flat);
			DeleteLastSps(Odr.del_good1);
			DeleteLastSps(Odr.del_good2);
			DeleteLastSps(Odr.del_good3);

			if (srch == Odr.name)
			{
				cout << left
					<< setw(15) << "Код заказчика"
					<< setw(20) << "Название заказчика"
					<< setw(15) << "Город"
					<< setw(15) << "Улица"
					<< setw(5) << "Дом"
					<< setw(6) << "Офис"
					<< setw(15) << "Код товара 1"
					<< setw(15) << "Код товара 2"
					<< setw(15) << "Код товара 3" << endl;

				cout << left
					<< setw(15) << Odr.orderer_ind
					<< setw(20) << Odr.name
					<< setw(15) << Odr.orer_adr.city
					<< setw(15) << Odr.orer_adr.street_name
					<< setw(5) << Odr.orer_adr.house << '/'
					<< setw(6) << Odr.orer_adr.flat
					<< setw(15) << Odr.del_good1
					<< setw(15) << Odr.del_good2
					<< setw(15) << Odr.del_good3 << endl;

				cout << "Дополнительная информация:\n";
				cout << "Информация по товару с индексом 1" << endl;
				goCl.RFFSearchG(Odr.del_good1);
				cout << "Информация по товару с индексом 2" << endl;
				goCl.RFFSearchG(Odr.del_good2);
				cout << "Информация по товару с индексом 3" << endl;
				goCl.RFFSearchG(Odr.del_good3);
			}
			if (finE.peek() == EOF)
			{
				cout << "Nope" << endl;
				break;
			}
		}
	}

	void AddElemOC()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(0, "");
		ios_base::left;
		cout << "Ввод данных о заказчиках" << endl;

		cout << "Код заказчика: ";
		cin >> Odr.orderer_ind;
		cin.ignore();

		cout << "Введите название заказчика: ";
		getline(cin, Odr.name);

		cout << "Введите адрес" << endl
			<< "Город: ";
		cin >> Odr.orer_adr.city;
		cin.ignore();

		cout << "Улица: ";
		cin >> Odr.orer_adr.street_name;
		cin.ignore();

		cout << "№ дома: ";
		cin >> Odr.orer_adr.house;
		cin.ignore();

		cout << "№ офиса: ";
		cin >> Odr.orer_adr.flat;
		cin.ignore();

		cout << "Введите код поставляемого товара 1: ";
		cin >> Odr.del_good1;
		cin.ignore();

		cout << "Введите код поставляемого товара 2: ";
		cin >> Odr.del_good2;
		cin.ignore();

		cout << "Введите код поставляемого товара 3: ";
		cin >> Odr.del_good3;
		cin.ignore();
	}

	void AddToFileOC()
	{
		ofstream fout;
		fout.open("C:\\Pract\\Orderer.txt", ios::app);
		ios_base::left;

		if (fout.is_open())
		{
			fout << left
				<< setw(5)  << Odr.orderer_ind
				<< setw(20) << Odr.name
				<< setw(15) << Odr.orer_adr.city
				<< setw(15) << Odr.orer_adr.street_name
				<< setw(4)  << Odr.orer_adr.house
				<< setw(4)  << Odr.orer_adr.flat
				<< setw(5)  << Odr.del_good1
				<< setw(5)  << Odr.del_good2
				<< setw(5)  << Odr.del_good3 << endl;
		}
		else
			cout << "Ooooooops.. " << endl;
		fout.close();
	}

	void ReadFromFileDC(ifstream* fin)
	{
		buffer = "";
		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Odr.orderer_ind = buffer; buffer = "";

		for (int i = 0; i < 20; i++)
			buffer += fin->get();
		Odr.name = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Odr.orer_adr.city = buffer; buffer = "";

		for (int i = 0; i < 15; i++)
			buffer += fin->get();
		Odr.orer_adr.street_name = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Odr.orer_adr.house = buffer; buffer = "";

		for (int i = 0; i < 4; i++)
			buffer += fin->get();
		Odr.orer_adr.flat = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Odr.del_good1 = buffer; buffer = "";

		for (int i = 0; i < 5; i++)
			buffer += fin->get();
		Odr.del_good2 = buffer; buffer = "";

		for (int i = 0; i <= 5; i++)
			buffer += fin->get();
		Odr.del_good3 = buffer; buffer = "";
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