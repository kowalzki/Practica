#ifndef STORAGE_H
#define STORAGE_H
#include "General.h"
#include <string>
using namespace std;

struct storage
{
	struct date in_date;
	struct date ord_date;
	struct date out_date;
	string good_ind; // код товара
	string dealer_ind; // код поставщика
	string orderer_ind; // код заказчика
	string delivery_type;
	string size;
	string price;
	string eploy_ind; // код сотрудника
};

#endif // !STORAGE_H

