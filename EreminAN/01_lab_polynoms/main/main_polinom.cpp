#pragma once
#include "Polynom.h"

using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");

	string polynomStrP;
	string polynomStrQ;
	string Task;
	string Num;
	Polynom Res;
	Polynom P;
	Polynom Q;
	int index = 0;
	int indexP = 0;
	cout << "======== ���� ========" << endl;
	cout << "1. �������� � ����������;" << endl;
	cout << "2. �������� � ������;" << endl;
	cout << "======================" << endl;
	cin >> index;
	if (index == 1)
	{
		cout << "������� ������� P: " << endl;
		cin >> polynomStrP;
		P.parser(polynomStrP);
		cout << "������� ������� Q: " << endl;
		cin >> polynomStrQ;
		Q.parser(polynomStrQ);
		cout << "������� ������:" << endl;
		cin >> Task;
	}
	if (index == 2)
	{
		cout << "������� ������� P: " << endl;
		cin >> polynomStrP;
		P.parser(polynomStrP);
		cout << "������� ������:" << endl;
		cin >> Task;
	}
	int size = 0;
	switch (index)
	{
	case 1:
		indexP = 0;
		while (size <= Task.size())
		{
			if (Task[size] == ' ')
				size++;
			else
			{
				if (Task[size] == 'P')
				{
					size++;
					indexP = 1;
				}
				if (Task[size] == '+' || Task[size] == '*')
				{
					if (Task[size] == '+')
						Res = P + Q;
					else Res = P * Q;
					size = Task.size();
				}
				if (Task[size] == '-')
				{
					if (indexP == 1)
						Res = P - Q;
					else Res = Q - P;
					size = Task.size();
				}
				size++;
			}
		}
		break;
	case 2:
		int size2;
		while (size <= Task.size())
		{
			if (Task[size] == ' ')
				size++;
			else
			{
				if (Task[size] == 'P')
				{
					size++;
					indexP = 1;
				}
				size2 = size;
				while (size2 <= Task.size())
				{
					if (isdigit(Task[size2]))
					{
						while (isdigit(Task[size2]))
						{
							Num += Task[size2];
							size2++;
						}
					}
					size2++;
				}
				if (Task[size] == '+' || Task[size] == '*')
				{
					double N = atof(Num.c_str());
					if (Task[size] == '+')
						Res = P + N;
					else Res = P * N;
					size = Task.size();
				}
				if (Task[size] == '-')
				{
					double N = atof(Num.c_str());
					if (indexP == 1)
						Res = P - N;
					else Res = (P * (-1)) + N;
					size = Task.size();
				}
				size++;
			}
		}
		break;
	default:
		cout << "�������� ����� ����" << endl;
		throw "error";
	}
	Res.cancellation();
	cout << "���������:" << endl;
	cout << Task << " = " << Res << endl;
}