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
