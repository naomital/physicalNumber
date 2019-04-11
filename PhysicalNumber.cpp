#include "PhysicalNumber.h"
#include <iostream>

using namespace std;
using namespace ariel;
//2 km + 300 m 300*100 = 30000/100000 = 2.3
//300m + 2km =2*100000 =200000/100 = 2300
const double value[9]={1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000};
const string name[9]={"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
PhysicalNumber::PhysicalNumber(double x1,Unit U1){
        x=x1;
        U=U1;
}
bool PhysicalNumber::someType(const PhysicalNumber& n) const{
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
PhysicalNumber PhysicalNumber::operator++(int){
  PhysicalNumber a(this->x,this->U);
        this->x=this->x+1;
        return a;
}
PhysicalNumber PhysicalNumber::operator--(int){
  PhysicalNumber a(this->x,this->U);
        this->x=this->x-1;
        return a;
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
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n) {
        if(someType(n)==false) {__throw_invalid_argument("Not some type");}
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

const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer = this->x + (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer = this->x - (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
//stream
ostream& ariel::operator<<(ostream &os, const PhysicalNumber& n){

        return (os <<n.x<< "[" << name[(int)n.U] << "]");
}
bool is_number(const std::string& s)
{
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
}
istream& ariel::operator>>(istream &is, PhysicalNumber& n){

        string num,s,type;
        bool flag=false;
        is>>s;
        num = s.substr(0, s.find("["));
        if(is_number(num)) {
                flag=true;
                n.x=stod(num);
        }



        type=s.substr(s.find("[")+1,s.length() -s.find("[")-2);
        for(size_t i = 0; i < 9; i++) {
                if(name[i] == type) {
                        n.U = (Unit)i;
                        flag=true;
                }
        }

        if(flag==false) {
               __throw_invalid_argument("syntaxt not good");

        }
        return is;
}
//bool == < > <= >=
const bool PhysicalNumber::operator==(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x==answer;
        }

}
const bool PhysicalNumber::operator<(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x < answer;
        }

}
const bool PhysicalNumber::operator>(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x>answer;
        }
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x<=answer;
        }
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x>=answer;
        }
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& n) const{
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                 double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x!=answer;
        }
}
