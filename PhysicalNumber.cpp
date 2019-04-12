#include "PhysicalNumber.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
using namespace ariel;
/**array for  the name of the typ for input-name
 *array for the criteria for all weight,distance and time that help as to
 *convert from one to enader. 
 * example: 2 km + 300 m 300*100 = 30000/100000 = 2.3
300m + 2km =2*100000 =200000/100 = 2300**/

const double value[9]={1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000};
const string name[9]={"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
//constractor x1-number, U-unit.
PhysicalNumber::PhysicalNumber( double x1,Unit U1){
        x=x1;
        U=U1;
}
// private function that check if a string is a number
bool is_number(const std::string& s)
{
        std::string::const_iterator it = s.begin();
        while (it != s.end() && (std::isdigit(*it) || *it=='.')) ++it;
        return !s.empty() && it == s.end();
}
//private function that chack if a PhysicalNumber this are in the same caind of type.
bool PhysicalNumber::someType(const PhysicalNumber& n) const {
        if(((int)n.U >= 0 && (int)n.U <=2) && ((int)this->U>=0&&(int)this->U<=2)) {return true;}
        else if (((int)n.U >= 3 && (int)n.U <=5) && ((int)this->U>=3&&(int)this->U<=5)) {return true;}
        else if (((int)n.U >= 6 && (int)n.U <=8) && ((int)this->U>=6&&(int)this->U<=8)) {return true;}
        else{return false;}
}

// + onary
const PhysicalNumber PhysicalNumber::operator+() {
        if(this->x < 0) {
                return PhysicalNumber((-1*x),U);
        }else{
                return PhysicalNumber(x,U);
        }
}
//- onary
const PhysicalNumber PhysicalNumber::operator-() {
        return PhysicalNumber((-1*x),U);
}
// p++ do something and then promoting +1
PhysicalNumber PhysicalNumber::operator++(int){
        PhysicalNumber a(this->x,this->U);
        this->x=this->x+1;
        return a;
}
//p-- do something and then subtract 1
PhysicalNumber PhysicalNumber::operator--(int){
        PhysicalNumber a(this->x,this->U);
        this->x=this->x-1;
        return a;
}
//++p  promoting +1 and then do something
PhysicalNumber& PhysicalNumber::operator++(){
        this->x=this->x+1;
        return *this;
}
// --p  subtract 1 and then do something
PhysicalNumber& PhysicalNumber::operator--(){
        this->x=this->x-1;
        return *this;
}
//+,-,+=,-=.=
//takes the data and adds something in to, in addition to checking whether it is the same standards of type 
//and if so converts it if necessary. 
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& n){
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                this->x = this->x+(n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return *this;
        }
}
//takes the data and subtract something in to, in addition to checking whether it is the same standards of type 
//and if so converts it if necessary.
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n) {
        if(someType(n)==false) {__throw_invalid_argument("Not some type");}
        else{
                this->x = this->x-(n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return *this;
        }
}
//assignment of data to a given variable.
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& n){
        this->x=n.x;
        this->U=n.U;
        return *this;
}
//connecting two numbers, checking whether they are indeed the same type and
//, if necessary, converting from the right to the type of the left.
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer = this->x + (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
//subtract two numbers, checking whether they are indeed the same type and
//, if necessary, converting from the right to the type of the left.
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer = this->x - (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return PhysicalNumber(answer,this->U);
        }
}
//stream, output of the PhysicalNumber.
ostream& ariel::operator<<(ostream &os, const PhysicalNumber& n){

        return (os <<n.x<< "[" << name[(int)n.U] << "]");
}
//input of the PhysicalNumber. checks whether the number and type is enterd as entered ("number[type]")
//if is does not, throw a special error message.
istream& ariel::operator>>(istream &is, PhysicalNumber& n){
        ios::pos_type startPosition = is.tellg();
        string num,s,type;
        bool flag=false;
        is>>s;
        num = s.substr(0, s.find("["));
        type=s.substr(s.find("[")+1,s.length() -s.find("[")-2);
        for(size_t i = 0; i < 9; i++) {
                if(name[i] == type) {
                        n.U = (Unit)i;
                        flag=true;
                }
        }
        if(flag==false) {
          n.errorStream(is,startPosition);
    return is;
        }
        flag=false;
        if(is_number(num)) {
                flag=true;
                n.x=stod(num);
        }

        if(s.find("[")==string::npos||s.find("]")==string::npos) {
          n.errorStream(is,startPosition);
      return is;
        }
        if(flag==false) {
          n.errorStream(is,startPosition);
return is;
        }
        return is;
}

//bool == < > <= >=
//check if PhysicalNumber this equal to PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator==(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                return x==answer;
        }

}
//check if PhysicalNumber this smaller than PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator<(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                if(x < answer) {
                        return true;
                }
                return false;
        }

}
//check if PhysicalNumber this bigger than PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator>(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                if(x>answer) {
                        return true;
                }
                return false;
        }
}
//check if PhysicalNumber this smaller or equal than PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator<=(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                if(x<=answer) {
                        return true;
                }
                return false;
        }
}
//check if PhysicalNumber this bigger or equal than PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator>=(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer =  (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                if(x>=answer) {
                        return true;
                }
                return false;
        }
}
//check if PhysicalNumber this not equal PhysicalNumber n, on condition that they are in the same type.
const bool PhysicalNumber::operator!=(const PhysicalNumber& n) const {
        if(someType(n)==false) {  __throw_invalid_argument("Not some type");}
        else{
                double answer = (n.x * (double(value[(int)n.U]) / value[(int)this->U]));
                if(x!=answer) {
                        return true;
                }
                return false;
        }
}
//los special error message.
void PhysicalNumber::errorStream(istream &is,ios::pos_type startPosition) {
   auto errorState = is.rdstate();
   is.clear(); // clear error so seekg will work
   is.seekg(startPosition); // rewind
   is.clear(errorState); // set back the error flag
}
