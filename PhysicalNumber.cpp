#include "PhysicalNumber.h"
#include <iostream>

using namespace std;
using namespace ariel;
//2 km + 300 m 300*100 = 30000/100000
const long value[9]={1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000};
const string name[9]={"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
PhysicalNumber::PhysicalNumber(double x1,Unit U1){
        x=x1;
        U=U1;
}
bool PhysicalNumber::someType(const PhysicalNumber& n){
        if(((int)n.U >= 0 && (int)n.U <=2) && ((int)this->U>=0&&(int)this->U<=2)) {return true;}
        else if (((int)n.U >= 3 && (int)n.U <=5) && ((int)this->U>=3&&(int)this->U<=5)) {return true;}
        else if (((int)n.U >= 6 && (int)n.U <=8) && ((int)this->U>=6&&(int)this->U<=8)) {return true;}
        else{return false;}
}
const PhysicalNumber PhysicalNumber::operator+() {
        this->x=+this->x;
        return PhysicalNumber(x,U);
}
const PhysicalNumber PhysicalNumber::operator-() {
      this->x=-this->x;
        return PhysicalNumber(x,U);
}
// p++ p--
PhysicalNumber& PhysicalNumber::operator++(int){
        this->x=this->x+1;
        return *this;
}
PhysicalNumber& PhysicalNumber::operator--(int){
        this->x=this->x-1;
        return *this;
}
//++p , --p
PhysicalNumber& PhysicalNumber::operator++(){
        this->x=this->x+1;
        return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
        this->x=this->x-1;
        return *this;
}
//+,-,+=,-=.=
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& n){
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                this->x = this->x+(n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return *this;
        }
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n){
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                this->x = this->x-(n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return *this;
        }
}
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& n){
        this->x=n.x;
        this->U=n.U;
        return *this;
}

const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer = this->x + (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer = this->x - (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
//stream
ostream& ariel::operator<<(ostream &os, const PhysicalNumber& n){

        return (os <<n.x<< "[" << name[(int)n.U] << "]"<<endl);
}
istream& ariel::operator>>(istream &is, PhysicalNumber& n){
        return is;
}
//bool == < > <= >=
const bool PhysicalNumber::operator==(const PhysicalNumber& n){
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x==answer;
        }

}
const bool PhysicalNumber::operator<(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x<answer;
        }

}
const bool PhysicalNumber::operator>(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x>answer;
        }
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x<=answer;
        }
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x>=answer;
        }
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& n) {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                long double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x!=answer;
        }
}
