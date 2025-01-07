#include <iostream>

class Device {
public:
	bool status = false;
	bool is_on()
	{
		if (status)
			return true;
		else
			return false;
	}
	void turn_on()
	{
		if (!status)
			status = true;
		else
			std::cout << "Device: It's already on!\n";
	}
	void turn_off()
	{
		if (status) {
			status = false;
			std::cout << "Device: It turned off.\n";
		}
		else
			std::cout << "Device: It's already off.\n";
	}
};

class Printer : virtual public Device {
public:
	void print()
	{
		if (is_on())
			std::cout << "Printing...\n";
		else
			std::cout << "Turn on the device first.\n";
	}

};

class Scanner : virtual public Device {
public:
	void scan()
	{
		if (is_on())
			std::cout << "Scanning...\n";
		else
			std::cout << "Turn on the device first.\n";
	}

};

class Combo : public Printer, public Scanner {
public:
};

int main()
{
	
	Combo cm;
	cm.print();
	cm.scan();
	cm.turn_off();
	cm.turn_on();
	cm.print();
	cm.scan();
	cm.turn_on();
	cm.turn_off();

}
