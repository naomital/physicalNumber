#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel {
class PhysicalNumber {
private:
Unit U;
double x;

//convert

//void casting()
public:
bool someType(const PhysicalNumber& n);
//constractors
PhysicalNumber(double x,Unit U);
// onary
const PhysicalNumber operator+();
const PhysicalNumber operator-();
//++p , --p and p++ p--
PhysicalNumber& operator++(int);
PhysicalNumber& operator--(int);

PhysicalNumber& operator++();
PhysicalNumber& operator--();
//+,-,+=,-=.=
PhysicalNumber& operator+=(const PhysicalNumber& rsize);
PhysicalNumber& operator-=(const PhysicalNumber& rsize);
PhysicalNumber& operator=(const PhysicalNumber& rsize);

const PhysicalNumber operator+(const PhysicalNumber& n);
const PhysicalNumber operator-(const PhysicalNumber& n);
//stream
friend ostream& operator<<(ostream &os, const PhysicalNumber& n);
friend istream& operator>>(istream &is, PhysicalNumber& n);
// < , > <= , >=

 const bool operator==(const PhysicalNumber& n);
 const bool operator<(const PhysicalNumber& n) ;
 const bool operator>(const PhysicalNumber& n) ;
 const bool operator<=(const PhysicalNumber& n) ;
 const bool operator>=(const PhysicalNumber& n) ;
 const bool operator!=(const PhysicalNumber& n) ;



};
ostream& operator<<(ostream &os, const PhysicalNumber& n);
istream& operator>>(istream &is, PhysicalNumber& n);
}
