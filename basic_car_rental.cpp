//
//	Car Rental
//

#include <iostream>
#include <typeinfo>
#include <vector>
#include <utility>

enum class Model {
	XC90,
	MEGANE,
	T10X,
};

enum class Fuel {
	Petrol,
	Diesel,
	Electric,
	Hybrid
};

class Car {
private:
	Model car_model;
	int car_age;
	int car_value;
	int car_km;
	Fuel car_fuel_type;
	bool rented = false;
public:
	Car(Model car_model, int car_age, int car_value,int car_km, Fuel car_fuel_type) : car_model(car_model), car_age(car_age), car_value(car_value), car_km(car_km), car_fuel_type(car_fuel_type) {}
	virtual Car* clone() = 0;
	virtual ~Car() = default;

	// getters & setters
	Model get_car_model()const
	{
		return car_model;
	}
	int get_car_age()const
	{
		return car_age;
	}
	int get_car_value()const
	{
		return car_value;
	}
	int get_rented_info()const
	{
		return rented;
	}
	int get_car_km()const
	{
		return car_km;
	}
	Fuel get_car_fuel_type()const
	{
		return car_fuel_type;
	}

	void set_car_model(Model new_model)
	{
		car_model = new_model;
	}
	void set_car_age(int new_age)
	{
		car_age = new_age;
	}
	void set_car_value(int new_value)
	{
		car_value = new_value;
	}
	void set_rented_info(bool new_status)
	{
		rented = new_status;
	}
	void set_car_km(int new_km)
	{
		car_km = new_km;
	}
	void set_car_fuel_type(Fuel new_fuel_type)
	{
		car_fuel_type = new_fuel_type;
	}
	//
};

static std::ostream& operator<<(std::ostream& os, const Model& model)
{
	switch (model) {
	case Model::XC90:
		return os << "Volvo - XC90";
	case Model::MEGANE:
		return os << "Renault - Megane";
	case Model::T10X:
		return os << "TOGG - T10X";
	}
}
static std::ostream& operator<<(std::ostream& os, const Fuel& fuel)
{
	switch (fuel) {
	case Fuel::Petrol:
		return os << "Petrol";
	case Fuel::Diesel:
		return os << "Diesel";
	case Fuel::Electric:
		return os << "Electric";
	case Fuel::Hybrid:
		return os << "Hybrid";
	}
}
static std::ostream& operator<<(std::ostream& os, const Car& car)
{
	return os << "| " << car.get_car_model() << " | Age : " << car.get_car_age() << " | KM : " << car.get_car_km() << " | Fuel Type : " << car.get_car_fuel_type() << " |\n";
}


class Volvo : public Car {
public:
	Volvo(Model car_model, int car_age, int car_value, int car_km, Fuel car_fuel_type) : Car(car_model, car_age, car_value, car_km, car_fuel_type) {}
	Volvo* clone()override
	{
		return new Volvo(*this);
	}
};
class Renault : public Car {
public:
	Renault(Model car_model, int car_age, int car_value, int car_km, Fuel car_fuel_type) : Car(car_model, car_age, car_value, car_km, car_fuel_type) {}
	Renault* clone()override
	{
		return new Renault(*this);
	}
};
class TOGG : public Car {
public:
	TOGG(Model car_model, int car_age, int car_value, int car_km, Fuel car_fuel_type) : Car(car_model, car_age, car_value, car_km, car_fuel_type) {}
	TOGG* clone()override
	{
		return new TOGG(*this);
	}

};


class Client {
private:
	std::string client_full_name;
	int client_id;
	int client_age;
	Car* rented_car;
public:
	Client(std::string name, int id, int age, Car* rented_car = nullptr) : client_full_name(name), client_id(id), client_age(age), rented_car(rented_car) {}

	// getters & setters
	std::string get_client_full_name()const
	{
		return client_full_name;
	}
	int get_client_id()const
	{
		return client_id;
	}
	int get_client_age()const
	{
		return client_age;
	}
	Car* get_rented_car()const
	{
		return rented_car;
	}

