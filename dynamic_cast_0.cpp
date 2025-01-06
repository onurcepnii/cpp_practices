#include <iostream>

class Car {
public:
	virtual ~Car() = default;
	virtual void start()
	{
		std::cout << "Car::start()\n";
	}
	virtual void run()
	{
		std::cout << "Car::run()\n";
	}
	virtual void stop()
	{
		std::cout << "Car::stop()\n";
	}
	virtual void car_name()
	{
		std::cout << "Car::car_name() " << c_name << "\n";
	}

	void non_vir()  // virtual dispatch works here
	{
		start();
		run();
		stop();
		car_name();
	}

private:
	std::string c_name{ "Car" };
};

class TOGG : public Car {
public:
	void start()override
	{
		std::cout << "TOGG::start()\n";
	}
	void run()override
	{
		std::cout << "TOGG:run()\n";
	}
	void stop()override
	{
		std::cout << "TOGG::stop()\n";
	}
	void car_name()override
	{
		std::cout << "Car Name :" << c_name << "\n";
	}

private:
	std::string c_name{ "TOGG" };
};



class TOGG_T10X : public TOGG {
public:
	void start()override
	{
		std::cout << "TOGG_T10X::start()\n";
	}
	void run()override
	{
		std::cout << "TOGG_T10X:run()\n";
	}
	void stop()override
	{
		std::cout << "TOGG_T10X::stop()\n";
	}
	void open_sunroof()
	{
		std::cout << "TOGG T10X Sunroof is opening...\n";
	}
	void car_name()override
	{
		std::cout << "Car Name :" << c_name << "\n";
	}

private:
	std::string c_name{ "TOGG_T10X" };
};


class Mercedes : public Car {
public:
	void start()override
	{
		std::cout << "Mercedes::start()\n";
	}
	void run()override
	{
		std::cout << "Mercedes:run()\n";
	}
	void stop()override
	{
		std::cout << "Mercedes::stop()\n";
	}
	void car_name()override
	{
		std::cout << "Car Name :" << c_name << "\n";
	}

private:
	std::string c_name{ "Mercedes" };
};


class Volvo : public Car {
public:
	void start()override
	{
		std::cout << "Volvo::start()\n";
	}
	void run()override
	{
		std::cout << "Volvo:run()\n";
	}
	void stop()override
	{
		std::cout << "Volvo::stop()\n";
	}
	void car_name()override
	{
		std::cout << "Car Name :" << c_name << "\n";
	}

private:
	std::string c_name{ "Volvo" };
};

void Car_func(Car* p)
{
	p->start();
	p->run();
	p->stop();

	if (TOGG_T10X* mytogg =dynamic_cast<TOGG_T10X*>(p)) {
		mytogg->open_sunroof();
	}

}


int main()
{

	Car* car = new TOGG_T10X;

	std::cout << "\n";

	Car_func(car);

	delete car;  // there is no ub, we have virtual destructor for that


}
