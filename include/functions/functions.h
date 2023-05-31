#pragma once
#include <cstdio>
#include <memory>
#include <vector>
#include <string>]
#include <conio.h>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <windows.h>

namespace vehicle {
	
	class Vehicle { 

	protected:
		
		std::string _name;
		double _v;
		
	public:

		Vehicle();
		Vehicle(const std::string& name, double v); 
		Vehicle(const Vehicle&) = default; 
		Vehicle& operator=(const Vehicle&) = default;
		std::string get_name() const;
		double get_v() const;
		virtual double calc(double s) = 0; 
		virtual void print() const = 0;
		virtual std::shared_ptr<Vehicle> clone() const = 0;

	};

	class Car : public Vehicle {

	public:

		Car();
		Car(const std::string& name, double v);
		double calc(double s) override; 
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;

	};

	class Freight : public Vehicle {

	private:

		double _t;

	public:

		Freight();
		Freight(const std::string& name, double v, double t);
		double get_t() const;
		double calc(double s) override;
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;

	};

	class Motorbike : public Vehicle {

	public:

		Motorbike();
		Motorbike(const std::string& name, double v);
		double calc(double s) override;
		std::shared_ptr<Vehicle> clone() const override;
		void print() const override;

	};

	using VehiclePtr = std::shared_ptr<Vehicle>;

	class VehicleList {

	private:

		std::vector<VehiclePtr> _vehicle;

	public:

		VehicleList() = default; //??
		VehicleList(const VehicleList& list);
		VehicleList& operator=(VehicleList list);
		void swap(VehicleList& list) noexcept;
		const VehiclePtr operator[](size_t index) const; //size_t
		VehiclePtr operator[](size_t index);
		size_t get_size() const;
		void add(VehiclePtr vehicle);
		void insert(VehiclePtr vehicle, int index);
		void remove(int index);
		void print() const;
		void clear();
		int maximal(double s);

	};

}