//
//   Virtual Destructor
//

#include <iostream>

class Base {
public:
	int mx;
	virtual ~Base()
	{
		std::cout << "Base::destructor called\n";
	}
};

class Der : public Base {
public:
	~Der()
	{
		std::cout << "Der::destructor called\n";
	}
	
};



int main()
{
	Base* my_obj = new Der{};
	delete my_obj;
}
