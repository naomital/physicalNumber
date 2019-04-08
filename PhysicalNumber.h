#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel {
class PhysicalNumber {
private:
Unit U;
double x;

//convert
void someType(PhysicalNumber& n);
void casting()
public:
//constractors
PhysicalNumber(double x,Unit U);
// onary
const PhysicalNumber operator+() const;
const PhysicalNumber operator-() const;
//++ and --
PhysicalNumber& operator++();
PhysicalNumber& operator--();
//+,-,+=,-=.=
PhysicalNumber& operator+=(const PhysicalNumber& rsize);
PhysicalNumber& operator-=(const PhysicalNumber& rsize);
PhysicalNumber& operator=(const PhysicalNumber& rsize);

const PhysicalNumber operator+(const PhysicalNumber& n) const;
const PhysicalNumber operator-(const PhysicalNumber& n) const;
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