	void set_rented_car(Car* car)
	{
		rented_car = car;
	}
	void set_client_id(int id)
	{
		client_id = id;
	}
	void set_client_age(int age)
	{
		client_age = age;
	}
	void set_client_full_name(std::string name)
	{
		client_full_name = name;
	}

	void list_client_detailed()const
	{
		std::cout << "| " << client_full_name << " |\n" << "ID:" << client_id << "\nAge:" << client_age << "\nRented Car: " << *rented_car;
	}

};

class Rental {
public:
	std::vector<Car*> carpark;
	std::vector<Car*> rented_cars;
public:
	~Rental() = default;

	//rent
	void rent_a_car(Client* client, Car* car, int rent_duration)
	{
		if (client->get_client_age() > 16)
		{
			car->set_rented_info(true);
			rented_cars.push_back(car);
			carpark.erase(std::remove(carpark.begin(), carpark.end(), car), carpark.end()); 
			client->set_rented_car(car);
			std::cout << "Mr." << client->get_client_full_name() << " | " << car->get_car_model() << " car rented successfully for " << rent_duration << " days.\n";
		}
		else
			std::cout << "Rent attempt failed.\n";	// degisecek
	}
	Car* find_suitable_car(Model preferred_model)
	{
		for (auto& car : carpark) {
			if ((car->get_car_model() == preferred_model)) {
				return car;
			}
		}
		return nullptr;
	}

	//listing
	void list_all_cars()const
	{
		std::cout << "## Available Cars ##\n";
		if (carpark.empty())
			std::cout << "No cars available in carpark.\n";
		for (auto& car : carpark) {
			std::cout <<"Model: " << car->get_car_model() << "\n" <<
				"Age: " << car->get_car_age() << "\n";
		}
		std::cout << "## Rented Cars ##\n";
		if (rented_cars.empty())
			std::cout << "No cars rented.\n";
		for (auto& car : rented_cars) {
			std::cout << "Model: " << car->get_car_model() << "\n" <<
				"Age: " << car->get_car_age() << "\n";
		}
	}
	void list_available_cars()const
	{
		std::cout << "## Available Cars ## ==>" << carpark.size() << " cars available.\n";
		if (carpark.empty())
			std::cout << "No cars available in carpark.\n";
		for (auto& car : carpark) {
			std::cout << "Model: " << car->get_car_model() << "\n" <<
				"Age: " << car->get_car_age() << "\n";
		}
	}
	void list_rented_cars()const
	{
		std::cout << "## Rented Cars ## ==>" << rented_cars.size() << " cars rented.\n";
		if (rented_cars.empty())
			std::cout << "No cars rented.\n";
		for (auto& car : rented_cars) {
			std::cout << "Model: " << car->get_car_model() << "\n" <<
				"Age: " << car->get_car_age() << "\n";
		}
	}

	void add_car_to_carpark(Car* car)
	{
		carpark.push_back(car);
		std::cout << "Car added to carpark!\n";
	}
	void remove_car(Car* car)
	{
		carpark.erase(std::remove(carpark.begin(), carpark.end(), car), carpark.end());
	}

};

int main()
{
	Client client(std::string("Onur Cepni"), 22092, 30);
	Rental rental;
	

	Volvo volvo(Model::XC90, 2, 19000, 2000, Fuel::Petrol);
	TOGG togg(Model::T10X, 1, 19500, 1900, Fuel::Electric);
	Renault renault(Model::MEGANE, 4, 12500, 2000, Fuel::Diesel);
	

	rental.add_car_to_carpark(&volvo);
	rental.add_car_to_carpark(&togg);
	rental.add_car_to_carpark(&renault);

	rental.remove_car(&volvo);
	
	rental.list_all_cars();
	rental.list_available_cars();
	rental.list_rented_cars();

	Car* mycar = rental.find_suitable_car(Model::MEGANE);
	rental.rent_a_car(&client, mycar, 12);

	

}
