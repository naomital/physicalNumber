/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

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
    //time 
    .CHECK_OUTPUT((h+=d), "300.5[hour]")
    .CHECK_OUTPUT((d+d), "60[min]")
    .CHECK_OUTPUT((c-c), "0[hour]")
    .CHECK_OUTPUT((d-d), "0[min]")
    .CHECK_OUTPUT((s-s), "0[sec]")
    //if when in calculation 2 defren type the result becomes the little one. 
    .CHECK_OUTPUT((min+c), "122[min]")
    .CHECK_OUTPUT((c-d), "90[min]")
    







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
