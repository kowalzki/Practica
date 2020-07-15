#ifndef DEALER_H
#define DEALER_H
#include "General.h"
#include <string>
using namespace std;

struct dealer
{
	int dealer_ind; // код поставщика
	string name;
	struct adress dlr_adr;
	int phone;
	int del_good1; // код поставляемого товара 1
	int del_good2; // код поставляемого товара 2
	int del_good3; // код поставляемого товара 3
};

#endif // !DEALER_H

