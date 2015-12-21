
#include <conio.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
using namespace std;

enum Scale
{
    Celsius,
    Kelvin,
    Far,
  //  realize,
};
struct Temperature
{
  Temperature(double value, Scale scale);
   Temperature();
  double value;
  char scale;
};

Temperature convert(Temperature tepm, Scale to);


istream& operator>>(istream& input, Temperature& temp);
ostream& operator<<(ostream& output, const Temperature& temp);
istream& operator>>(istream& input, Scale& scale);
ostream& operator<<(ostream& output, const Scale& scale);
