#ifndef ORDERER_H
#define ORDERER_H
#include "General.h"
#include <string>
using namespace std;

struct orderer
{
	string orderer_ind; // код заказчика
	string name;
	struct adress orer_adr;
	string phone;
	string del_good1; // код поставляемого товара 1
	string del_good2; // код поставляемого товара 2
	string del_good3; // код поставляемого товара 3
};
#endif // !ORDERER_H

