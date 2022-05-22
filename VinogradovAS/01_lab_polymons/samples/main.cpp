#include "node.h"
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <string>
#include <headlist.h>
using namespace std;

void ResultOutput(char op, TPolynom& p1, TPolynom& p2) {
	if (op == '+') {
		cout << "���������: " << p1 + p2 << endl;
	}
	else if (op == '-') {
		cout << "���������: " << p1 - p2 << endl;
	}else cout << "���������: " << p1 * p2 << endl;
}

int main1() {
	TPolynom p1("x+y");
	TPolynom p2("x-y");
	p1 == p2;

	return 0;
}

int main() {
	string str1 = "1+x";
	string str2 = "1-y";
	TPolynom p1(str1);
	TPolynom p2(str2);
	TPolynom p3;
	p3 = p1 * p2;
	//p3 = ResultOutput('+', p1, p2);
	cout << p3;
	return 0;
}


int main2()
{
	setlocale(LC_ALL, "Russian");
	string str1 = "xyz", str2;
	char op;
	int flag = 1;
	cout << "����������� ���������, ������� ����� �� ����������, �������� � ��������!" << endl << endl;
	while (flag == 1) {
		cout << "������� ������ �������:" << endl;
		cout << "p1 = ";
		cin >> str1;
		TPolynom p1(str1);
		
		cout << "������� ������ �������:" << endl;
		cout << "p2 = ";
		cin >> str2;
		TPolynom p2(str2);
		cout << "������� ��������, ������� �� ������ ��������� � ���(+,-,*): ";
		cin >> op;
		ResultOutput(op, p1, p2);
		cout << endl << "���� ������ ����������, ������� 1, ���� ������ ���������, �� ������� 0 " << endl;
		cin >> flag;
		cout << endl;
	}
	
	return 0;
}