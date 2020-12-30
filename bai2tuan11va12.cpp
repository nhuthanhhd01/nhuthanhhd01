#include<iostream>
using namespace std;
class Complex {
	int real, imag;
public:
	Complex(int r = 0, int i = 0) : real(r), imag(i) {}
	Complex operator+(const Complex& b) const {
		Complex z(real + b.real, imag + b.imag);
		return z;
	}
	Complex operator-(const Complex& b) const {
		return Complex(real - b.real, imag - b.imag);
	}
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;
	Complex& operator +=(const Complex&);
	Complex& operator -=(const Complex&);
	friend ostream& operator<<(ostream& os, const Complex SP)
	{
		if (SP.real == 0 && SP.imag == 0)
		{
			os << "0";
		}
		else if (SP.real == 0)
		{
			os << SP.imag << "i";
		}
		else if (SP.imag == 0)
		{
			os << SP.real;
		}
		else
		{
			os << SP.real;
			if (SP.imag > 0)
			{
				os << "+";
			}
			os << SP.imag << "i";
		}
		return os;
	}
};

int main() {
	Complex A, B(1, 2), C(3, 1), D(1, 1), E(-2, 6);
	A = B * C + (D - E);
	cout << "B = " << B << endl << "C = " << C << endl << "D = " << D << endl << "E = " << E << endl << "A = B * C + (D - E) = " << A;
	return 0;
}

Complex Complex::operator*(const Complex& b) const
{
	Complex z(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
	return z;
}

Complex Complex::operator/(const Complex& b) const
{
	Complex z((real * b.real + imag * b.imag) / (b.real * b.real + b.imag * b.imag), (-real * b.imag + imag * b.real) / (b.real * b.real + b.imag * b.imag));
	return z;
}

Complex& Complex::operator +=(const Complex& b)
{
	this->real += b.real;
	this->imag += b.imag;
	return *this;
}

Complex& Complex::operator -=(const Complex& b)
{
	this->real -= b.real;
	this->imag -= b.imag;
	return *this;
}
