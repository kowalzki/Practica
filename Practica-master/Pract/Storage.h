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
	int good_ind; // код товара
	int dealer_ind; // код поставщика
	int orderer_ind; // код заказчика
	string delivery_type;
	int size;
	int price;
	int eploy_ind; // код сотрудника
};

#endif // !STORAGE_H

