
    
/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <string>
#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber km(2, Unit::KM);
    PhysicalNumber m(300, Unit::M);
    PhysicalNumber cm(2, Unit::CM);

    PhysicalNumber s(2, Unit::SEC);
    PhysicalNumber h(300, Unit::HOUR);
    PhysicalNumber min(2, Unit::MIN);

    PhysicalNumber g(100, Unit::G);
    PhysicalNumber kg(100, Unit::KG);
    PhysicalNumber t(100, Unit::TON);
int random[5] = {rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};
PhysicalNumber kg0(random[0], Unit::KG);
        PhysicalNumber kg1(random[1], Unit::KG);
        PhysicalNumber kg2(random[2], Unit::KG);
        PhysicalNumber kg3(random[3], Unit::KG);
        PhysicalNumber kg4(random[4], Unit::KG);
PhysicalNumber ton0(random[0], Unit::TON);
        PhysicalNumber ton1(random[1], Unit::TON);
        PhysicalNumber ton2(random[2], Unit::TON);
        PhysicalNumber ton3(random[3], Unit::TON);
        PhysicalNumber ton4(random[4], Unit::TON);
        PhysicalNumber secon(5, Unit::SEC);
        PhysicalNumber hour(3, Unit::HOUR);
        PhysicalNumber minits(60, Unit::MIN);
        PhysicalNumber secon0(random[0], Unit::SEC);
         PhysicalNumber secon1(random[1], Unit::SEC);
        PhysicalNumber secon2(random[2], Unit::SEC);
        PhysicalNumber secon3(random[3], Unit::SEC);
        PhysicalNumber secon4(random[4], Unit::SEC);
         PhysicalNumber min0(random[0], Unit::MIN);
        PhysicalNumber min1(random[1], Unit::MIN);
        PhysicalNumber min2(random[2], Unit::MIN);
        PhysicalNumber min3(random[3], Unit::MIN);
        PhysicalNumber min4(random[4], Unit::MIN);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(km, "2[km]")
    .CHECK_OUTPUT(m, "300[m]")
    .CHECK_OUTPUT(cm, "2[cm]")
    .CHECK_OUTPUT(s, "2[sec]")
    .CHECK_OUTPUT(h, "300[hour]")
    .CHECK_OUTPUT(min, "2[min]")
    .CHECK_OUTPUT(g, "100[g]")
    .CHECK_OUTPUT(kg, "100[kg]")
    .CHECK_OUTPUT(t, "100[ton]")


    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)
    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    //case 1 whigh
    .CHECK_OUTPUT(g+kg, "100100[g]")
    .CHECK_OUTPUT((kg+=t), "100100[kg]")
    .CHECK_THROWS(t-=kg)
    .CHECK_OUTPUT(kg+kg, "200200[kg]")
    .CHECK_OUTPUT(kg-kg, "0[kg]")
    .CHECK_OUTPUT((t+=g), "100.0001[ton]")

         .CHECK_OUTPUT(kg0-kg1, std::to_string(random[0] - random[1]) +"[kg]")
         .CHECK_OUTPUT(kg1-kg2, std::to_string(random[1] -random[2]) +"[kg]")
         .CHECK_OUTPUT(kg2-kg3, std::to_string(random[2] - random[3]) +"[kg]")
         .CHECK_OUTPUT(kg3-kg4, std::to_string(random[3] - random[4]) +"[kg]")
         .CHECK_OUTPUT(kg0-kg2, std::to_string(random[0] - random[2]) +"[kg]")
         .CHECK_OUTPUT(kg0-kg3, std::to_string(random[0] - random[3]) +"[kg]")
         .CHECK_OUTPUT(kg0-kg4, std::to_string(random[0] - random[4]) +"[kg]")
        .CHECK_OUTPUT(kg1-kg3, std::to_string(random[1] - random[3]) +"[kg]")
         .CHECK_OUTPUT(kg0+kg1, std::to_string(random[0] + random[1]) +"[kg]")
         .CHECK_OUTPUT(kg1+kg2,std::to_string (random[1] +random[2]) +"[kg]")
         .CHECK_OUTPUT(kg2+kg3, std::to_string(random[2] + random[3]) +"[kg]")
         .CHECK_OUTPUT(kg3+kg4, std::to_string(random[3] + random[4]) +"[kg]")
         .CHECK_OUTPUT(kg0+kg2, std::to_string(random[0] + random[2]) +"[kg]")
         .CHECK_OUTPUT(kg0+kg3, std::to_string(random[0] + random[3]) +"[kg]")
         .CHECK_OUTPUT(kg0+kg4, std::to_string(random[0] + random[4]) +"[kg]")
        .CHECK_OUTPUT(kg1+kg3, std::to_string(random[1] + random[3]) +"[kg]")

         .CHECK_OUTPUT(ton0-ton1, std::to_string(random[0] - random[1]) +"[ton]")
         .CHECK_OUTPUT(ton1-ton2, std::to_string(random[1] -random[2]) +"[ton]")
         .CHECK_OUTPUT(ton2-ton3, std::to_string(random[2] - random[3]) +"[ton]")
         .CHECK_OUTPUT(ton3-ton4,std::to_string (random[3] - random[4]) +"[ton]")
         .CHECK_OUTPUT(ton0-ton2, std::to_string(random[0] - random[2]) +"[ton]")
         .CHECK_OUTPUT(ton0-ton3, std::to_string(random[0] - random[3]) +"[ton]")
         .CHECK_OUTPUT(ton0-ton4,std::to_string (random[0] - random[4]) +"[ton]")
        .CHECK_OUTPUT(ton1-ton3, std::to_string(random[1] - random[3]) +"[ton]")
         .CHECK_OUTPUT(ton0+ton1, std::to_string(random[0] + random[1]) +"[ton]")
         .CHECK_OUTPUT(ton1+ton2, std::to_string(random[1] +random[2]) +"[ton]")
         .CHECK_OUTPUT(ton2+ton3, std::to_string(random[2] + random[3]) +"[ton]")
         .CHECK_OUTPUT(ton3+ton4, std::to_string(random[3] + random[4]) +"[ton]")
         .CHECK_OUTPUT(ton0+ton2, std::to_string(random[0] + random[2]) +"[ton]")
         .CHECK_OUTPUT(ton0+ton3, std::to_string(random[0] + random[3]) +"[ton]")
         .CHECK_OUTPUT(ton0+ton4, std::to_string(random[0] + random[4]) +"[ton]")
        .CHECK_OUTPUT(ton1+ton3, std::to_string(random[1] + random[3]) +"[ton]")
    //time
    .CHECK_OUTPUT((h+=d), "300.5[hour]")
    .CHECK_OUTPUT(h, "300.5[hour]")
    .CHECK_OUTPUT((d+d), "60[min]")
    .CHECK_OUTPUT((c-c), "0[hour]")
    .CHECK_OUTPUT((d-d), "0[min]")
    .CHECK_OUTPUT((s-s), "0[sec]")
    .CHECK_OUTPUT((min+c), "122[min]")
    .CHECK_OUTPUT((c-=d), "1.5[hour]")
    .CHECK_OUTPUT(c, "1.5[hour]")
    .CHECK_OUTPUT((s+=min), "122[sec]")
    .CHECK_OUTPUT(s, "122[sec]")
    .CHECK_OUTPUT((min-d), "-28[min]")
    .CHECK_OUTPUT((d+=min), "32[min]")
    .CHECK_OUTPUT((d+=c), "122[min]")
    .CHECK_OUTPUT((d+=h), "18152[min]")
    .CHECK_OUTPUT((d+=s), "18154.033333333[min]")
     .CHECK_OUTPUT(secon, "5[sec]")
     .CHECK_OUTPUT(hour, "3[hour]")
     .CHECK_OUTPUT(minits, "60[min]")
     .CHECK_OUTPUT(minits - hour, "-120[min]")
    .CHECK_OUTPUT(secon - minits, "-3595[sec]")



         .CHECK_OUTPUT(secon0-secon1, std::to_string(random[0] - random[1]) +"[sec]")
         .CHECK_OUTPUT(secon1-secon2, std::to_string(random[1] -random[2]) +"[sec]")
         .CHECK_OUTPUT(secon2-secon3, std::to_string(random[2] - random[3]) +"[sec]")
         .CHECK_OUTPUT(secon3-secon4, std::to_string(random[3] - random[4]) +"[sec]")
         .CHECK_OUTPUT(secon0-secon2, std::to_string(random[0] - random[2]) +"[sec]")
         .CHECK_OUTPUT(secon0-secon3, std::to_string(random[0] - random[3]) +"[sec]")
         .CHECK_OUTPUT(secon0-secon4, std::to_string(random[0] - random[4]) +"[sec]")
        .CHECK_OUTPUT(secon1-secon3, std::to_string(random[1] - random[3]) +"[sec]")
         .CHECK_OUTPUT(secon0+secon1, std::to_string(random[0] + random[1]) +"[sec]")
         .CHECK_OUTPUT(secon1+secon2, std::to_string(random[1] +random[2]) +"[sec]")
         .CHECK_OUTPUT(secon2+secon3, std::to_string(random[2] + random[3]) +"[sec]")
         .CHECK_OUTPUT(secon3+secon4, std::to_string(random[3] + random[4]) +"[sec]")
         .CHECK_OUTPUT(secon0+secon2, std::to_string(random[0] + random[2]) +"[sec]")
         .CHECK_OUTPUT(secon0+secon3, std::to_string(random[0] + random[3]) +"[sec]")
         .CHECK_OUTPUT(secon0+secon4, std::to_string(random[0] + random[4]) +"[sec]")
        .CHECK_OUTPUT(secon1+secon3, std::to_string(random[1] + random[3]) +"[sec]")

         .CHECK_OUTPUT(min0-min1, std::to_string(random[0] - random[1]) +"[min]")
         .CHECK_OUTPUT(min1-min2, std::to_string(random[1] -random[2]) +"[min]")
         .CHECK_OUTPUT(min2-min3, std::to_string(random[2] - random[3]) +"[min]")
         .CHECK_OUTPUT(min3-min4, std::to_string(random[3] - random[4]) +"[min]")
         .CHECK_OUTPUT(min0-min2, std::to_string(random[0] - random[2]) +"[min]")
         .CHECK_OUTPUT(min0-min3, std::to_string(random[0] - random[3]) +"[min]")
         .CHECK_OUTPUT(min0-min4, std::to_string(random[0] - random[4]) +"[min]")
        .CHECK_OUTPUT(min1-min3, std::to_string(random[1] - random[3]) +"[smin]")
         .CHECK_OUTPUT(min0+min1, std::to_string(random[0] + random[1]) +"[min]")
         .CHECK_OUTPUT(min1+min2, std::to_string(random[1] +random[2]) +"[min]")
         .CHECK_OUTPUT(min2+min3, std::to_string(random[2] + random[3]) +"[min]")
         .CHECK_OUTPUT(min3+min4, std::to_string(random[3] + random[4]) +"[min]")
         .CHECK_OUTPUT(min0+min2, std::to_string(random[0] + random[2]) +"[min]")
         .CHECK_OUTPUT(min0+min3, std::to_string(random[0] + random[3]) +"[min]")
         .CHECK_OUTPUT(min0+min4, std::to_string(random[0] + random[4]) +"[min]")
        .CHECK_OUTPUT(min1+min3, std::to_string(random[1] + random[3]) +"[min]")
        .CHECK_OUTPUT(secon1+min1, std::to_string(random[1] + (random[1]*60)) +"[sec]")
        .CHECK_OUTPUT(secon0+min1, std::to_string(random[0] + (random[1]*60)) +"[sec]")
        .CHECK_OUTPUT(secon2+min1, std::to_string(random[2] + (random[1]*60)) +"[sec]")
        .CHECK_OUTPUT(secon3+min1, std::to_string(random[3] + (random[1]*60)) +"[sec]")
        .CHECK_OUTPUT(secon1+min2, std::to_string(random[1] + (random[2]*60)) +"[sec]")
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
