#ifndef ORDERER_H
#define ORDERER_H
#include "General.h"
#include <string>
using namespace std;

struct orderer
{
	string orderer_ind; // ��� ���������
	string name;
	struct adress orer_adr;
	string phone;
	string del_good1; // ��� ������������� ������ 1
	string del_good2; // ��� ������������� ������ 2
	string del_good3; // ��� ������������� ������ 3
};
#endif // !ORDERER_H

