#include <functions/functions.h>
#include <stdexcept>
#include <string>
#include <cmath>


using namespace vehicle;
using namespace std;

Vehicle::Vehicle() : _name(""), _v(0) {}
Vehicle::Vehicle(const std::string& name, double v) : _name(name), _v(v) {}
string Vehicle::get_name() const { return _name; }
double Vehicle::get_v() const { return _v; }

Car::Car() : Vehicle() {}
Car::Car(const std::string& name, double v) : Vehicle(name, v) {}
void Car::print() const { cout << "Тип транспорта: Легковой автомобиль\n   Модель: " << _name << "\n   Объем двигателя: " << _v << endl; }
shared_ptr<Vehicle> Car::clone() const { return make_shared<Car>(_name, _v); }
double Car::calc(double s) { return s * _v; }

Freight::Freight() : Vehicle(), _t(0) {}
Freight::Freight(const std::string& name, double v, double t) : Vehicle(name, v), _t(t) {}
double Freight::get_t() const { return _t; }
void Freight::print() const { cout << "Тип транспорта: Грузовой автомобиль\n   Модель: " << _name << "\n   Базовый тариф перевозки: " << _v << endl; }
shared_ptr<Vehicle> Freight::clone() const { return make_shared<Freight>(_name, _v, _t); }
double Freight::calc(double s) { return s * _v * (_t / 2 + 1); }

Motorbike::Motorbike() : Vehicle() {}
Motorbike::Motorbike(const std::string& name, double v) : Vehicle(name, v) {}
void Motorbike::print() const { cout << "Тип транспорта: Мотоцикл\n   Модель: " << _name << "\n   Базовый тариф перевозки: " << _v << endl; }
shared_ptr<Vehicle> Motorbike::clone() const { return make_shared<Motorbike>(_name, _v); }
double Motorbike::calc(double s) { return 0.3 * s * _v; }

VehicleList::VehicleList(const VehicleList& vehicle) {

	for (int i = 0; i < _vehicle.size(); ++i) {

		_vehicle.push_back(vehicle[i]->clone()); //??

	}

};

VehicleList& VehicleList::operator=(VehicleList vehicle) {

	swap(vehicle);
	return *this; //??

}

void VehicleList::swap(VehicleList& vehicle) noexcept {

	_vehicle.swap(vehicle._vehicle);

}

void VehicleList::clear() {

	_vehicle.clear();

}

const VehiclePtr VehicleList::operator[](size_t index) const {

	if (index < 0 or _vehicle.size() <= index)

		throw out_of_range("Invalid index");

	return _vehicle[index];

}

VehiclePtr VehicleList::operator[](size_t index) {

	if (index < 0 or _vehicle.size() <= index)

		throw out_of_range("Invalid index");

	return _vehicle[index];

}

void VehicleList::add(VehiclePtr vehicle) {

	_vehicle.push_back(vehicle);

}

size_t VehicleList::get_size() const {

	return _vehicle.size();

}

void VehicleList::insert(VehiclePtr vehicle, int index) {

	if (index < 0 or _vehicle.size() <= index)

		throw runtime_error("[VehicleList::insert]Invalid index");

	_vehicle.insert(_vehicle.begin() + index, vehicle); //??
}

void VehicleList::remove(int index) {

	if (index < 0 or _vehicle.size() <= index)

		throw runtime_error("[VehicleList::remove]Invalid index");

	_vehicle.erase(_vehicle.begin() + index); //??

}

void VehicleList::print() const {

	for (int i = 0; i < _vehicle.size(); ++i) {

		cout << " " << i + 1 << ")";
		_vehicle[i]->print();

	}

	cout << endl; //??

}

int VehicleList::maximal(double s) {

	int sz = _vehicle.size();
	int index = -1;
	double max_tax = _vehicle[0]->calc(s);

	for (int i = 1; i < sz; i++) {

		const double tax = _vehicle[i]->calc(s);

		if ((index == -1) or (tax < max_tax)) {

			index = i;
			max_tax = tax;

		}

	}

	return index;

}