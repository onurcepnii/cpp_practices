//
//    Composition Containment - Private Inheritence
//
#include <iostream>

class Engine {
public:
	void start_engine()
	{
		std::cout << "Engine started.\n";
	}
};

class TOGG {
	Engine eng;			// containment
public:
	void start_car()
	{
		eng.start_engine();
	}
};

class Volvo : private Engine {		// private inheritence
public:
	void start_car()
	{
		start_engine();		
	}
};

int main()
{
	TOGG my_togg;
	Volvo my_volvo;

	my_togg.start_car();
	my_volvo.start_car();

}
