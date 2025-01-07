//
//    Virtual Constructor Idiom - Clone Idiom
//

#include <iostream>

class Truck {
	virtual void start()
	{
		std::cout << "Truck::start()\n";
	}
	virtual void run()
	{
		std::cout << "Truck::run()\n";
	}
	virtual void stop()
	{
		std::cout << "Truck::stop()\n";
	}
	virtual Truck* clone() = 0;		//clone idiom
};

class BMC : public Truck {
public:
	void start()override
	{
		std::cout << this << " : " << "BMC::start()\n";
	}
	void run()override
	{
		std::cout << this << " : " << "BMC::run()\n";
	}
	void stop()override
	{
		std::cout << this << " : " << "BMC::stop()\n";
	}
	BMC* clone()override
	{
		return new BMC(*this);
	}
};


int main()
{
	BMC my_bmc1;
	BMC* my_bmc2 = my_bmc1.clone();

	my_bmc1.start();
	my_bmc1.stop();

	my_bmc2->start();
	my_bmc2->stop();
}
