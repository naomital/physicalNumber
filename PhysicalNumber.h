#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel {
class PhysicalNumber {
private:
int U;
double x;
public:
//constractors
PhysicalNumber(double x,int U);
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

friend const bool operator==(const PhysicalNumber n1, const PhysicalNumber n2) {
        return n1.x == n2.x;};
friend const bool operator<(const PhysicalNumber n1, const PhysicalNumber n2) {
        return n1.x < n2.x;};
friend const bool operator>(const PhysicalNumber n1, const PhysicalNumber n2) {
        return n1.x > n2.x;};
friend const bool operator<=(const PhysicalNumber n1, const PhysicalNumber n2) {
        return n1.x <= n2.x;};
friend const bool operator>=(const PhysicalNumber n1, const PhysicalNumber n2) {
        return n1.x >= n2.x;};
friend const bool operator!=(const PhysicalNumber n1, const PhysicalNumber n2) {
        return !(n1.x==n2.x);};
};
}
