#ifndef GOOD_H
#define GOOD_H
#include <string>
using namespace std;

struct good
{
	int good_ind; // код товара
	int type_ind; // код типа
	string prod; //производитель
	string name;
	string hold_condit; // условия хранения
	string package; // упаковка
	int exp_date; //cpok годности 
};

#endif // !GOOD_H
