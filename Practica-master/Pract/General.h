#include <string>
#ifndef GENERAL_H
#define GENERAL_H
using namespace std;

struct full_name
{
	string name;
	string sec_name;
	string surname;
};

struct date
{
	string day;
	string month;
	string year;
};

struct adress
{
	string city;
	string street_name;
	string house;
	string flat;
};

#endif
