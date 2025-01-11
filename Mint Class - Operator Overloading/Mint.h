#include <ostream>


class Mint {
private:
	int mval;
public:
	Mint() = default;
	explicit Mint(int x) : mval(x) {};

	friend [[nodiscard]] Mint operator+(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] Mint operator-(const Mint& lhs, const Mint& rhs);
	
	friend [[nodiscard]] Mint operator*(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] Mint operator/(const Mint& lhs, const Mint& rhs);

	friend [[nodiscard]] bool operator==(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] bool operator!=(const Mint& lhs, const Mint& rhs);

	friend [[nodiscard]] bool operator<(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] bool operator>(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] bool operator<=(const Mint& lhs, const Mint& rhs);
	friend [[nodiscard]] bool operator>=(const Mint& lhs, const Mint& rhs);

	//sign operators
	Mint [[nodiscard]] operator+()const;
	Mint [[nodiscard]] operator-()const;

	bool [[nodiscard]] operator!()const;

	//decrement-increment operators
	Mint [[nodiscard]] operator++();	//prefix
	Mint [[nodiscard]] operator++(int);	//postfix

	Mint [[nodiscard]] operator--();	//prefix
	Mint [[nodiscard]] operator--(int);	//postfix

	//assign operators
	Mint& operator+=(const Mint&);
	Mint& operator-=(const Mint&);
	Mint& operator*=(const Mint&);
	Mint& operator/=(const Mint&);
	Mint& operator%=(const Mint&);

	friend std::ostream& operator<<(std::ostream& os, const Mint& mint);
	friend std::istream& operator>>(std::istream& is, Mint& mint);

};

