#ifndef ORDERER_H
#define ORDERER_H
#include "General.h"
#include <string>
using namespace std;

struct orderer
{
	int orderer_ind; // код заказчика
	string name;
	struct adress orer_adr;
	int phone;
	int del_good1; // код поставляемого товара 1
	int del_good2; // код поставляемого товара 2
	int del_good3; // код поставляемого товара 3
};
#endif // !ORDERER_H

