#include <functions/functions.h>
#include <windows.h>
#include <string>
#include <conio.h>
#include <iostream>

using namespace vehicle;
using namespace std;

void con() {
	cout << " _____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �--------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ���������											  |" << endl;
	cout << " | 2 - �������� ��������� �� �������                                 |" << endl;
	cout << " | 3 - ������� ��������� �� �������                                  |" << endl;
	cout << " | 4 - ������� ������ ����������                                     |" << endl;
	cout << " | 5 - ���������� ��������� ���������                                |" << endl;
	cout << " | 6 - ����� ������� ���������� � ���������� ���������� ���������    |" << endl;
	cout << " | 7 - ����� �� �������                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

shared_ptr<Vehicle> vehicle_build() {

	string name;
	int model;
	float v, t;
	int seal;

	cout << "������� ��� ����������: " << "\n" << "1 - Car" << "\n" << "2 - Freight" << "\n" << "3 - Motorbike" << "\n";
	cin >> model;

	if (model != 1 and model != 2 and model != 3)

		throw runtime_error("wrong value");

	cout << "������� �������� ����������: ";
	getline(cin >> ws, name);

	cout << "������� ������ ���������: ";
	cin >> v;

	switch (model) {

	case 1:

		return make_shared<Car>(name, v);

	case 2:

		cout << "������� ������: ";
		cin >> t;
		return make_shared<Freight>(name, v, t);
	
	case 3:

		return make_shared<Motorbike>(name, v);

	}

}

int main()
{

	SetConsoleTitle("Vehicles");
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	VehicleList vehicles;
	con();

	while (true)
	{
		int q;
		cin >> q;
		int index = 0;
		float s;
		system("cls");
		con();

		if (q == 7) {

			vehicles.clear();
			break;

		}

		switch (q)
		{

		case 1:

			system("cls"); //??
			vehicles.add(vehicle_build());
			system("cls");
			con();
			break;

		case 2:
			cout << "������� ������ ��� ������� ����������: ";
			cin >> index;
			vehicles.insert(vehicle_build(), index);
			break;

		case 3:
			cout << "������� ������ ��� �������� ����������: ";
			cin >> index;
			vehicles.remove(index);
			break;

		case 4:

			vehicles.print();
			break;

		case 5:
			cout << "������� ������� ������ ������: ";
			cin >> s;
			cout << "������� ������ ����������, ��� �������� ����� ���������� �����: ";
			cin >> index;
			cout << vehicles[index]->calc(s);
			break;

		case 6:
			cout << "������� ������� ������ ������: ";
			cin >> s;
			cout << "������ ���������� � ������������ �������: " << vehicles.maximal(s) << endl;
			break;

		}
	}
	return 0;
}