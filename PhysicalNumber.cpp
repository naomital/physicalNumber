#include "PhysicalNumber.h"
#include <iostream>

using namespace std;
using namespace ariel;

  PhysicalNumber::PhysicalNumber(double x1,int U1){
    x=x1;
    U=U1;
  }
  const PhysicalNumber PhysicalNumber::operator+() const{
    return PhysicalNumber(0,0);
  }
  const PhysicalNumber PhysicalNumber::operator-() const{
      return PhysicalNumber(0,0);
  }
  //++ and --
  PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
  }
  PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
  }
  //+,-,+=,-=.=
  PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& rsize){
    return *this;
  }
  PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& rsize){
    return *this;
  }
  PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& rsize){
    return *this;
  }

  const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n) const{
    return PhysicalNumber(0,0);
  }
  const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n) const{
    return PhysicalNumber(0,0);
  }
  //stream
  ostream& ariel::operator<<(ostream &os, const PhysicalNumber& n){
    return os;
  }
  istream& ariel::operator>>(istream &is, PhysicalNumber& n){
    return is;
  }
void PhysicalNumber::someType(PhysicalNumber& n){
        if(((int)n.U >= 0 && (int)n.U <=2) && ((int)this->U>=0&&(int)this->U<=2)) {}
        else if (((int)n.U >= 3 && (int)n.U <=5) && ((int)this->U>=3&&(int)this->U<=5)) {}
        else if (((int)n.U >= 6 && (int)n.U <=8) && ((int)this->U>=6&&(int)this->U<=8)) {}
        else{__throw_invalid_argument("test");}
}
