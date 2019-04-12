#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel {
class PhysicalNumber {
private:
Unit U;// the unit of the tayp
double x;//the number
bool someType(const PhysicalNumber& n) const;//private function that chack if they are in the same type.
void errorStream(istream &is,ios::pos_type startPosition);// special error message.

public:

//constractors
PhysicalNumber(double x,Unit U);
// onary
const PhysicalNumber operator+();
const PhysicalNumber operator-();
//++p , --p and p++ p--
PhysicalNumber operator++(int);
PhysicalNumber operator--(int);

PhysicalNumber& operator++();
PhysicalNumber& operator--();
//+,-,+=,-=.=
PhysicalNumber& operator+=(const PhysicalNumber& rsize);
PhysicalNumber& operator-=(const PhysicalNumber& rsize);
PhysicalNumber& operator=(const PhysicalNumber& rsize);

const PhysicalNumber operator+(const PhysicalNumber& n) const;
const PhysicalNumber operator-(const PhysicalNumber& n) const;
//modified friend to allow functions is/os to access data.
friend ostream& operator<<(ostream &os, const PhysicalNumber& n);
friend istream& operator>>(istream &is, PhysicalNumber& n);
// < , > <= , >=

 const bool operator==(const PhysicalNumber& n) const;
 const bool operator<(const PhysicalNumber& n) const;
 const bool operator>(const PhysicalNumber& n) const;
 const bool operator<=(const PhysicalNumber& n) const;
 const bool operator>=(const PhysicalNumber& n) const;
 const bool operator!=(const PhysicalNumber& n) const;



};
//for everyone to knew that is a function like this:
ostream& operator<<(ostream &os, const PhysicalNumber& n);
istream& operator>>(istream &is, PhysicalNumber& n);
}
