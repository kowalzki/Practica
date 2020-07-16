#ifndef DEALER_H
#define DEALER_H
#include "General.h"
#include <string>
using namespace std;

struct dealer
{
	string dealer_ind; // код поставщика
	string name;
	struct adress dlr_adr;
	string phone;
	string del_good1; // код поставляемого товара 1
	string del_good2; // код поставляемого товара 2
	string del_good3; // код поставляемого товара 3
};

#endif // !DEALER_H

