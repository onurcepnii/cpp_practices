#include "Mint.h"
#include <iostream>

[[nodiscard]] Mint operator+(const Mint& lhs, const Mint& rhs)
{
	return Mint{ lhs } += rhs;
}
[[nodiscard]] Mint operator-(const Mint& lhs, const Mint& rhs)
{
	return Mint{ lhs } -= rhs;
}

[[nodiscard]] Mint operator*(const Mint& lhs, const Mint& rhs)
{
	return Mint{ lhs } *= rhs;
}
[[nodiscard]] Mint operator/(const Mint& lhs, const Mint& rhs)
{
	return Mint{ lhs } /= rhs;
}

[[nodiscard]] bool operator==(const Mint& lhs, const Mint& rhs)
{
	return lhs.mval == rhs.mval;
}
[[nodiscard]] bool operator!=(const Mint& lhs, const Mint& rhs)
{
	return !(lhs == rhs);
}

[[nodiscard]] bool operator<(const Mint& lhs, const Mint& rhs)
{
	return lhs.mval < rhs.mval;
}
[[nodiscard]] bool operator>(const Mint& lhs, const Mint& rhs)
{
	return !(lhs < rhs);
}
[[nodiscard]] bool operator<=(const Mint& lhs, const Mint& rhs)
{
	return !(rhs < lhs);
}
[[nodiscard]] bool operator>=(const Mint& lhs, const Mint& rhs)
{
	return !(rhs > lhs);
}


//sign operators
[[nodiscard]] Mint Mint::operator+()const
{
	return *this;
}	
[[nodiscard]] Mint Mint::operator-()const
{
	return Mint{ mval };
}

bool [[nodiscard]] Mint::operator!()const
{
	return static_cast<bool>(mval);
}

//decrement-increment operators
Mint [[nodiscard]] Mint::operator++()		//prefix
{
	mval++;
	return *this;
}
Mint [[nodiscard]] Mint::operator++(int)	//postfix
{
	return Mint{ mval++ };
}

Mint [[nodiscard]] Mint::operator--()		//prefix
{
	mval--;
	return  *this;
}
Mint [[nodiscard]] Mint::operator--(int)		//postfix
{
	return Mint{ mval-- };
}

//assign operators
Mint& Mint::operator+=(const Mint& other)
{
	mval += other.mval;
	return *this;
}
Mint& Mint::operator-=(const Mint& other)
{
	mval -= other.mval;
	return *this;
}
Mint& Mint::operator*=(const Mint& other)
{
	mval *= other.mval;
	return *this;
}
Mint& Mint::operator/=(const Mint& other)
{
	mval /= other.mval;
	return *this;
}
Mint& Mint::operator%=(const Mint& other)
{
	mval %= other.mval;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Mint& mint)
{
	return os << mint.mval;
}

std::istream& operator>>(std::istream& is, Mint& mint)
{
	return is >> mint.mval;
}
