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

    PhysicalNumber Gram(30, Unit::G);
    PhysicalNumber Cm(30, Unit::CM);
    PhysicalNumber KM(30, Unit::KM);
    PhysicalNumber MET(200, Unit::M);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

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

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("Should not work")
      .CHECK_THROWS(Gram+Cm)
      .CHECK_THROWS(Cm+Gram)
      .CHECK_THROWS(Gram+=Cm)
      .CHECK_THROWS(Cm+=Gram)
      .CHECK_THROWS(Cm-=Gram)
      .CHECK_THROWS(Gram-=Cm)
      .CHECK_THROWS(Cm-Gram)
      .CHECK_THROWS(Gram-Cm)
      .CHECK_THROWS(Cm < Gram)
      .CHECK_THROWS(Gram > KM)
      .CHECK_THROWS(Gram >= KM)
      .CHECK_THROWS(Cm <= Gram)
      .CHECK_THROWS(KM <= Gram)
      .CHECK_THROWS(a <= b)
      .CHECK_THROWS(b <= c)
      .CHECK_THROWS(b += Gram)
      .CHECK_THROWS(a -= d)
      .CHECK_THROWS(c += MET)
      .CHECK_THROWS(c -= MET)
      .CHECK_THROWS(MET -= c)
      .CHECK_THROWS(MET += c)
      .CHECK_THROWS(Gram < KM)
      .CHECK_OK(istringstream("200[g") >> Gram)
      .CHECK_OK(istringstream("0.2[]") >> a)
      .CHECK_OK(istringstream("200g]") >> Gram)
      .CHECK_OK(istringstream("0.2[kgg]") >> a)
      .CHECK_OK(istringstream("122.2kg") >> a)
      .CHECK_OK(istringstream("1332.2[to n]") >> a)
      .CHECK_OK(istringstream("[ton]1332.2") >> a)


      .setname("Should work")
      .CHECK_OUTPUT(++Gram, "31[g]")
      .CHECK_OUTPUT(--Gram, "30[g]")
      .CHECK_OUTPUT(--Cm, "29[cm]")
      .CHECK_OUTPUT(++Cm, "30[cm]")
      .CHECK_OUTPUT((Gram+=Gram), "60[g]")
      .CHECK_OUTPUT((Cm+=Cm), "60[cm]")
      .CHECK_OUTPUT((-Gram),"-60[g]")
      .CHECK_OUTPUT(+Gram,"60[g]")
      .CHECK_OUTPUT(Gram-Gram,"0[g]")
      .CHECK_OUTPUT((KM+=MET) , "30.2[km]")
      .CHECK_OUTPUT((Cm-=Cm),"0[cm]")
      .CHECK_OUTPUT(Cm,"0[cm]")
      .CHECK_OUTPUT((Cm+=MET),"20000[cm]")
      .CHECK_OUTPUT((MET+=Cm) , "400[m]")
      .CHECK_OUTPUT((++MET) , "401[m]")
      .CHECK_OUTPUT((--MET) , "400[m]")
      .CHECK_OUTPUT((-MET) , "-400[m]")
      .CHECK_OUTPUT((+MET) , "400[m]")
      .CHECK_OUTPUT(Gram++, "60[g]")
      .CHECK_OUTPUT(Gram, "61[g]")
      .CHECK_OUTPUT(Gram--, "61[g]")
      .CHECK_OUTPUT(Gram, "60[g]")



      .CHECK_EQUAL(Cm < KM, true)
      .CHECK_EQUAL(Cm > KM, false)
      .CHECK_EQUAL(Cm != KM, true)
      .CHECK_EQUAL(Cm == KM, false)
      .CHECK_EQUAL(Cm == Cm, true)
      .CHECK_EQUAL(MET > Cm, true)
      .CHECK_EQUAL(MET != Cm, true)
      .CHECK_EQUAL(MET > Cm, true)
      .CHECK_EQUAL(MET >= Cm, true)
      .CHECK_OK(istringstream("200[m]") >> MET)
      .CHECK_OUTPUT(MET, "200[m]")
      .CHECK_EQUAL(MET == Cm, true)
      .CHECK_OK(istringstream("2000[g]") >> Gram)
      .CHECK_OK(istringstream("2[kg]") >> a)
      .CHECK_OUTPUT(a, "2[kg]")
      .CHECK_EQUAL(Gram == a, true)
      .CHECK_EQUAL(Gram != a, false)
      .CHECK_OUTPUT((--Gram) , "1999[g]")
      .CHECK_EQUAL(Gram != a, true)
      .CHECK_EQUAL(Gram == a, false)
      .CHECK_OK(istringstream("200[g]") >> Gram)
      .CHECK_OK(istringstream("0.2[kg]") >> a)
      .CHECK_OUTPUT(Gram , "200[g]")
      .CHECK_OUTPUT(a , "0.2[kg]")
      .CHECK_EQUAL(Gram != a, false)
      .CHECK_EQUAL(Gram == a, true)

      .CHECK_OK(istringstream("30[min]") >> b)
      .CHECK_OK(istringstream("0.5[hour]") >> c)
      .CHECK_OUTPUT(b , "30[min]")
      .CHECK_OUTPUT(c , "0.5[hour]")

      .CHECK_OK(istringstream("1[ton]") >> b)
      .CHECK_OK(istringstream("1000[kg]") >> c)
      .CHECK_OUTPUT(b , "1[ton]")
      .CHECK_OUTPUT(c , "1000[kg]")

      .CHECK_EQUAL(b != c, false)
      .CHECK_EQUAL(b == c, true)

      .CHECK_OK(istringstream("0.5[km]") >> b)
      .CHECK_OK(istringstream("500[m]") >> c)
      .CHECK_OUTPUT(b , "0.5[km]")
      .CHECK_OUTPUT(c , "500[m]")

      .CHECK_EQUAL(b != c, false)
      .CHECK_EQUAL(b == c, true)
      .CHECK_OUTPUT((b+b+c), "1.5[km]")
      .CHECK_OUTPUT((c+b+b), "1500[m]")
      .CHECK_OUTPUT((c+b-b), "500[m]")
      .CHECK_OUTPUT((b-c-c+b), "0[km]")
      .CHECK_EQUAL((b+c > b), true)
      .CHECK_EQUAL((b-c < b), true)
      .CHECK_OUTPUT((b+=c+=b), "1.5[km]")
      .CHECK_OUTPUT(b, "1.5[km]")
      .CHECK_OUTPUT(c, "1000[m]")


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }

    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
