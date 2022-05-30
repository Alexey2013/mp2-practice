#include "tablesort.h"
#include "tablehash.h"

using namespace std;

void Menut()
{
	system("cls"); // clear
   cout << "1 - ����� ������� � �������� ������"
		<< endl << "2 - �������� ������� � �������� ������"
		<< endl << "3 - ������� ������� � �������� ������"
		<< endl << "4 - �������� �������"
	    << endl << "5 - �������� ��� ����������"
		<< endl << "6 - �������� ������� �������"
		<< endl << "7 - �����"
		<< endl << "8 - Clear console."
		<< endl;
}

void Menut1()
{
   cout << "1 - ��������������� �������"
		<< endl << "2 - ������������� �������"
		<< endl << "3 - ��� �������"
		<< endl << "4 - ��� �������"
		<< endl << "5 - �����"
		<< endl;
}

void Menu()
{
	system("cls"); // clear
	cout << "1 - ������� ��������"
		 << endl << "2 - ������� ��������"
		 << endl << "3 - �������� ������� �� ���������"
		 << endl << "4 - �������� ��������"
		 << endl << "5 - ������ �������� x, y, z"
		 << endl;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int sw, sw2, ch, x, y, z, res;
	double c;
	TTableScan<TPolinom, string> Tscan(200);
	TTableSort<TPolinom, string> Tsort(Tscan);
	TTableHash<TPolinom, string> Thash(200, 1);
	sw = 1;
	while (sw != 7)
	{
		Menut();
		cout << "������� �����: ";
		cin >> sw;
		cin.ignore(32767, '\n');
		switch (sw)
		{
		case 1:
		{
			sw2 = 1;
			string strkey2;
			cout << "������� ����: ";
			getline(cin, strkey2, '\n');
			while (sw2 != 5)
			{
				Menut1();
				cout << "������� �����: ";
				cin >> sw2;
				cin.ignore(32767, '\n');
				switch (sw2)
				{
				case 1:
				{
					cout << Tscan.FindRecord(strkey2);
					break;
				}
				case 2:
				{
					cout << Tsort.FindRecord(strkey2);
					break;
				}
				case 3:
				{
					cout << Thash.FindRecord(strkey2);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 2:
		{
			sw2 = 1;
			string str;
			cout << "������� �������: ";
			getline(cin, str, '\n');
			TPolinom P(str);
			string strkey;
			cout << "������� ����: ";
			getline(cin, strkey, '\n');
			Menut1();
			cout << "������� �����: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
				Tscan.InsertRecord(strkey, P);
				break;
			}
			case 2:
			{
				Tsort.InsertRecord(strkey, P);
				break;
			}
			case 3:
			{
				Thash.InsertRecord(strkey, P);
				break;
			}
			case 4:
			{
				Tscan.InsertRecord(strkey, P);
		    	Tsort.InsertRecord(strkey, P);
				Thash.InsertRecord(strkey, P);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3:
		{
			sw2 = 1;
			string strkey3;
			cout << "������� ����: ";
			getline(cin, strkey3, '\n');
			Menut1();
			cout << "������� �����: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
			try
			{
				Tscan.RemoveRecord(strkey3);
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
			}
			case 2:
			{
				try
				{
				Tsort.RemoveRecord(strkey3);
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
			}
		    case 3:
			{
				try
				{
				Thash.RemoveRecord(strkey3);
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
			}
			case 4:
			{
				try
				{ 
				Tscan.RemoveRecord(strkey3);
				Tsort.RemoveRecord(strkey3);
				Thash.RemoveRecord(strkey3);
				}
				catch (const char* exception)
				{
					std::cerr << "Error: " << exception << '\n';
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4:
		{
			sw2 = 1;
			Menut1();
			cout << "������� �����: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
				try
				{
				Tscan.Clear();
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
				}
			case 2:
			{
				try
				{
				Tsort.Clear();
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
			}
			case 3:
			{
				try
				{
				Thash.Clear();
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
				break;
			}
			case 4:
			{
				try
				{
					Tscan.Clear();
				}
				catch (const char* exception)
				{
					std::cerr << "Error: " << exception << '\n';
				}
				try
				{
					Tsort.Clear();
				}
				catch (const char* exception)
				{
					std::cerr << "Error: " << exception << '\n';
				}
				try
				{
				Thash.Clear();
				}
				catch (const char* exception)
				{
					std::cerr << "Error: " << exception << '\n';
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 5:
		{
			sw2 = 1;
			Menut1();
			cout << "�������� �������: ";
			cin >> ch;
			cin.ignore(32767, '\n');
			Menu();
			cout << "�������� ��������: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			string strkey10;
			cout << "������� ���� ��������: ";
			cin >> strkey10;
			cin.ignore(32767, '\n');
			string strkey11;
			string strkey20;
			TPolinom C;
			TPolinom S;
			TPolinom K;
			switch (sw2)
			{
			case 1:
			{
				cout << "������� ���� 2 ��������: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					string strkey12;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey12;
					cin.ignore(32767, '\n');
					Tscan.InsertRecord(strkey12, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					string strkey13;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey13;
					cin.ignore(32767, '\n');
					Tsort.InsertRecord(strkey13, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					string strkey14;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey14;
					cin.ignore(32767, '\n');
					Thash.InsertRecord(strkey14, C);
				}
				break;
			}
			case 2:
			{
				cout << "������� ���� 2 ��������: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tscan.InsertRecord(strkey20, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tsort.InsertRecord(strkey20, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Thash.InsertRecord(strkey20, C);
				}
				break;
			}
		    case 3:
			{
				cout << "������� ���������: ";
				cin >> c;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tscan.InsertRecord(strkey20, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tsort.InsertRecord(strkey20, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Thash.InsertRecord(strkey20, C);
				}
				break;
			}
			case 4:
			{
				cout << "������� ���� 2 ��������: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tscan.InsertRecord(strkey20, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tsort.InsertRecord(strkey20, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Thash.InsertRecord(strkey20, C);
				}
				break;
			}
			case 5:
			{
				cout << "������� x, y, z: ";
				cin >> x; cin.ignore(32767, '\n'); cin >> y; cin.ignore(32767, '\n'); cin >> z; cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tscan.InsertRecord(strkey20, L);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Tsort.InsertRecord(strkey20, L);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					cout << "������� ���� ��������� ��������: ";
					cin >> strkey20;
					cin.ignore(32767, '\n');
					Thash.InsertRecord(strkey20, L);
				}
				break;
			}
			}
			break;
		}
		case 6:
		{
			sw2 = 1;
			while (sw2 != 5)
			{
				Menut1();
				cout << "������� �����: ";
				cin >> sw2;
				cin.ignore(32767, '\n');
				switch (sw2)
				{
				case 1:
				{
					cout << "ScanT:\n" << Tscan;
					break;
				}
				case 2:
				{
					cout << "SortT:\n" << Tsort;
					break;
				}
				case 3:
				{
					cout << "HashT:\n" << Thash;
					break;
				}
				case 4:
				{
					cout << "ScanT:\n" << Tscan;
					cout << "SortT:\n" << Tsort;
					cout << "HashT:\n" << Thash;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 8:
		{
			Menut();
			break;
		}
		default:
			break;
		}
		}
	return 0;
}