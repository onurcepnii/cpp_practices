/*
	Print 0 to 100 without using any loop.
 
	Öyle bir kod yazın ki 0'dan 100'e kadar olan sayıları yazdırın ama döngü kullanılmasın.
*/

// Yöntem 1  (Templates | Explicit Specialization)
------------------------------------------------------------------
#include <iostream>

template <int I>
void foo()
{
	std::cout << I << " ";
	foo<I + 1>();
}

template <>
void foo<100>() {
	std::cout << 100;
}

int main()
{
	foo<0>();
}


// Yöntem 2  (Templates | Explicit Specialization)
------------------------------------------------------------------
#include <iostream>
  
template <int N>
struct Print : Print<N - 1> {
	Print()
	{
		std::cout << N << ' ';
	}
};

template <>
struct Print<-1> {

};

int main()
{
	Print<100> x;
}

//Yöntem 3  (Class)
------------------------------------------------------------------
#include <iostream>
  
class Myclass {
public:
	Myclass()
	{
		int static cnt = 0;
		std::cout << cnt++ << " ";
	}
};

int main()
{
	Myclass myclass[101];
}
