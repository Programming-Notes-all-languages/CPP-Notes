#include "Passenger.hpp"
int main()
{
// default constructor
Passenger p1;
// 2nd constructor
Passenger p2("John Smith", VEGETARIAN, 293145);
// 2nd constructor
Passenger p3("Pocahontas", REGULAR);
// Copy constructor
Passenger p4(p3);
// Copy constructor
Passenger p5 = p2;
// default constructor
Passenger* pp1 = new Passenger;
// 2nd constructor
Passenger* pp2 = new Passenger("JoeBlow", NO_PREF);
// default constructor
Passenger pa[20];
p5.print();
delete pp1;
delete pp2;
return 0;
}
