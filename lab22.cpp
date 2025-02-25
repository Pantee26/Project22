#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs() const;
        double angle() const;
		friend ComplexNumber operator+(double, const ComplexNumber &);
        friend ComplexNumber operator-(double, const ComplexNumber &);
        friend ComplexNumber operator*(double, const ComplexNumber &);
        friend ComplexNumber operator/(double, const ComplexNumber &);
        friend ComplexNumber operator==(double, const ComplexNumber &);
        
        friend ostream &operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, 
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    if (real == c.real && imag == c.imag){
        return true;
    }
    else {
        return false;
    }
}

ComplexNumber operator+(double y, const ComplexNumber &c){
	return ComplexNumber(y+c.real,c.imag);
}

ComplexNumber operator-(double y, const ComplexNumber &c){
	return ComplexNumber(y-c.real,-c.imag);
}

ComplexNumber operator*(double y, const ComplexNumber &c){
	return ComplexNumber(y*c.real,y*c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((d * c.real) / denominator, (-d * c.imag) / denominator);
}

 ComplexNumber operator==(double y, const ComplexNumber &c){
     if (y == c.real && y == c.imag){
        return true;
    }
    else {
        return false;
    }
 }


ostream &operator<<(ostream &os, const ComplexNumber &c) {
    if (c.imag == 0) os << c.real;
    else if (c.real == 0) os << c.imag << "i";
    else os << c.real << (c.imag > 0 ? "+" : "-") << abs(c.imag) << "i";
    return os;
}

double ComplexNumber::abs() const {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() const {
    return atan2(imag, real) * (180.0 / M_PI);
}